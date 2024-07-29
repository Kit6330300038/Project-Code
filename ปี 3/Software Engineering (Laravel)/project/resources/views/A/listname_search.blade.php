<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Restore Page</title>
    <link href="assets/css/addBattery.css" rel="stylesheet"  >

    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/redbar.css'); ?>">
    
    <style>
    
    </style>

</head>
<body>
    <div class="header">
        <img src="assets/img/lg.png" alt="Stickman" width="150" height="55" style="padding-top: 15px; padding-left: 20px;">
        <div class="header-right">
         
          <a href="{/{route('debat')}}" style="font-size: 20px;">จัดการแบตเตอรี่</a>
          <a href="{/{route('deca')}}" style="margin-left: 60px; font-size: 20px;">จัดการตู้</a>
          <a href="{/{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;">จัดการบัญชี</a>
          <a class="active" href="{/{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;">จัดการผู้ดูแล</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a" href="{/{route('companies.index')}}" data-text="home">เพิ่มพนักงานผู้ดูแลตู้</a></li>
            <li><a class ="sidebar-a" href="{/{route('companies.index')}}" data-text="archives">เปลี่ยนผู้ดูแลตู้</a></li>
            <li><a class ="sidebar-a" href="{/{route('companies.index')}}" data-text="tags">ปลดผู้ดูแลตู้</a></li>
            <li><a class ="sidebar-a_active" href="{/{route('companies.index')}}" data-text="categories">รายชื่อผู้ดูแลรับผิดชอบตู้</a></li>
        </ul>
    </div>
    
    <div>
       
    </div>
    <div class ="container-center2">
        <div class="lidecoration">


            <form action="{/{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
                @csrf

                <li><strong>รหัสผู้ดูแล : </strong><input name="search"><button type="submit" style="font-size:15px; background-color:#6BB3E0; color:black; border-color:#6BB3E0; height:30px; width:70px; border-radius: 10px; margin:10px;">ค้นหา</button></li>
                
            </form>

        </div>

        
        
        <table>

            @if($data->isNotEmpty())
                <tr>
                    <th>รหัสประจำตัว</th>
                    <th>ชื่อผู้ดูแล</th>
                    <th>หมายเลข ID ของตู้</th>
                    <th>สถานที่</th>
                </tr>
            
            @foreach ($data as $swap)
           
            
                <tr>
                    <td>{{ $swap->user_id }}</td>
                    <td style="width: 100px;">{{ $swap->name }} &nbsp;&nbsp;{{ $swap->surname }}</td>
                    <td>{{ $swap->cabinet_id }}</td>
                    <td>{{ $swap->location }}</td>
                </tr>
               
            @endforeach
            @else 
                <div>
                    <h2>ไม่พบข้อมูล</h2>
                </div>
            @endif
            
            
        </table>
        
    </div>
    
</body>
</html>









