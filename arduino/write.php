<?php 
include ("../db/koneksi.php");
$temp = $_GET['suhu'];
$humi = $_GET['kelembapan'];
$ldr = $_GET['cahaya'];
$d_s = $_GET['suhu_d'];
$d_k = $_GET['kelembapan_d'];
$d_c = $_GET['cahaya_d'];

mysqli_query($konek, "INSERT INTO `pemantauan` (`suhu`, `kelembapan`, `cahaya`, `suhu_d`, `kelembapan_d`, `cahaya_d`)
             VALUES ($temp, $humi, $ldr, $d_s, $d_k, $d_c)");

?> 