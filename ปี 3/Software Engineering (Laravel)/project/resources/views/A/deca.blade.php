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
         
          <a href="{{route('debat')}}" style="font-size: 20px;">จัดการแบตเตอรี่</a>
          <a class="active"  style="margin-left: 60px; font-size: 20px;">จัดการตู้</a>
          <a href="{{route('test')}}" style="margin-left: 60px; font-size: 20px;">จัดการบัญชี</a>
          <a href="{{route('list_nameg')}}" style="margin-left: 60px; font-size: 20px;">จัดการผู้ดูแล</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="home">รายละเอียดของตู้</a></li>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a_active" href="{{route('companies.index')}}" data-text="tags">ลดตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="categories">สรุปรายรับ</a></li>
        </ul>
    </div>
    
    <div>
       
    </div>
    <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
        @csrf
        
        <div class ="container-center">
            <div class="lidecoration">
                <li><strong>ID ของตู้สลับแบตเตอรี่</strong></li>
                <li><input type="number" name="ca_id"></li>
                
            </div>
        
            
            
            <div class="col-md-12">
               
                    <button type="submit" class="mt-3 btn btn-primary">Submit</button>

            </div>

          

        </div>
    </form>
    
</body>
</html>
