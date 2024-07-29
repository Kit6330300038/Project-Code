<?php

namespace App\Http\Controllers;

use App\Models\Kao;
use Illuminate\Http\Request;

class CompanyNEWSController extends Controller
{
    // Create Index
    public function index(){
        $data['kaos'] = Kao::orderBy('id','asc')->paginate(5);
        return view('kaos.index',$data);
    }

    // Create resource
    public function create(){
        return view('kaos.create');
    }

    // Store resource
    public function store(Request $request){
        $request->validate([
            'name' => 'required',
            'news' => 'required',
            'link' => 'required'
        ]);

        $kao = new Kao;
        $kao->name = $request->name;
        $kao->news = $request->news;
        $kao->link = $request->link;
        $kao->save();
        return redirect()->route('kaos.index')->with('success','News has been created successfully.');
    }

    public function edit(Kao $kao){
        return view('kaos.edit',compact('kao'));
    }

    public function update(Request $request,$id){
        $request->validate([
            'name' => 'required',
            'news' => 'required',
            'link' => 'required'
        ]);
        $kao = Kao::find($id); //หา id ที่มัน match กันเพื่อค้นหา id ข้อมูลที่เราต้องการ update
        $kao->name = $request->name;
        $kao->news = $request->news;
        $kao->link = $request->link;
        $kao->save();
        return redirect()->route('kaos.index')->with('success','News has been updated successfully.');
    }

    public function destroy(Kao $kao){
        $kao->delete();
        return redirect()->route('kaos.index')->with('success','News has been deleted successfully.');
    }
}
