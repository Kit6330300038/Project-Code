<!DOCTYPE html>
<html lang="en">
<head>
    <title> หมดอายุ </title>
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
    <style>
        table,th, td {
            border: 2px solid black;
            border-collapse: collapse;
                
        }td{
            padding-left:7px
        }
    </style>
</head>
<body>
    <div class="header">       
        <div>
            <a href="{{route('concludeall')}}" class="img">
                <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
        </a>
        <div class="header-right">
          <a class="active"bhref="{{route('addBattery')}}" style=" font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a href="{/{route('detailOfCabinet')}}" style="margin-left: 60px; font-size: 20px; ">จัดการตู้</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>

    </div>
    
        </div>       
            <div class="sidebar">
                <ul>
                    <li><a class ="sidebar-a" href="{/{route('detailOfCabinet')}}" data-text="home">เพิ่มแบตเตอรี่</a></li>
                    <li><a class ="sidebar-a" href="{{route('manageCabinet')}}" data-text="archives">ลดแบตเตอรี่</a></li>
                    <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="tags">สถานะเรียกคืนแบตเตอรี่</a></li>
                    <li><a class ="sidebar-a_active" href="{{route('concludeall')}}" data-text="categories">รายชื่อแบตเตอรี่ที่ใกล้หมดอายุ</a></li>
                </ul>
            </div>
            <div class="container-center" style="width: 1000px;height: 500px">
                <div style="padding-top: 10px">
                    <table style="width: 1000px">
                        <tr>    
                            <th style="width:40%">วันผลิต</th>
                            <th style="width:25%">รหัสแบต</th>
                            <th style="width:25%">อายุ</th>
                            <th style="border: 2px solid #D9D9D9;"></th>
                        </tr><?php $sum = 0 ?>
                        @foreach( $out_of_date  as $incom)
                            <tr>@php
                                $ty = date('Y')-date("Y", strtotime($incom->create_date));
                            @endphp
                                <td>{{ $incom -> create_date }}</td>
                                <td >{{ $incom -> bat_id }}</td>
                                <td >{{ $ty }} ปี</td>
                                <?php $sum += 1 ?>
                                <form method="POST" action="{{ route('recall') }}">
                                    @csrf <!-- {{ csrf_field() }} -->
                                    <input style="display: none;" name="id" value='{{ $incom -> id }}'>
                                <td style="width: 100px;border: 2px solid #D9D9D9;"><button type='submit' style="">เรียกคืน</button></td>
                                </form>
                            </tr>
                                        
                        @endforeach
                    </table>
                @if ($sum == 15)
                    <strong style="color: red">แสดงผลเพียง 15 แถวแรกเท่านั้น</strong>
                @endif
                <br>
                @if (Session::has('success'))
                    <strong style="color:rgb(0, 149, 255)">{{ Session::get('success') }}</strong>
                @endif
                
                </div>

                <a style="padding-top: 20px;position:absolute;right:175px;bottom:75px;" href="{{ route('ood') }}">back</button>
            </div>
        
    </body>
    
</body>