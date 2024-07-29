<?php

namespace App\Http\Controllers;

use Illuminate\Support\Facades\DB;

use Illuminate\Http\Request;
use App\Models\Cabinet;

class CabinetController extends Controller
{
    //

    public function index(){
        $data = DB::table('cabinets')->select('*')->get();
        $res['data']=$data;
        // $data['companies'] = Cabinet::orderBy('id','asc')->paginate(5);
        return view('companies.list',$res);
    }

    
}
