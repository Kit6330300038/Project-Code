<?php

namespace App\Http\Controllers;

use App\Models\Company;
use Illuminate\Support\Facades\DB;
use Illuminate\Http\Request;
use Illuminate\Support\Arr;
use Illuminate\Support\Facades\Hash;
use Symfony\Component\HttpFoundation\Session\Session;

class KitController extends Controller
{
    //
    public function Index()
    {   
        return view('welcome');
    }

    public function login1(Request $request) // after login page
    {   
        $type=$request->session()->get("type");
        $res["request"]=$type;
        return view('kit.loginuser',$res);
    }

    public function login2(Request $request)
    {   
        $type=$request->session()->get("type");
        $name=$request->session()->get("type");
        $res["request"]=$type;
        return view('kit.loginwarden',$res);
    }

    public function login3(Request $request)
    {   
        $type=$request->session()->get("type");
        $name=$request->session()->get("type");
        $res["request"]=$type;
        return view('kit.loginmanager',$res);
    }

    public function comhome(Request $request)
    {   $type = $request->session()->get("type");
        $name = $request->session()->get("info");
        $res["type"]=$type;
        $res["name"]=$name;
        return view('kit.notreal.managerhome',$res);
    }

    public function warhome(Request $request)
    {   $type = $request->session()->get("type");
        $name = $request->session()->get("info");
        $res["type"]=$type;
        $res["name"]=$name;
        return view('kit.notreal.wardenhome',$res);
    }

    public function home(Request $request)  // before login page
    {   $type = $request->session()->get("type");
        $name = $request->session()->get("info");
        $res["type"]=$type;
        $res["name"]=$name;
        return view('kit.notreal.home',$res);
    }
    
    public function loginuser(Request $request) // after submit login 
    {   $username =  $request->username;
        $password = $request->password;
        if($username != null && $password != null)
        {   $user =substr(DB::table('user')->select('*')->where('password',crc32(string: $password))->where('username',
                            $username)->get(),1,-1);
            if ($user!= '') {
                $request->session()->put('type', 1 );
                $request->session()->put('info', json_decode($user));
                return redirect()->route('login.user');
                //route main user
            }
            return redirect()->route('login')->with('error','wrong username or password');
        }
        return redirect()->route('login')->with('error','no username or password');
    }

    public function loginwarden(Request $request)
    {   $usernamew = $request->username;$passwordw = $request->password;
        if($usernamew!= null && $passwordw != null){
            $user = substr(DB::table('warden')->select('*')->where('password',crc32(string: $passwordw))->where('username',
                            $usernamew)->get(),1,-1);
            if ($user!= '') {
                $request->session()->put('type', 2 );
                $request->session()->put('info', json_decode($user) );
                return redirect()->route('login.warden');
                //route warden user
            }
            return redirect()->route('loginwd')->with('error','wrong username or password');
        }
        return redirect()->route('loginwd')->with('error','no username or password');
    }

    public function loginmanager(Request $request)
    {   $usernamem = $request->username;$passwordm = $request->password;
        if($usernamem!= null && $passwordm != null){
            $user = substr(DB::table('manager')->select('*')->where('password',crc32(string: $passwordm))->where('username',
                            $usernamem)->get(),1,-1);
            if ($user!= '') {
                $request->session()->put('type', 3 );
                $request->session()->put('info', json_decode($user) );
                return redirect()->route('login.manager');
                //route manager user
            }
            return redirect()->route('loginmg')->with('error','wrong username or password');
        }
        return redirect()->route('loginmg')->with('error','no username or password');
    }
    public function logout(Request $request)  
    {   
        $request->session()->flush();
        $request->session()->put('test', 'i here');
        return redirect()->route('login');
    }
    public function logoutm(Request $request){
        $request->session()->flush();
        return redirect()->route('login');
    }

    public function conclude_all()  // 
    {   $ret['years']=DB::table('income')
            ->selectRaw('YEAR(Date_of_payment) year')
            ->groupBy('year')
            ->orderBy('year')
            ->get();
        $ret['dtable']= DB::table('income')
            ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
            ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
            ->whereMonth('income.Date_of_payment',date("m"))//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
            ->whereYear('income.Date_of_payment',date("Y"))
            ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
            ->orderBy('income.Swappies_ID')
            ->get();
        return view('kit.all',$ret);
    }

