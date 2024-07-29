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

    

      


      <div class="box1">

        <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
          @csrf

          <li><strong>รหัสผู้ดูแล : </strong><input name="login"><button type="submit" style="font-size:15px; background-color:#6BB3E0; color:black; border-color:#6BB3E0; height:40px; width:110px; border-radius: 10px; margin:10px;">เข้าสู่ระบบ</button></li>
          
        </form>

        
      </div>

 


</body>
</html>