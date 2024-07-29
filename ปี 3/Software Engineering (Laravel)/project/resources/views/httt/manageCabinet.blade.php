<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Cabinet Manager</title>
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
</head>
<body>
    <div class="header">       
         <a href="#" class="img">
            <img src="assets/images/lg.png" alt="swapppp" width="100" height="50">
        </a>
        <div class="header-right">
          <a href="{/{route('addBattery')}}" style="margin-left: 60px; font-size: 20px;">จัดการแบตเตอรี่</a>
          <a class="active" href="{/{route('mt')}}" style=" font-size: 20px;" >จัดการตู้</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบัญชี</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a" href="{{route('detailOfCabinet')}}" data-text="home">รายละเอียดของตู้</a></li>
            <li><a class ="sidebar-a_active" href="{{route('manageCabinet')}}" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('deca')}}" data-text="tags">ลดตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('concludeall')}}" data-text="categories">สรุปรายรับ</a></li>
        </ul>
    </div>
    
    <div>

        
        
    </div>
            <form action="{{route('manageCabinet')}}" method="POST" enctype="multipart/form-data"><!--'httt.store'-->
                @csrf
                <div class="container-center">
                    <div class="lidecoration">
                        <li><strong>ชื่อ (ID) ของตู้สลับแบตเตอรี่</strong></li>
                        <li><input type="ID_Cabinet" name="ID_Cabinet"></li>
                        <li><strong>สถานที่</strong></li>
                        <li><input type="address" name="address"></li>
                        <li><strong>ผู้รับผิดชอบตู้สลับแบตเตอรี่</strong></li>
                        <li><input type="ID_Res" name="ID_Res"></li>
                        <button type="submit" class="container-right">ยืนยัน</button>
                    </div>
                </div>
            </form>
</body>
</html>