    public function getcontable(Request $request)
    {   $year = $request->years;
        $month = $request->mounth;
        $area =  $request->swappies;
        $ret['']='';        
        if($year != 0 ){  // year
            if($month != 0){    // year month
                if($area != null){     // year month id
                    $ret['table']= DB::table('income')
                    ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                    ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                    ->whereMonth('income.Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                    ->whereYear('income.Date_of_payment',$year)
                    ->where('income.Swappies_ID',$area)
                    ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                    ->orderBy('income.Swappies_ID')
                    ->get();
                }else{      // year month
                    $ret['table']= DB::table('income')
                            ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                            ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                            ->whereMonth('income.Date_of_payment',$month)
                            ->whereYear('income.Date_of_payment',$year)
                            ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                            ->orderBy('income.Swappies_ID')
                            ->get();
                }
            }else{ // year
                if($area != null){     // year id
                    $ret['table']= DB::table('income')
                        ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                        ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                        ->whereYear('income.Date_of_payment',$year)
                        ->where('income.Swappies_ID',$area)
                        ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                        ->orderBy('income.Swappies_ID')
                        ->get();
                }else{      // year
                    $ret['table']= DB::table('income')
                        ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                        ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                        ->whereYear('income.Date_of_payment',$year)
                        ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                        ->orderBy('income.Swappies_ID')
                        ->get();
                }
            }
        }elseif($month != 0){   // month
            if($area != null){     // month id
                $ret['table']= DB::table('income')
                    ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                    ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                    ->whereMonth('income.Date_of_payment',$month)
                    ->where('income.Swappies_ID',$area)
                    ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                    ->orderBy('income.Swappies_ID')
                    ->get();
            }else{      // month
                $ret['table']= DB::table('income')
                    ->join('cabinets', 'income.Swappies_ID', 'LIKE', 'cabinets.id')
                    ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                    ->whereMonth('income.Date_of_payment',$month)
                    ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                    ->orderBy('income.Swappies_ID')
                    ->get();
            }
        }elseif($area !=null){  // id
            $ret['table']= DB::table('income')
                ->join('cabinets', 'income.Swappies_ID', '=', 'cabinets.id')
                ->selectRaw("income.Swappies_ID  ,income.Type_of_payment, sum(income.Price) AS total, cabinets.address")
                ->where('income.Swappies_ID',$area)
                ->groupBy('income.Type_of_payment','income.Swappies_ID','cabinets.address')
                ->orderBy('income.Swappies_ID')
                ->get();
        }  

        
        return redirect()->route('concludeall')->with($ret);
    }

    public function conclude_one(Request $request)//  batery detail
    {   $ret['years']=DB::table('income')
            ->selectRaw('YEAR(Date_of_payment) year')
            ->groupBy('year')
            ->orderBy('year')
            ->get();
        $ret['dtable']= DB::table('income')
                ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                ->whereMonth('Date_of_payment',date("m"))//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                ->whereYear('Date_of_payment',date("Y"))
                ->where('Swappies_ID',request()->session()->get('where'))
                ->orderBy('Date_of_payment')
                ->get();
        return view('kit.one',$ret);
    }

    public function getconinfo(Request $request) // condition batery 
    {   if($request->id != null)
        {   request()->session()->put("where",$request->id);
        }else{

        }
        
        $uid=$request->uid;
        $top=$request->top;
        $day=$request->day;
        $month=$request->mounth;
        $year=$request->years;
        if($uid != 0|| $uid != null){ // id
            if($top != 0 ){ //id top
                if($year !=0){ //id top year
                    if($month != 0){ //id top year month
                        if($day != 0){ //id top year month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id top year month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ //id top year  day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id top year 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }else{
                    if($month != 0){ //id top month
                        if($day != 0){ //id top  onth day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id top month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ //id top day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id top 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->where('User_ID',$uid)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }
            }else{
                if($year !=0){ //id year
                    if($month != 0){ //id year month
                        if($day != 0){ //i dyear month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id year month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->whereYear('Date_of_payment',$year)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ //id year  day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('id,Date_of_payment')
                            ->get();
                        }else{  //id year 
                            $ret['table']= DB::table('income')
                            ->selectRaw("Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }else{
                    if($month != 0){ //id month
                        if($day != 0){ //id month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id top month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ //id day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereDay('Date_of_payment',$day)
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //id 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->where('User_ID',$uid)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }
            }
        }else{
            if($top != 0){ // top
                if($year !=0){ // top year
                    if($month != 0){ // top year month
                        if($day != 0){ // top year month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // top year month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->whereYear('Date_of_payment',$year)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ // top year  day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // top year 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }else{
                    if($month != 0){ // top month
                        if($day != 0){ // top  onth day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->whereDay('Date_of_payment',$day)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // top month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ // top day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereDay('Date_of_payment',$day)
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // top 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->where('Type_of_payment',$top)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }
            }else{
                if($year !=0){ //year
                    if($month != 0){ // year month
                        if($day != 0){ // year month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // year month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereYear('Date_of_payment',$year)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ // year  day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->whereDay('Date_of_payment',$day)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  // year 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereYear('Date_of_payment',$year)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }else{
                    if($month != 0){ // month
                        if($day != 0){ // month day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)//whereRaw('MONTH(income.Date_of_payment) = ?',[$month])
                            ->whereDay('Date_of_payment',$day)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //  month 
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereMonth('Date_of_payment',$month)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }else{
                        if($day != 0){ // day
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->whereDay('Date_of_payment',$day)
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }else{  //
                            $ret['table']= DB::table('income')
                            ->selectRaw("id,Date_of_payment,User_ID,Type_of_payment ,Price")
                            ->where('Swappies_ID',request()->session()->get('where'))
                            ->orderBy('Date_of_payment')
                            ->get();
                        }
                    }
                }
            }
        }
        return redirect()->route('concludeone')->with($ret);
    }

    public function ood() // out of date page
    {   $ret['out_of_date']=DB::table('battery')
            ->selectRaw("create_date,id,id as bat_id,cabinet_id")
            /*->whereMonth('create_date',">=",date('m'))*/
            ->whereYear('create_date',"<=",date('Y')-5)
            ->where('status','!=',[8,9])
            ->orderBy('create_date')
            ->take(15)->get();
        return view('kit.outofdate',$ret);
    }

    public function recall(Request $request)  // recall out of date
    {   $where = $request->id;
        DB::table('battery')
            ->where('id', $where)
            ->update(['status' => "8"]);
        return redirect()->route('ood')->with('success','mission failed successful !!!');
    }
    public function batdtail(Request $request) 
    {   $batidf = $request->session()->get('id') ;
        $ret['data']=DB::table('reserve_batteries')
                ->join('cabinets', 'reserve_batteries.id_cabinet', '=', 'cabinets.id')
                ->join('user', 'reserve_batteries.id_user', '=', 'user.id')
                ->selectRaw("user.name, user.surname, user.id, cabinets.address , reserve_batteries.out_time")
                ->where('reserve_batteries.id_user',$batidf)
                ->where('reserve_batteries.status',3)
                ->orderBy('reserve_batteries.out_time')
                ->get();
        return view('kit.detailed',$ret);
    }

}
?>