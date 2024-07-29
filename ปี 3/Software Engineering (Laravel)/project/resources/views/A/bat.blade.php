<!DOCTYPE html>
<html>
<head>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

    <link href="assets/css/bat.css" rel="stylesheet">

<style>
</style>
</head>
<body>

<div>
  <div class="header">
    <img src="assets/img/lg.png" alt="Stickman" width="150" height="55" style="padding-top: 10px; margin-left:10px;">
    <div class="header-right">
      
      <a href="{{route('test')}}" style="font-size: 20px;" >จัดการแบตเตอรี่</a>
      <a class="active" href="{{route('test')}}" style="margin-left: 150px; font-size: 20px;">จัดการตู้</a>
      
    </div>
  </div>
</div>

<div class="tables">

  @foreach($data as $company)
  <h4 style=" color:#005900;  margin-left:5%;"> รหัสตู้ : {{ $company->cabinet_id}} <br><br>สถานที่ : {{ $company->location }}  </h5>
  
    @break


   
  </form>

  @endforeach

   
<table>
    @foreach($data as $company)
    
    <tr >
      <td style="width: 30%;"> หมายเลขแบต : {{ $company->bat_id }}</td>
      <td style="width: 50%;">สถานะแบต : 
        @if($company->status == 1)
        ชาร์จเต็มแล้ว
        @endif
        @if($company->status == 0)
        ชาร์จยังไม่เต็มแล้ว
        @endif
        @if($company->status == 9)
        แบตเตอรี่ไม่อยู่ที่ตู้
        @endif
        @if($company->status == 8)
        แบตเตอรี่ถูกเรียกคืน
        @endif
        @if($company->status == 5)
        แบตเตอรี่ไม่อยู่ในระบบ
        @endif
        

        
      </td>
      <td><button type="submit" name="bat_data" value={{$company->cabinet_id}} style="font-size:20px;  margin-left:10% ;margin-top:5% ; background-color:#CE613F; color:white; border-color:#CE613F; height:50px; width:150px; border-radius: 10px;">รายละเอียด </button> </td>
      
    </tr>
    @endforeach
    
  </table>


  @foreach($data as $company)
  <form action="{{ route('companies.store') }}" method="POST" enctype="multipart/form-data">
    @csrf
    

    <button type="submit" name="ca_select" value={{$company->cabinet_id}} style="font-size:20px;  margin-left:80% ;margin-top:5% ; background-color:#3B9327; color:white; border-color:#3B9327; height:50px; width:150px; border-radius: 10px;">ย้อนกลับ </button> 
    @break

  </form>

  @endforeach

 
</div>


</body>
</html>


