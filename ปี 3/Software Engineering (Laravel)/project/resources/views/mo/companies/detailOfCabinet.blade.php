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
    <div class="container-center" style="width:900px; height:550px"> 
        <div class="row">
            <h3>รายละเอียดของตู้</h3>
        </div>
        <table border="1">
            <tr>
                <td>รหัสตู้</td>
                <td>สถานที่ที่ตู้ตั้งอยู่</td>
                <td>ที่อยู่ของสถานที่ที่ตู้ตั้งอยู่</td>
                <td>รูปภาพประกอบ</td>
            </tr>
            @foreach ($data as $cabi)
            <tr>
                <td>{{$cabi->id}}</td>
                {{-- <td>{{$cabi->location}}</td> --}}
                <td>{{ $cabi->location }}</td>
                <td>{{$cabi->address}}</td>
                <td>
                    <img src="{{ asset($cabi->img)}}" alt="okkkk" width='130' height='65'/> <!-- class="img img-responsive" -->
                </td>
                <form method="POST" action="{{ route('getcabiinfo') }}">
                    @csrf <!-- {{ csrf_field() }} -->
                    <input style="display: none;" name="id" value='{{$cabi -> id}}'>
                <td style="width: 100px;border: 2px solid #D9D9D9;"><button type='submit' style="">รายละเอียด</button></td>
                {{-- @if ($cabi->id == '500000')
                    <td>
                        <a href="{{ route('detailOfBattery',$cabi->id) }}"
                            <button type="submit" class="breadcrumb">ตึกคอม ศรีราชา</button>
                        </a>
                    </td>
                @endif --}}
            </tr>
            @endforeach
        </table>

        <div class="col-md-12">
            <button type="submit" class="mt-3 btn btn-primary"> ยืนยัน </button>
        </div>
    </div>

    <div class="header">
        <div class="header-right">
          <a href="#" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a class="active" href="#" style="font-size: 20px; ">จัดการตู้</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
        </div>
    </div>
    
    <div class="sidebar">
        <ul>
            <li><a class ="sidebar-a_active" href="#" data-text="home">รายละเอียดของตู้</a></li>
            <li><a class ="sidebar-a" href="#" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="#" data-text="tags">ลดตู้แบตเตอรี่</a></li>
            <li><a class ="sidebar-a" href="#" data-text="categories">สรุปรายรับ</a></li>
        </ul>
    </div>
    
    <div>
        <a href="#" class="img">
            <img src="assets/img/swappies.png" alt="swapppp" width="100" height="50">
        </a>
    </div>
    
</body>
</html>