<?php

namespace App\Http\Controllers;

use Illuminate\Support\Facades\DB;

use App\Models\Company;

use App\Models\Battery;
use App\Models\Cabinet;
use App\Models\manage;
use Illuminate\Http\Request;

class CompanyCRUDController extends Controller
{

   
   
    public function store(Request $request){
        
        if(isset($_POST['bat_id']))
        {

            

            $where = $request->input('bat_id');

            if( Battery::find($where)== null)
            {
                return redirect()->route('error_bat');
            }

            DB::table('battery')
            ->where('battery.id',$where)->delete();

            
            return redirect()->route('debat');

        }
        elseif(isset($_POST['ca_id']))
        {
            
            $where = $request->input('ca_id');


            DB::table('cabinets')
            ->where('cabinets.id',$where)->delete();

            DB::table('battery')
            ->where('battery.cabinet_id',$where)->delete();

            

            return redirect()->route('deca');

        }
        elseif(isset($_POST['search']))
        {
            $search = $request->input('search');

            $data = DB::table('warden')->selectRaw('warden.id AS user_id,cabinets.id AS cabinet_id,warden.name,cabinets.location,warden.surname')
            ->join('cabinets','warden.idswappies','=','cabinets.id')
            ->where('warden.id', 'LIKE', "%{$search}%")->get();

     
            return view('A.listname_search', compact('data'));

        }
        elseif(isset($_POST['login']))
        {
            $login = $request->input('login');
            
            $data = DB::table('warden')
            ->selectRaw('warden.id AS user_id,cabinets.id AS cabinet_id,warden.name,warden.phone')
            ->join('cabinets','warden.idswappies','=','cabinets.id')
            ->where('warden.id', 'LIKE', "%{$login}%")->get();
            
     
            return view('A.test', compact('data'));

        }

        

        elseif(isset($_POST['ca_select']))
        {
            $ca_select = $request->input('ca_select');

            $data = DB::table('warden')->selectRaw('warden.id AS user_id,cabinets.id AS cabinet_id,warden.name,warden.phone,cabinets.location')
            ->join('cabinets','warden.idswappies','=','cabinets.id')
            ->where('cabinets.id', 'LIKE', "%{$ca_select}%")->get();

     
            return view('A.all_ca', compact('data'));

        }

        elseif(isset($_POST['user_select']))
        {
            $user_select = $request->input('user_select');
            
            $data = DB::table('warden')->selectRaw('warden.id AS user_id,cabinets.id AS cabinet_id,warden.name,warden.phone')
            ->join('cabinets','warden.idswappies','=','cabinets.id')
            ->where('warden.id', 'LIKE', "%{$user_select}%")->get();
          
            return view('companies.test2', compact('data'));

        }

        elseif(isset($_POST['bat_select']))
        {
            $bat_select = $request->input('bat_select');

            $data = DB::table('battery')->selectRaw('battery.id AS bat_id,cabinets.id AS cabinet_id,cabinets.location,battery.status')
            ->join('cabinets','battery.cabinet_id','=','cabinets.id')
            ->where('battery.cabinet_id', 'LIKE', "%{$bat_select}%")->get();
            

     
            return view('companies.bat', compact('data'));

        }

        elseif(isset($_POST['bat_data']))
        {
            $bat_data = $request->input('bat_data');
     
            return view('companies.em_test');

        }

        elseif(isset($_POST['search_lo']))
        {
            $search_lo = $request->input('search_lo');
    
          
            $data = DB::table('cabinets')->select('*')
           
            ->where('cabinets.location', 'LIKE', "%{$search_lo}%")->get();
          
            return view('companies.location_search', compact('data'));

        }

        elseif(isset($_POST['select_lo']))
        {
            $select_lo = $request->input('select_lo');
    
            $data = DB::table('cabinets')->select('*')
             
            ->where('cabinets.location', 'LIKE', "%{$select_lo}%")->get();
          
            return view('companies.location_search', compact('data'));

        }
        
    }

    
    

}
