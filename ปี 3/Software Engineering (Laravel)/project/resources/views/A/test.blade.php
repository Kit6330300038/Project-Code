<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Laravel CRUD Index</title>

    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/test.css'); ?>">

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

    <style>
        
        </style>
</head>


<body>

    <nav class="navbar bg-success fixed-top">
        <div class="container-fluid">
          <img src="assets/img/lg.png" alt="Stickman" width="150" height="55">
           <h2 class="navbar-text text-white text-center ">หน้าหลัก</h2>
            
           @foreach($data as $company)
           <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
            @csrf
  
            <button type="submit" name="user_select" value={{$company->user_id}} style="font-size:20px; background-color:#7BBB71	; color:white; border-color:#7BBB71; height:50px; width:120px; border-radius: 10px;" >ข้อมูลผู้ใช้ </button> 
            </form>
            
          @endforeach


        </div>
      </nav>

      <div class="box1">

        @foreach($data as $company)

       
        
            <p style= 'margin-left:10%;margin-top:10%; font-size: 24px; '>สวัสดี คุณ{{ $company ->name }} {{ $company ->surname }}</p>


        <div class="butt" style="margin-top:5%;">

          <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
          @csrf

          <button type="submit" name="ca_select" value={{$company->cabinet_id}} style="font-size:22px;  margin-left:80px ;margin-top:20px ; background-color:#41A62A	; color:white; border-color:#41A62A; height:70px; width:200px; border-radius: 10px;" >จัดการตู้ </button> 
          </form>
    
      
    
    
        <a href="{{ route('deca') }}"><input type="submit" style="font-size:22px;  margin-left:130px ;margin-top:20px ; background-color:#41A62A	; color:white; border-c olor:#41A62A; height:70px; width:180px; border-radius: 10px;" name="Submit" value="ข้อมูลแบตเตอรี่" ></a> 

        @endforeach

        </div>
    
      </div>


</body>
</html>