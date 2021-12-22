<?php
// $servername = "127.0.0.1";
// $database = "cv";
// $username = "root";
// $password = "";
// $konek = mysqli_connect ($servername, $database, $username, $password); 
// $sql = "SELECT * FROM `work`";
// if (!$konek) {
//     die("Connection failed: " . mysqli_connect_error());
// }

$konek = mysqli_connect("localhost", "root", "", "db_jamur");
$sql = "SELECT * FROM `pemantauan`";
if (!$konek) {
    die("Connection failed: " . mysqli_connect_error());
}

?>