<h1>รายละเอียดของตู้<h1>
<table border="1">
    <tr>
        <td>รหัสตู้</td>
        <td>สถานที่ที่ตู้ตั้งอยู่</td>
        <td>ที่อยู่ของสถานที่ที่ตู้ตั้งอยู่</td>
        <td>รูปภาพประกอบ</td>
    </tr>
    @foreach ($data as $cabi)
    <tr>
        <td>{{$cabi->id}}</td>
        <td>{{$cabi->location}}</td>
        <td>{{$cabi->address}}</td>
        <td>
            <img src="{{ asset($cabi->img)}}" width='150' height='100' class="img img-responsive" />
        </td>
    </tr>
    @endforeach
</table>