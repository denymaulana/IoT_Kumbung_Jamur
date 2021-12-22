<?php
function data($val){
    include ("koneksi.php");
    // $sql = "SELECT * FROM `work`";
    // $not = "sdbuwdg";
    $db = mysqli_query($konek, "SELECT * FROM `pemantauan` ORDER BY `timestamp` DESC");
    if ($data = mysqli_fetch_array($db) ){
        
        return $data[$val];
    }
    // else{
    //     return $not;
    // }
}
?>