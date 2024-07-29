<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>News Blog Page</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body style="background-color:powderblue">
    
    <div class="container mt-2">
        <div class="row">
            <div class="mt-4 col-lg-12 text-center">
                <h2>บล็อกข่าว | News Blog</h2>
            </div>
            <div>
                <a href="{{ route('kaos.create') }}" class="btn btn-success">Create News</a>
            </div>
            @if ($message = Session::get('success'))
            <div class="alert alert-success">
                <p>{{  $message }}</p>
            </div>
            @endif

            <table class="table table-bordered" style='border: 1px solid black;'>
                <tr>
                    <th>No.</th>
                    <th>News Name</th>
                    <th>News Detail</th>
                    <th>News Link</th>
                    <th width="280px">Action</th>
                </tr>
                @foreach($kaos as $kao)
                    <tr>
                        <td>{{ $kao->id }}</td>
                        <td>{{ $kao->name }}</td>
                        <td>{{ $kao->news }}</td>
                        <td>{{ $kao->link }}</td>
                        <td>
                            <form action="{{ route('kaos.destroy', $kao->id) }}" method="POST">
                                <a href="{{ route('kaos.edit',$kao->id) }}" class="btn btn-warning">Edit</a>
                                @csrf
                                @method('DELETE')
                                <button type="submit" class="btn btn-danger">Delete</button>
                            </form>
                        </td>
                    </tr>
                @endforeach
            </table>
            {!! $kaos->links('pagination::bootstrap-5') !!}
        </div>
    </div>    

    <div class="container-center text-center" style="width:900px; height:550px"> 
        <div class="row">
            <h2>SWAPPIES</h2>
            <div>ให้บริการสลับแบตเตอรี่สำหรับมอเตอร์ไซค์ไฟฟ้า (Battery swapping services)</div>
            <h2>ติดต่อเรา</h2>
            <div>Facebook : Swappies</div>
            <div>Instagram : Swappies</div>
            <div>Line Official Account : @Swappies</div>
            <div>Email : Swappies@gmail.com</div>
        </div>
    </div>

</body>
</html>