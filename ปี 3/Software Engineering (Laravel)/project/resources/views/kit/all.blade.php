<!DOCTYPE html>
<html>
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
    <head> <!-- <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Prompt:wght@200&display=swap" rel="stylesheet"> -->
        <style>
            table,th, td {
                border: 2px solid black;
                border-collapse: collapse;
                
            }
        </style>
    </head>
    <body>
        <div class="header">
            <div class="header-right">
              <a href="{/{route('addBattery')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
              <a class="active" href="{/{route('detailOfCabinet')}}" style="font-size: 20px; ">จัดการตู้</a>
              <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
              <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
              <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
            </div>
            <div>
                <a href="{/{route('manageContain')}}" class="img">
                    <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
            </a>
        </div>
        
            </div>       
                <div class="sidebar">
                    <ul>
                        <li><a class ="sidebar-a" href="{/{route('detailOfCabinet')}}" data-text="home">รายละเอียดของตู้</a></li>
                        <li><a class ="sidebar-a" href="{{route('manageCabinet')}}" data-text="archives">เพิ่มตู้แบตเตอรี่</a></li>
                        <li><a class ="sidebar-a" href="{/{route('manageContain')}}" data-text="tags">ลดตู้แบตเตอรี่</a></li>
                        <li><a class ="sidebar-a_active" href="{{route('concludeall')}}" data-text="categories">สรุปรายรับ</a></li>
                        
                    </ul>
                </div>
                <div class="container-center" style="width: 1000px;height: 500px">
                    <form method="POST" action="{{ route('gettable') }}">
                        @csrf <!-- {{ csrf_field() }} -->
                        <label for="box" style="padding-left: 30px;font-size: 20px;">ปี : </label>
                        <select name="years" id="box" style="font-size: 20px;">
                            <option value="0">plase select</option>
                            @foreach( $years as $year)
                                <option value="{{ $year -> year }}">{{ $year -> year }}</option>
                            @endforeach
                        </select>
                
                        <label for="se" style="padding-left: 30px;font-size: 20px;">เดือน : </label>
                        <select name="mounth" id="se" style="font-size: 20px;">
                            <option value="0">plase select</option>
                            <option value="1">มกราคม</option> <option value="2">กุมภาพันธ์</option> <option value="3">มีนาคม</option>
                            <option value="4">เมษายน</option> <option value="5">พฤษภาคม</option> <option value="6">มิถุนายน</option>
                            <option value="7">กรกฎาคม</option ><option value="8">สิงหาคม</option> <option value="9">กันยายน</option>
                            <option value="10">ตุลาคม</option> <option value="11">พฤศจิกายน</option> <option value="12">ธันวาคม</option>
                        </select>
                        <label for="num" style="padding-left: 30px;font-size: 20px;">หมายเลขตู้ : </label>
                        <input type="text" pattern="\d*" name="swappies" id="mum" style="font-size: 20px;"maxlength="6">
                        
                        <label style="padding-right: 30px;"></label>
                        <button type='submit' style="font-size: 20px;">ยืนยัน</button>
                    </form>
                        @if(Session::has('table'))

                            <div style="padding-top: 30px">
                                <table style="width: 1000px">
                                    <tr>    
                                        <th style="width:15%">หมายเลขตู้</th>
                                        <th style="width:45%">สถานที่</th>
                                        <th style="width:15%">ประเภท</th>
                                        <th style="width:15%">จำนวน</th>
                                        <th style="border: 2px solid #D9D9D9;"></th>
                                    </tr>
                                    @foreach( Session::get('table') as $incom)
                                        <tr><form method="POST" action="{{ route('getinfo') }}">
                                            @csrf <!-- {{ csrf_field() }} -->
                                            <td>{{ $incom -> Swappies_ID }}</td>
                                            <td>{{ $incom -> address }}</td>
                                            @if ( $incom -> Type_of_payment == 1)
                                                <td>เช่าซื้อ</td>
                                            @else
                                                <td>จ่ายเต็ม</td>
                                            @endif
                                            <td>{{ $incom -> total }}</td>
                                            <input style="display: none;" name="id" value='{{ $incom -> Swappies_ID }}'>
                                            <input style="display: none;" name="top" value='{{ $incom -> Type_of_payment }}'>
                                            <td style="width: 100px;border: 2px solid #D9D9D9;"><button type='submit' style="">รายละเอียด</button></td>
                                        </form></tr>
                                        
                                    @endforeach
                                </table>
                            </div>
                        @endif
                        @if (!Session::has('table'))
                        <div style="padding-top: 30px">
                            <table style="width: 1000px">
                                <tr>    
                                    <th>หมายเลขตู้</th>
                                    <th>สถานที่</th>
                                    <th>ประเภท</th>
                                    <th>จำนวน</th>
                                    <th style="width: 100px;border: 2px solid #D9D9D9;"></th>
                                </tr>
                                @foreach( $dtable as $incom)
                                    <tr><form method="POST" action="{{ route('getinfo') }}">
                                        @csrf <!-- {{ csrf_field() }} -->
                                        <td>{{ $incom -> Swappies_ID }}</td>
                                        <td>{{ $incom -> address }}</td>
                                        @if ( $incom -> Type_of_payment == 1)
                                            <td>เช่าซื้อ</td>
                                        @else
                                            <td>จ่ายเต็ม</td>
                                        @endif
                                        <td>{{ $incom -> total }}</td>
                                        <input style="display: none;" name="id" value='{{ $incom -> Swappies_ID }}'>
                                        <input style="display: none;" name="top" value='{{ $incom -> Type_of_payment }}'>
                                        <td style="width: 100px;border: 2px solid #D9D9D9;"><button type='submit' style="">รายละเอียด</button></td>
                                    </form></tr>
                                    
                                @endforeach
                            </table>
                        @endif
                        <a style="position:absolute;right:175px;bottom:75px;" href="{{route('concludeall')}}">back</a>
                    
                </div>
            
        </body>
        
    </body>
    