<!DOCTYPE html>
<html lang="en">
<body>

<h1>T E S T USER</h1>
<h1 id="welcome"></h1>
<h1>HI {{ $name -> name }}    {{ $type }}</h1>
<h1>at {{ $name -> address }} </h1>
<h1>phone {{ $name -> phone }} </h1>

<form method="POST" action="{{ route('logout') }}">
    @csrf <!-- {{ csrf_field() }} -->
    <button type='submit'>LOG OUT</button>
</form>
</body>

<script>
    document.getElementById("welcome").innerHTML = 'WELCOME   ' + sessionStorage.getItem("name");
    //sessionStorage.removeItem('user');

</script>