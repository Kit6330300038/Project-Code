<?php

use App\Http\Controllers\Commanawarden;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\KitController;
use App\Http\Controllers\CompanyCRUDController;
use App\Http\Controllers\CabinetController;
use App\Http\Controllers\CompanyNController;
use App\Http\Controllers\CompanyNEWSController;
use Illuminate\Support\Facades\DB;
use App\Http\Controllers\CompanyBatController;
use Illuminate\Http\Request;


Route::resource('companies',CompanyCRUDController::class);

Route::get('/', function () {
    return view('welcome');
});

Route::get('/editindex',[Commanawarden::class,"editindex"])->name("editindex");
Route::get('/deleteindex',[Commanawarden::class,"deleteindex"])->name("deleteindex");
/*=========================================================================================== */
Route::post('manageCabinet', function () {
    return view('httt.manageCabinet');
})->name('manageCabinet');

Route::get('addBattery', function () {
    return view('httt.addBattery');
})->name('addBattery');

/*Route::post('getcallbackone', function (Request $request){
    $id=$request->id;
    $request->session()->put('id',$id);
    return redirect()->route('detailOfBatteryDeep');
    }
    )->name('getcallbackone');*/

Route::get('returnBat', function () {
    $data = DB::table('battery')->select('*')->join('cabinets', 'cabinets.id', '=', 'battery.cabinet_id')->get();
    $res["swappies"] = $data;
    return view('httt.returnBat',$res);
})->name('returnBat');
/*=========================================================================================== */


// Route::get('list', function () {
//     $data = DB::table('cabinets')->select('*')->get();
//     $res['data']=$data;
//     return view('companies.list',$res);
// })->name('list');

Route::get('detailOfCabinet', function () {
    $data = DB::table('cabinets')->select('*')->get();
    $res['data']=$data;
    return view('mo.companies.detailOfCabinet',$res);
})->name('detailOfCabinet');

Route::post('getcabiinfo', function (Request $request){
$id=$request->id;
$request->session()->put('id',$id);
return redirect()->route('detailOfBattery');
}
)->name('getcabiinfo');

Route::get('detailOfBattery', function (Request $request) {
    $data = DB::table('battery')->select('*')
        ->where('cabinet_id',$request->session()->get('id'))
        ->get();
    $res['data']=$data;
    return view('mo.companies.detailOfBattery',$res);
})->name('detailOfBattery');

Route::post('getbatinfo', function (Request $request){
    $id=$request->id;
    $request->session()->put('id',$id);
    return redirect()->route('detailOfBatteryDeep');
    }
    )->name('getbatinfo');

Route::get('detailOfBatteryDeep', function (Request $request) {
    $data = DB::table('battery')->select('*')
    ->where('id',$request->session()->get('id'))
    ->get();
    $res['data']=$data;
    return view('mo.companies.detailOfBatteryDeep',$res);
})->name('detailOfBatteryDeep');


//Route::view('list','list');
// Route::get('list',[CabinetController::class,'Show']);


/*=========================================================================================== */
Route::get('test', function () {
    $data = DB::table('warden')->select('*')
    ->join('cabinets','warden.idswappies','=','cabinets.id')->get();
    
    $res["data"] =$data;
    return view('companies.test', $res); 
})->name('test');


Route::get('test3', function () {
    $data = DB::table('warden')->select('*')->get();
    $res["data"] =$data;
    return view('companies.test3', $res); 
})->name('test3');

Route::get('test2', function () {
    $data = DB::table('warden')->select('*')->get();
    $res["data"] =$data;
    return view('companies.test2', $res); 
    
})->name('test2');

Route::get('testbar', function () {
    $data = DB::table('warden')->select('*')->get();
    $res["data"] =$data;
    return view('companies.testbar', $res); 
    
})->name('testbar');

Route::get('all_ca', function () {
    $data = DB::table('warden')->select('*')
    ->join('cabinets','warden.id','=','cabinets.id')->get();
    $res["data"] =$data;
    return view('A.all_ca', $res); 
    
})->name('all_ca');

