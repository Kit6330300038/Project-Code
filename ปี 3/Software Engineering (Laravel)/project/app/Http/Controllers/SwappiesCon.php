<?php

namespace App\Http\Controllers;

use App\Models\Swappies;
use App\Models\Cabinets;
use App\Models\UserManager;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;

class SwappiesCon extends Controller
{
    //Create Index
    
    public function index()
    {
        $users["swappies"] = Swappies::select('swappies.*','cabinets.address as address')
        ->join('cabinets', 'cabinets.id', '=', 'swappies.id')->get();
        ($users);
        return view('httt.index',$users);
    }

    public function create()
    {
        return view('httt.create');
    }
    
    public function store(Request $request)
    {
        if(isset($_POST['ID_Battery']))
        {
            $request->validate([
                'ID_Battery'=>'required',
                'age'=>'required',
                'ID_Cabinet'=>'required'
            ]);
            $swap = new Swappies;
            $swap->number_of_battery=$request->ID_Battery;
            $swap->age_of_battery=$request->age;
            $swap->number_of_cabinet=$request->ID_Cabinet;
            $swap->save();
            return redirect()->route('addBattery');
        }elseif(isset($_POST['Name'])){
            $request->validate([
                'Name'=>'required',
                'Lastname'=>'required',
                'date'=>'required',
                'email'=>'required',
                'phone_num'=>'required',
                'password'=>'required',
                'address'=>'required'
            ]);
            $user = new UserManager();
            $user->user_id=$user->user_id+1;/////ติดปัญหา
            $user->name=$request->Name;
            $user->surname=$request->Lastname;
            $user->username=$request->email;
            $user->password=crc32($request->password);
            $user->address=$request->address;
            $user->phone=$request->phone_num;
            $user->birth_day=$request->date;
            $user->save();
            return redirect()->route('registerManager');

        }else{
            $request->validate([
                'ID_Cabinet'=>'required',
                'address'=>'required',
                'ID_Res'=>'required'
            ]);
            $cab = new Cabinets();
            $cab->number_of_cabinet=$request->ID_Cabinet;
            $cab->address=$request->address;
            $cab->Response=$request->ID_Res;
            $cab->save();
            return redirect()->route('httt.manageCabinet');
        }
        

    }
    public function maps()
    {
        $locations = [
            ['23', 13.12003701089334, 100.92093896612188],
            ['17', 13.119292480373037, 100.9200333750403],
            ['มก ', 13.12113336545965, 100.91969262364711],
        ];
        return view('httt.map',compact('locations'));
    }
}