<?php
// include ("../db/get_data.php");
$konek = mysqli_connect("localhost", "root", "", "db_jamur");
// include ("koneksi.php");


// baca id tertinggi
$sql_id = mysqli_query($konek, "SELECT MAX(id) FROM pemantauan");
// tanggap datanya
$data_id = mysqli_fetch_array($sql_id);
// ambil id terakhir / terbesar
$id_akhir = $data_id['MAX(id)'];  // id=8
$id_awal = $id_akhir - 4;


// baca informasi tanggal untuk semua data sumbu x di grafik
$timestamp = mysqli_query($konek, "SELECT timestamp FROM pemantauan WHERE id>= '$id_awal' and id<='$id_akhir' ORDER BY id DESC");
// baca informasi suhu untuk semua data sumbu x di grafik
$suhu = mysqli_query($konek, "SELECT suhu FROM pemantauan WHERE id>= '$id_awal' and id<='$id_akhir' ORDER BY id DESC");
// baca informasi kelembapan untuk semua data sumbu x di grafik
$kelem = mysqli_query($konek, "SELECT kelembapan FROM pemantauan  WHERE id>= '$id_awal' and id<='$id_akhir' ORDER BY id DESC");
// baca informasi Cahaya untuk semua data sumbu x di grafik
$ldr = mysqli_query($konek, "SELECT cahaya FROM pemantauan WHERE id>= '$id_awal' and id<='$id_akhir' ORDER BY id DESC");
?>

<!-- tampilan grafik -->
<div class="panel panel-primary">
<div class="panel-heading">
    Grafik Sensor
</div>

<div class="panel-body">
<!-- siapkan canvas untuk grafik -->
<canvas id="myChart"> </canvas>

<!-- gambar grafik -->
<script type="text/javascript">
// baca id canvas tempat grafik akan diletakan
var canvas = document.getElementById('myChart');
// letakan data tanggal dan suhu untuk grafik
var data = {
    labels : [
        <?php
        while($data_tanggal = mysqli_fetch_array($timestamp))
        {
            echo '"'.$data_tanggal['timestamp'].'",' ;
        }
        ?>
    ],
    datasets : [
        
        {
        label : "Suhu",
        fill: true,
        backgroundColor: "rgba(255, 0, 0, 0.1)",
        borderColor: "rgba(255,0,0,0.9)",
        lineTension: 0.5,
        pointRadius: 5,
        data : [
            <?php
                while($data_suhu = mysqli_fetch_array($suhu))
                {
                    echo $data_suhu['suhu'].',';
                }
            ?>
        ]
    },

    {
        label : "Kelembapan",
        fill: true,
        backgroundColor: "rgba(0, 255, 0, 0.1)",
        borderColor: "rgba(0,255,0,0.9)",
        lineTension: 0.5,
        pointRadius: 5,
        data : [
            <?php
                while($data_kelem = mysqli_fetch_array($kelem))
                {
                    echo $data_kelem['kelembapan'].',';
                }
            ?>
        ]
    },

    {
        label : "Cahaya",
        fill: true,
        backgroundColor: "rgba(0, 0, 255, 0.1)",
        borderColor: "rgba(0,0,255,0.9)",
        lineTension: 0.5,
        pointRadius: 5,
        data : [
            <?php
                while($data_cahaya = mysqli_fetch_array($ldr))
                {
                    echo $data_cahaya['cahaya'].',';
                }
            ?>
        ]
    }
]
};


// opsi grafik
var option = {
    showLines : true,
    animation : {duration : 0}
};

// cetak grafik kedalam canvas
var myLineChart = Chart.Line(canvas, {
    data : data,
    options : option
});


</script>
</div>
</div>