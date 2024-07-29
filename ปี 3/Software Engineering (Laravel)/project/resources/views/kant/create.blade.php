<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create Data</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <!--<link rel="stylesheet" href="{{ asset('test.css') }}">-->
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/kant.css'); ?>">

</head>
<body>
    <div class="header">
        <a href="{{route('companies.index')}}" class="img">
            <img src="{{asset('assets/images/lg.png')}}" alt="swapppp" width="100" height="50">
        </a>
        
        <div class="header-right">
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการแบตเตอรี่</a>
          <a href="{{route('companies.index')}}" style="font-size: 20px; ">จัดการตู้</a>
          <a href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการบัญชี</a>
          <a class="active" href="{{route('companies.index')}}" style="margin-left: 60px; font-size: 20px;" >จัดการผู้ดูแล</a>
        </div>
    </div>
    <div class="sidebar">
        <div class="menucreate d-grid gap-2 text-center ">
            <ul>
                <li><a class ="sidebar-a_active" href="{{route('companies.create')}}" data-text="home">เพิ่มผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a" href="{{route('editindex')}}" data-text="archives">เปลี่ยนผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a" href="{{route('deleteindex')}}" data-text="tags">ปลดผู้ดูแลตู้</a></li>
                <li><a class ="sidebar-a" href="{{route('companies.index')}}" data-text="categories">ผู้ดูแลรับผิดชอบตู้</a></li>
            </ul>
            

        </div>
        
        
    </div>
    <div class="username">
        
    </div>

    <div class="container-center" style="height:450px">
        <div class="continer mt-2">
            <div class="row">
        
                @if (session('status'))
                    <div class="alert alert-success">
                        {{ session('status')}}
                    </div>
                @endif
                <form action="{{ route('companies.store')}}" method="POST" enctype="multipart/form-data">
                    @csrf
                    <div class="row">
                        <!--<div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>หมายเลขไอดีพนักงาน</strong>
                                <input type="number" name="id" class="form-control0" placeholder="เลขไอดี" min="6000">
                                @error('id')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>-->
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>ชื่อ พนักงาน</strong>
                                <input type="text" name="name" class="form-control0" placeholder="ชื่อ">
                                @error('name')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>นามสกุล พนักงาน</strong>
                                <input type="text" name="surname" class="form-control0" placeholder="นามสกุล">
                                @error('surname')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>EMAIL</strong>
                                <input type="email" name="username" class="form-control0" placeholder="email">
                                @error('username')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>PASSWORD</strong>
                                <input type="text" name="password" class="form-control0" placeholder="password">
                                @error('password')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>หมายเลข ID ตู้ที่รับผิดชอบ</strong>
                                <input type="number" name="idswappies" class="form-control0" placeholder="หมายเลข ID ตู้" min="500000">
                                @error('idswappies')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>เบอร์โทรศัพท์</strong>
                                <input type="tel" name="phone" class="form-control0" placeholder="เบอร์โทรศัพท์">
                                @error('phone')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>
                        <!--<div class="col-md-12">
                            <div class="form-group my-3">
                                <strong>สถานที่ของตู้</strong>
                                <input type="text" name="cabinets.address" class="form-control0" placeholder="สถานที่ตั้งตู้">
                                @error('cabinets.address')
                                    <div class="lert alert-danger">{{$message}}</div>
                                    
                                @enderror
                            </div>
                        </div>-->
                        <div class="d-grid gap-2 col-6 mx-auto">
                            <button  type="submit" class="btn btn-success btn-lg " >Submit</button>
                            
                        </div>
                        <div class="d-grid gap-2 col-6 mx-auto">
                            
                            <a href="{{ route('companies.index')}}" class="btn btn-primary">Back</a>
                        </div>
                        
                        
                    </div>
                
                </form>
            </div>
        </div>
    </div>
    <div>

        
    </div>
    


    
    
</body>
</html>
