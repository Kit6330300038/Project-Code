<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Suffer laravel</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/kant.css'); ?>">
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
    

</head>

<body >
    <div class="header">
        <a href="{{route('companies.index')}}" class="img">
            <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
        </a>
        <div class="header-right">
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a href="{{route('companies.index')}}" style="margin-left: 60px;font-size: 20px; ">จัดการตู้</a>
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a class="active" href="{{route('companies.index')}}" style=" font-size: 20px;" >จัดการผู้ดูแล</a>
        </div>
    </div>
        
        

    <div class="sidebar">
        <div class="menuindex d-grid gap-2 text-center ">
            <ul>
                <li><a class ="sidebar-a" href="{/{route('companies.create')}}" data-text="home">เพิ่มผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a" href="{{route('editindex')}}" data-text="archives">เปลี่ยนผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a" href="{{route('deleteindex')}}" data-text="tags">ปลดผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a_active" href="{/{route('companies.index')}}" data-text="categories">ผู้ดูแลรับผิดชอบตู้</a></li>
            </ul>
            
        </div>
        
        
    </div>


    <div class="containerindex-center">
        <div class="contianer mt-2" >
 
            <table class="table table-bordered border-dark "> 
                <tr>
                    <th>ID ผู้ดูแล</th>
                    <th>ชื่อผู้ดูแล</th>
                    <th>ID ตู้ที่รับผิดชอบ</th>
                    <th>สถานที่ตั้งของตู้</th>
                </tr>
                @foreach($companies as $company)
                    <tr>
                        <td>{{ $company -> id}}</td>
                        <td>{{ $company -> name}} {{ $company -> surname}}</td>
                        <td>{{ $company -> idswappies}}</td>
                        <td>{{ $company -> address}}</td>
                    </tr>
                @endforeach
            </table>
        {!! $companies->links('pagination::bootstrap-5') !!}
        
        </div>
    </div>

    <div>

        
    </div>
      


    
    

</body>
</html>


