<!DOCTYPE html>
<html lang="en">
<head>
    <title> ประวัติแบต </title>
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
</head>
<style>
    table,th, td {
        border: 2px solid black;
        border-collapse: collapse;
            
    }
</style>
<body>
    <div class="header">
        <div class="header-right">
          <a href="{/{route('addBattery')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a class="active" href="{/{route('detailOfCabinet')}}" style="font-size: 20px; ">จัดการตู้</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a_active" href="{/{route('detailOfCabinet')}}" data-text="home">รายละเอียดของตู้</a></li>
            <li><a class ="sidebar-a" href="{/{route('manageCabinet')}}" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="tags">ลดตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="categories">สรุปรายรับ</a></li>
        </ul>
    </div>
    
    <div>
        <a href="{/{route('manageContain')}}" class="img">
            <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
        </a>
        
        
    </div>
    <div class="container-center" style="width: 1000px;height: 500px">
        <table style="width: 1000px">
            <tr>    
                <th style="width:20%">วันเวลาดำเนินการ</th>
                <th style="width:40%">สถานที่</th>
                <th style="width:10%">รหัสผู้ใช้</th>
                <th style="width:25%">ชื่อ-นามสกุล</th>
            </tr>
        @foreach ( $data as $d )
            <tr>
                <td>{{ $d -> out_time }}</td>
                <td>{{ $d -> address }}</td>
                <td>{{ $d -> id }}</td>
                <td>{{ $d -> name }} {{ $d -> surname }}</td>
            </form>
        </tr>
        @endforeach
    </div>
    <a style="padding-top: 20px;position:absolute;right:175px;bottom:75px;" href="{{ route('ood') }}">back</button>
</body>
</html>