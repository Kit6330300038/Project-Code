<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create Data</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/test.css'); ?>">
  
    <style>
      
        
        </style>
</head>
<body>

    <nav class="navbar bg-success fixed-top">
        <div class="container-fluid">
          <img src="assets/img/lg.png" alt="Stickman" width="150" height="55">
           <h2 class="navbar-text text-white text-center ">ผู้ใช้</h2>
           <a href="{{ route('test3') }}" class="btn btn-danger btn-lg">ออกจากระบบ</a>
        </div>
      </nav>

      <div class="box2">
        


        @foreach($data as $company)
       
          <p style='margin-left:10%;padding-top:35px; font-size: 20px;'>ชื่อ : {{ $company->name }}  {{ $company ->surname }}</p>
          <p style='margin-left:10%;padding-top:20px; font-size: 20px;'>เบอร์โทร :  {{ $company->phone }}</p>
          <p style='margin-left:10%;padding-top:20px; font-size: 20px;'>ID : {{ $company->user_id }}</p>
          <p style='margin-left:10%;padding-top:20px; font-size: 20px;'>หมายเลขตู้ที่รับผิดชอบ : {{$company->cabinet_id }} </p>

        @endforeach

        <div class="butt" style="margin-top:5%;">

        </div>
    
      </div>

      @foreach($data as $company)
           <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
            @csrf
  
            <button type="submit" name="login" value={{$company->user_id}} class="btn btn-success btn-lg" style="margin-left:80%;margin-top:2% ;" >ย้อนกลับ </button> 
            </form>
            
          @endforeach


</body>
</html>