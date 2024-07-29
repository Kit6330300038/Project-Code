<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Cabinet Manager</title>
    <link href="assets/css/manageCabinet.css" rel="stylesheet"  >
</head>
<body>
    <div class="header">
        <div class="header-right">
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a href="{{route('companies.index')}}" style="font-size: 20px; ">จัดการตู้</a>
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a class="active" href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a_active" href="{{route('companies.index')}}" data-text="home">รายละเอียดของตู้</a></li>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="tags">ลดตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="categories">สรุปรายรับ</a></li>
        </ul>
    </div>
    
    <div>
        <a href="{{route('companies.index')}}" class="img">
            <img src="assets/css/lg.png" alt="swapppp" width="100" height="50">
        </a>
        
        
    </div>
    
    
</body>
</html>