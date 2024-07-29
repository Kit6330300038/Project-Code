<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Laravel Project Index</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body>

    <div class="container mt-5">
        <div class="row">
            <div class="col-lg-12 text-center">
                <h2>ตู้ Swap Battery</h2>
            </div>
            <div>
                <a href="{{ route('companies.create') }}" class="btn btn-success">สร้างตู้</a>
            </div>
            @if ($message = Session::get('success'))
            <div class="alert alert-success">
                <p>{{ $message }}</p>
            </div>
            @endif

            <table class="table table-bordered">
                <tr>
                    <th>ลำดับตู้</th>
                    <th>สถานที่ที่ตู้ตั้งอยู่</th>
                    <th>สถานะแบตเตอรี่</th>
                    <th width="280px">แก้ไข/ลบ</th>
                </tr>
                <?php $i=1; ?>
                @foreach($companies as $company)
                        <td>{{ $i++ }}</td>
                        <td>{{ $company->address }}</td> <!-- <td> <a href="" class="btn btn-primary">{{ $company->address }}</a></td> -->
                        @if ($company->battery_status == "ชาร์จเต็ม")
                        <td class="text-success">{{ $company->battery_status }}</td>
                        @elseif ($company->battery_status == "ชาร์จไม่เต็ม")
                        <td class="text-danger">{{ $company->battery_status }}</td>
                        @else
                        <td class="text-warning">{{ $company->battery_status }}</td>
                        @endif
                        <td>
                            <form action="{{ route('companies.destroy',$company->id) }}" method="POST">
                                <a href="{{ route('companies.edit',$company->id) }}" class="btn btn-warning">Edit</a>
                                @csrf
                                @method('DELETE')
                                <button type="submit" class="btn btn-danger">Delete</button>
                            </form>
                        </td>
                    </tr>
                @endforeach
            </table>
            {!! $companies->links('pagination::bootstrap-5') !!}
            <div class="col-2 ms-auto"><a href="" class="btn btn-primary">ย้อนกลับ</a></div>
        </div>
    </div>
    
</body>
</html>