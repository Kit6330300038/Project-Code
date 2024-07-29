<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Restore Page</title>
    <link href="assets/css/addBattery.css" rel="stylesheet"  >
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
</head>
<body>
    <div class="header">
        <div class="header-right">
          <a class="active" href="{/{route('addBattery')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;" >จัดการตู้</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบัญชี</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a_active" href="{{route('addBattery')}}" data-text="home">เพิ่มแบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="#" data-text="archives">ลดแบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="#" data-text="tags">สถานะเรียกเคืนแบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('ood')}}" data-text="categories">รายชื่อแบตเตอรี่ที่ใกล้หมดอายุ</a></li>
        </ul>
    </div>
    
    <div>
        <a href="#" class="img">
            <img src="assets/images/lg.png" alt="swapppp" width="100" height="50">
        </a>
        
    </div>
    <div aciclass ="container-center">
        <div >
            <form action="{/{route('httt.store')}}" method="POST" enctype="multipart/form-data">
                @csrf
                <div class="container-center">
                    <div class="lidecoration">
                        <li><strong>ID ของแบตเตอรี่</strong></li>
                        <li><input type="ID_Battery" name="ID_Battery" class="input"></li>
                        <li><strong>อายุของแบตเตอรี่</strong></li>
                        <li><input type="age" name="age" class="input"></li>
                        <li><strong>ID ของตู้แบตเตอรี่</strong></li>
                        <li><input type="ID_Cabinet" name="ID_Cabinet" class="input"></li>
                        <button class="container-right">ยืนยัน</button>
                    </div>
                </div>
            </form>
            
        </div>
    </div>
    
</body>
</html>