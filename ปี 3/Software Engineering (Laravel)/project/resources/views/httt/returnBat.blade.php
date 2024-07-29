<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Restore Page</title>
    <link href="assets/css/main.css" rel="stylesheet"  >
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
</head>
<body>
    <div class="header">
        <div class="header-right">
          <a class="active" href="#" style="font-size: 20px;">จัดการแบตเตอรี่</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการตู้</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบัญชี</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a" href="{{route('addBattery')}}" data-text="home">เพิ่มแบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="archives">ลดแบตเตอรี่</a></li>
            <li><a class ="sidebar-a_active" href="{/{route('swappies.index')}}" data-text="tags">สถานะเรียกเคืนแบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="categories">รายชื่อแบตเตอรี่ที่ใกล้หมดอายุ</a></li>
        </ul>
    </div>
    
    <div>
        <a href="{/{route('manageContain')}}" class="img">
            <img src="assets/img/0BAA63CC-A5DD-486D-8D97-83FF25553E49.png" alt="swapppp" width="100" height="50">
        </a>
        
        
    </div>
    <div class ="container-center">
        @foreach ($swappies as $swap)
            @if($swap->status==8) 
                    <h3>รายละเอียดการเรียกคืนแบตเตอรี่ : ลูกที่ {{ $swap->id}}</h3>
                    <h3>หมายเลข ID ของแบตเตอรี่ : {{ $swap->bat_id }}</h3>
                    <h3>อายุของแบตเตอรี่ : {{ $swap->create_date }} ปี</h3>
                    <h3>สถานที่ : {{ $swap->name_add }}</h3>
            @endif
            
        @endforeach
        @if($swap->status!=8)
            <h2>ไม่มีแบตที่ต้องเรียกคืน</h2>
        @endif
        <a href = "#"class="container-center1">ย้อนกลับ</a>
        <a href = "#"class="container-right">ยืนยัน</a>
    </div>
    
</body>
</html>