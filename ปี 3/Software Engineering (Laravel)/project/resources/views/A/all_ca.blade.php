<!DOCTYPE html>
<html>
<head>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/all_ca.css'); ?>">

<style>



</style>
</head>
<body>

<div>

  <div class="header">
    <img src="assets/img/lg.png" alt="Stickman" width="150" height="55" style="padding-top: 10px; margin-left:10px;">
    <div class="header-right">
      
      {{-- <a href="{{route('companies.index')}}">สำหรับผู้จัดการตู้</a> --}}
      <a  href="{{route('test')}}" style="font-size: 20px;" >จัดการแบตเตอรี่</a>
      <a class="active" href="{{route('location')}}" style="margin-left: 150px; font-size: 20px;">จัดการตู้</a>
      
    </div>
  </div>


</div>

<div class="tables">

  
  <div class="box_bat">

    
  <table>
      @foreach($data as $company)

          <tr>
                        
            <td >
              <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
                @csrf

                <p> หมายเลขตู้ที่รับผิดชอบ : {{ $company->cabinet_id }} <br><br> สถานที่ตั้ง : {{ $company->location }}</p>
            
                <button type="submit" name="bat_select" value={{$company->cabinet_id}} style="font-size:20px;  margin-left:80% ; background-color:#3B9327; color:white; border-color:#3B9327; height:50px; width:150px; border-radius: 10px;" > แบตเตอรี่ </button> 
                </form>
            
              </div>
              </td>
           
          </tr>
      
      @endforeach
      
    </table>


  <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
    @csrf

    <button type="submit" name="login" value={{$company->user_id}} style="font-size:20px;  margin-left:80% ;margin-top:5% ; padding bottom:50px ; background-color:#3B9327; color:white; border-color:#3B9327; height:50px; width:150px; border-radius: 10px;" > ย้อนกลับ </button> 
    </form>

  </div>


</div>


</body>
</html>


