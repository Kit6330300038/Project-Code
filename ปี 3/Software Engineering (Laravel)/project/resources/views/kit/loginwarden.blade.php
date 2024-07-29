
<!DOCTYPE html>
<html>
<link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/barrr.css'); ?>">
<style>
  .button {
    background-color: #00a5c6;
    border: none;
    color: rgb(0, 0, 0);
    padding: 15px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
  }
  .input1 {
    background-color: #e8e8e8;
    font-size: 25px;
    margin-left: 40px;
    border-radius: 25px;
    padding: 7px 1px 7px 20px;
    width: 450px;
    height: 40px;
  }
  .space {
    height: 20px;
  }
  .warning {
    color: rgb(255, 0, 0);
    font-size: 30px;
  }
  </style>
<body>

    <div>
    
      <div class="header">
        <img src="assets/images/lg.png" alt="Stickman" width="156" height="65" style="padding-top: 8px; margin-left:10px;"/>
        <div class="header-right">
          
          <h1 style="margin-left: 157px; font-size: 30px; position:relative; top: -25px;" >เข้าสู่ระบบสำหรับผู้ดูแลตู้</h1>

          <a href="{{route('login')}}" style="margin-left: 150px; font-size: 20px;" >ผู้ใช้ทั่วไป</a>
          <a class="active" href="{{route('loginwd')}}" style="margin-left: 30px; font-size: 20px;">ผู้ดูแลตู้</a>
          <a href="{{route('loginmg')}}" style="margin-left: 30px; font-size: 20px;">ผู้จัดการ</a>

          
        </div>
        <div class="header-right" style='margin-left: 50px;top:150px;height:400px;width:550px;
          background:linear-gradient(180deg, #ffffff 40%, #f9d5f8 90%);border-radius: 25px;'>
          <p class='space'></p>
          <form method="POST" action="{{ route('wardenlogin') }}">
            @csrf <!-- {{ csrf_field() }} -->
            <input type="text" id='username1' name="username" placeholder="Emaill or Username" class="input1"><br>
            <p class='space'></p>
            <input type="password" id='password1' name="password" placeholder="Password" class="input1"><br>
            <p style="height: 5px;"></p>
            <button type='submit' class="button" style="margin-left: 225px;border-radius: 25px;">LOG IN</button>
            <p style="height: 2px;"></p>
            @if(Session::has('error'))
              <div>
                <strong class="warning" style="margin-left: 10px;">ERROR!!, {{ Session::get('error') }}</strong> 
              </div>
            @endif
          </form>
        </div>
        

      </div>
      
    
    </div>
    
</body>    