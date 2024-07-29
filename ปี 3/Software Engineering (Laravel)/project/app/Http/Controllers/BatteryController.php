<?php

namespace App\Http\Controllers;

use Illuminate\Support\Facades\DB;

use Illuminate\Http\Request;
use App\Models\Battery;

class BatteryController extends Controller
{
    //

    public function index(){
        $data = DB::table('batteries')->select('*')->get();
        $res['data']=$data;
        // $data['companies'] = Cabinet::orderBy('id','asc')->paginate(5);
        return view('batteries.list',$res);
    }
}
