<!DOCTYPE html>
<html>
<title> สรุป ตู้เดี่ยว ???? </title>
<link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
<head>
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
        <a href="{{route('concludeone')}}" class="img">
                <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
        </a>
        <div class="header-right">
          <a href="{/{route('addBattery')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a class="active" href="{/{route('detailOfCabinet')}}" style="font-size: 20px; ">จัดการตู้</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a href="{/{route('manageContain')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
          <a href="#" style="margin-left: 60px; font-size: 20px;">จัดการบล็อคข่าว</a>
        </div>
        <div>

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
            <form method="POST" action="{{ route('getinfo') }}">
                @csrf <!-- {{ csrf_field() }} -->
                <label for="box" style="padding-left: 40px;font-size: 20px;">ปี : </label>
                <select name="years" id="box" style="font-size: 20px;">
                    <option value="0">please select</option>
                    @foreach( $years as $year)
                        <option value="{{ $year -> year }}">{{ $year -> year }}</option>
                    @endforeach
                </select>
        
                <label for="se" style="padding-left: 40px;font-size: 20px;">เดือน : </label>
                <select name="mounth" id="se" style="font-size: 20px;">
                    <option value="0">please select</option>
                    <option value="1">มกราคม</option> <option value="2">กุมภาพันธ์</option> <option value="3">มีนาคม</option>
                    <option value="4">เมษายน</option> <option value="5">พฤษภาคม</option> <option value="6">มิถุนายน</option>
                    <option value="7">กรกฎาคม</option ><option value="8">สิงหาคม</option> <option value="9">กันยายน</option>
                    <option value="10">ตุลาคม</option> <option value="11">พฤศจิกายน</option> <option value="12">ธันวาคม</option>
                </select>
                <label for="da" style="padding-left: 40px;font-size: 20px;">วันที่ : </label>
                <select name="day" id="da" style="font-size: 20px;">
                    <option value="0">please select</option>
                    <option value="1">1</option> <option value="2">2</option> <option value="3">3</option>
                    <option value="4">4</option> <option value="5">5</option> <option value="6">6</option>
                    <option value="7">7</option ><option value="8">8</option> <option value="9">9</option>
                    <option value="10">10</option> <option value="11">11</option> <option value="12">12</option>
                    <option value="13">13</option> <option value="14">14</option> <option value="15">15</option>
                    <option value="16">16</option> <option value="17">17</option> <option value="18">18</option>
                    <option value="19">19</option> <option value="20">20</option> <option value="21">21</option>
                    <option value="22">22</option> <option value="23">23</option> <option value="24">24</option>
                    <option value="25">25</option> <option value="26">26</option> <option value="27">27</option>
                    <option value="28">28</option> <option value="29">29</option> <option value="30">30</option>
                    <option value="31">31</option>
                </select>

                <label for="t" style="padding-left: 40px;font-size: 20px;">ประเภท : </label>
                <select name="top" id="t" style="font-size: 20px;">
                    <option value="0">plase select</option>
                    <option value="1">มัดจำ</option> <option value="2">จ่ายเต็ม</option>
                </select>
                <label for="mum" style="padding-left: 40px;font-size: 20px;">รหัสผู้ดำเนินการ : </label>
                <input type="text" pattern="\d*" name="uid" id="mum" style="font-size: 20px;" maxlength="4">
                
                <label style="padding-right: 30px;"></label>
                <button type='submit' style="font-size: 20px;">ยืนยัน</button>
            </form>
            @if(Session::has('table'))

                            <div style="padding-top: 30px">
                                <table style="width: 1000px">
                                    <tr>    
                                        <th style="width:20%">วันดำเนินการ</th>
                                        <th style="width:20%">ID ผู้ใช้</th>
                                        <th style="width:20%">รูปแบบการจ่าย</th>
                                        <th style="width:20%">จำนวน</th>
                                        <th style="width:20%">รวม</th>
                                    </tr>
                                    <?php $sum = 0 ?>
                                    @foreach( Session::get('table') as $incom)
                                        <tr>
                                            @csrf <!-- {{ csrf_field() }} -->
                                            <td>{{ $incom -> Date_of_payment }}</td>
                                            <td>{{ $incom -> User_ID }}</td>
                                            @if ( $incom -> Type_of_payment == 1)
                                                <td>เช่าซื้อ</td>
                                            @else
                                                <td>จ่ายเต็ม</td>
                                            @endif
                                            <td>{{ $incom -> Price }}</td>
                                            <td><?php $sum += $incom->Price  ?>{{ $sum }} </td>
                                        </tr>
                                        
                                    @endforeach
                                    <tr>
                                        <td style="border: 1px solid #D9D9D9;"></td>
                                        <td style="border: 1px solid #D9D9D9;"></td>
                                        <td style="border: 1px solid #D9D9D9;border-left-color:1px soild black"></td>
                                        <td style="font-weight: bold;border-left: 2px solid rgb(0, 0, 0);">TOTAL : </td>
                                        <td> {{ $sum }} </td>
                                    </tr>
                                </table>
                            </div>
                        @endif

            @if (!Session::has('table'))
                <div style="padding-top: 30px">
                <table style="width: 1000px">
                    <tr>    
                        <th style="width:20%">Date_of_payment</th>
                        <th style="width:20%">User_ID</th>
                        <th style="width:20%">Type_of_payment</th>
                        <th style="width:20%">จำนวน</th>
                        <th style="width:20%">รวม</th>
                    </tr><?php $sum = 0 ?>
                    @foreach( $dtable as $incom)
                        <tr>
                            <td>{{ $incom -> Date_of_payment }}</td>
                            <td>{{ $incom -> User_ID }}</td>
                            @if ( $incom -> Type_of_payment == 1)
                                <td>เช่าซื้อ</td>
                            @else
                                <td>จ่ายเต็ม</td>
                            @endif
                            <td>{{ $incom -> Price }}</td>
                            <td ><?php $sum += $incom->Price  ?>{{ $sum }}</td>
                        </tr>
                    @endforeach
                    <tr>
                        <td style="border: 1px solid #D9D9D9;"></td>
                        <td style="border: 1px solid #D9D9D9;"></td>
                        <td style="border: 1px solid #D9D9D9;border-left-color:1px soild black"></td>
                        <td style="font-weight: bold;border-left: 2px solid rgb(0, 0, 0);">TOTAL : </td>
                        <td> {{ $sum }} </td>
                    </tr>
                </table>
            @endif
            <a style="position:absolute;right:175px;bottom:75px;" href="{{route('concludeall')}}">back</a>
        </div>


</body>
<script>


</script>
