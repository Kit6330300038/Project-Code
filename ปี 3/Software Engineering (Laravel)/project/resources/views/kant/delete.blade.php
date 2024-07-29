<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Delete Data</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/manageCabinet.css'); ?>">
    <link rel="stylesheet" type="text/css" href="<?php echo asset('assets/css/kant.css'); ?>">

</head>
<body>
    <div class="continer mt-2">
        <div class="row">
            <div class="col-lg-12">
                <h2>Delete Company</h2>
            </div>

            <div>
                <a href="{{ route('companies.index')}}" class="btn btn-primary">Back</a>
            </div>
            @if (session('status'))
                <div class="alert alert-success">
                    {{ session('status')}}
                </div>
            @endif
            <form action="{{ route('companies.destroydata',$company->id)}}" method="POST" enctype="multipart/form-data">
                @csrf
                @method('PUT')
                <div class="row">
                   
                    <button  type="submit" class="btn btn-primary">Submit</button>
                </div>
            
            </form>
        </div>
    </div>
    
</body>
</html>