<?php

namespace App\Http\Controllers;

use App\Models\Company;
use Illuminate\Http\Request;

class Commanawarden extends Controller
{
    //create index
    public function index(){
        $data['companies'] = Company::orderBy('id', 'asc')->paginate(6);
        /*$data['companies'] = Company::join('cabinets','cabinets.id','=','companies.idswappies')->paginate();*/
        return view('kant.notreal.index', $data);

    }
    //create resource
    public function create() {
        return view('kant.create') ;
    }

    //store resource
    public function store(Request $request) {

       
        $request->validate([
            /*'id' => 'required',*/
            'name' => 'required',
            'surname' => 'required',
            'username' => 'required',
            'password' => 'required',
            'idswappies' => 'required',
            'phone' => 'required'/*,
            'address' => 'required'*/
        ]);

        $company = new Company;
        /*$company->id = $request->id;*/
        $company->name = $request->name;
        $company->surname = $request->surname;
        $company->username = $request->username;
        $company->password = crc32($request->password);
        $company->idswappies = $request->idswappies;
        $company->phone = $request->phone;
        /*$company->address = $request->address;*/
        $company -> save();
        return redirect() -> route('companies.index')->with('success','เพิ่มสำเร็จจ้าาาา');
    }

    public function edit(Company $company){
        return view('kant.edit',compact('company'));
    }



    public function editindex(){
        $data['companies'] = Company::orderBy('id', 'asc')->paginate(6);
        /*$data['companies'] = Company::join('cabinets','cabinets.id','=','companies.idswappies')->paginate();*/
        return view('kant.editindex', $data);

    }
    public function deleteindex(){
        $data['companies'] = Company::orderBy('id', 'asc')->paginate(6);
        /*$data['companies'] = Company::join('cabinets','cabinets.id','=','companies.idswappies')->paginate();*/
        return view('kant.deleteindex', $data);

    }

    public function test(){
        $data['companies'] = Company::orderBy('id', 'asc')->paginate(6);
        /*$data['companies'] = Company::join('cabinets','cabinets.id','=','companies.idswappies')->paginate();*/
        return view('kant.notreal.test');

    }

    public function update(Request $request,$id){
        $request->validate([
            /*'id' => 'required',*/
            'name' => 'required',
            'surname' => 'required',
            'username' => 'required',
            'password' => 'required',
            'idswappies' => 'required',
            'phone' => 'required'/*,
            'address' => 'required'*/
        ]);
        $company = Company::find($id);
        /*$company->id = $request->id;*/
        $company->name = $request->name;
        $company->surname = $request->surname;
        $company->username = $request->username;
        $company->password = crc32($request->password);
        $company->idswappies = $request->idswappies;
        $company->phone = $request->phone;
        /*$company->address = $request->address;*/
        $company->save();
        return redirect()->route('companies.index')->with('success','แก้ไขสำเร็จจ้าาาา');
    }






    /*public function destroy(Company $company){
        view('companies.delete',compact('company'));
    
        
    }*/

    /*public function destroydata(Company $company){
        
        $company -> delete();
        return redirect()->route('companies.index')->with('success','Company has been delete cuccessfully.');
        
    }*/

    public function destroy(Company $company){
        $company -> delete();
        
        
        return redirect()->route('companies.index')->with('success','ปลดสำเร็จจ้าาาา');
    }
    
  

  
}
?>