Route::get('bat', function () {
    $data = DB::table('battery')->select('*')->get();
    $res["data"] =$data;
    return view('companies.bat', $res); 
   
})->name('bat');


Route::get('deca', function () {


    return view('companies.deca'); 
    
})->name('deca');

Route::get('error_bat', function () {

    return view('companies.error_bat'); 
    
})->name('error_bat');

Route::get('error_ca', function () {

    return view('companies.error_ca'); 
    
})->name('error_ca');


Route::get('debat', function () {
    $data = DB::table('warden')->select('*')
    ->join('battery','warden.id','=','battery.id')->get();
    $res["data"] =$data;
    return view('companies.debat', $res); 
   
})->name('debat');

Route::get('list_nameg', function () {
    $data = DB::table('warden')->selectRaw('warden.id AS user_id,cabinets.id AS cabinet_id,warden.name,warden.surname,cabinets.location')
            ->join('cabinets','warden.idswappies','=','cabinets.id')->get();

    $res["data"] =$data;
    return view('A.list_nameg', $res); 
   
})->name('list_nameg');

Route::get('listname_search', function () {
    return view('A.listname_search'); 
})->name('testlist');

Route::get('location', function () {
    $data = DB::table('cabinets')->select('*')->get();
    $res["data"] =$data;
    return view('companies.location', $res); 

   
})->name('location');

Route::get('app_page', function () {
    
    return view('companies.app_page'); 
})->name('app_page');

Route::get('em_test', function () {
    return view('A.em_test'); 
})->name('em_test');

Route::get('location', function () {
    $data = DB::table('cabinets')->select('*')->get();
    $res["data"] =$data;
    return view('A.location', $res); 

   
})->name('location');





/*=========================================================================================== */


Route::get('/out_of_date', [KitController::class, 'ood'])->name('ood');
Route::get('/battry/detailed', [KitController::class, 'batdtail'])->name('batail');

Route::get('/conclude/all', [KitController::class, 'conclude_all'])->name('concludeall');
Route::get('/conclude/one', [KitController::class, 'conclude_one'])->name('concludeone');

route::post('/oodrecall', [KitController::class, 'recall'])->name('recall');

route::post('/conclude/gettable', [KitController::class, 'getcontable'])->name('gettable');
route::post('/conclude/getinfo', [KitController::class, 'getconinfo'])->name('getinfo');

Route::post('/loginuser', [KitController::class, 'loginuser'])->name('userlogin');
Route::post('/loginwarden', [KitController::class, 'loginwarden'])->name('wardenlogin');
Route::post('/loginmanager', [KitController::class, 'loginmanager'])->name('managerlogin');
route::post('/logout', [KitController::class, 'logout'])->name('logout');
route::get('/logoutm', [KitController::class, 'logoutm']);

Route::middleware('no_nonsense')->group(function () {
    Route::middleware('no_back')->group(function () {
        /*Route::get('/login', [SwappiesController::class, 'Index'])->name('login');*/
        Route::get('/login', [KitController::class, 'login1'])->name('login');
        Route::get('/loginwd', [KitController::class, 'login2'])->name('loginwd');
        Route::get('/loginmg', [KitController::class, 'login3'])->name('loginmg');
    });
/*-------------------------------------------
All Normal Users Routes List
--------------------------------------------*/
    Route::middleware('is_user')->group(function () {
        Route::get('/userhome', [KitController::class, 'home'])->name('login.user');
    });
  
/*------------------------------------------
All warden Routes List
--------------------------------------------*/
    Route::middleware('is_warden')->group(function () {
        Route::get('/wardenhome', [KitController::class, 'warhome'])->name('login.warden');
    });
  
/*------------------------------------------
All manager Routes List
--------------------------------------------*/
    Route::middleware("is_manager")->group(function () {
        Route::get('/managerhome', [KitController::class, 'comhome'])->name('login.manager');
    });
});

