<?php
// ไฟล์ Controller เป็นไฟล์ที่ใช้เขียนโค้ดในการจัดการ request ต่างๆ เช่นเพิ่ม ลบ แก้ไข ดึงข้อมูล
namespace App\Http\Controllers;

use App\Models\CompanyN;
use Illuminate\Http\Request;

class CompanyNController extends Controller
{
    // Create Index
    public function index(){
        $data['company_n_s'] = CompanyN::orderBy('id','asc')->paginate(5);
        return view('company_n_s.index',$data);
    }

    // Create resource
    public function create(){
        return view('company_n_s.create');
    }

    // Store resource
    public function store(Request $request){
        $request->validate([
            'name' => 'required',
            'news' => 'required',
            'link' => 'required'
        ]);

        $company = new CompanyN;
        $company->name = $request->name;
        $company->news = $request->news;
        $company->link = $request->link;
        $company->save();
        return redirect()->route('company_n_s.index')->with('success','Company has been created successfully.');
    }

    public function edit(CompanyN $company){
        return view('company_n_s.edit',compact('company'));
    }
}
