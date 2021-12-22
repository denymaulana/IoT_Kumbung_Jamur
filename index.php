<?php
// session_start();

// // 
// if (!isset($_SESSION["login"]) ) {
//   header("Location: login.php");
//   exit;
// }
// //

// require ("db/koneksi.php");
?>

<!DOCTYPE html>
<html lang="en">

<head>

  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">
  <link rel="icon" href="img/ftik-ubp.ico" type="image/ico" sizes="32x32">
  <title>IoT</title>

  <!-- Custom fonts for this template-->
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">

  <!-- Custom styles for this template-->
  <link href="css/sb-admin-2.min.css" rel="stylesheet">
  <script src="js/jquery.min.js" type="text/javascript"></script>

<!--  beda -->
<!-- <link rel="stylesheet" type="text/css" href="assets/css/bootstrap.min.css"> -->
 <script type="text/javascript" src="assets/js/jquery-3.4.0.min.js"></script>
<script type="text/javascript" src="assets/js/mdb.min.js"></script> 
<script type="text/javascript" src="jquery-latest.js"></script> 
<!--  -->

  <script type="text/javascript">
    $(document).ready(function () {
      $("#suhu").load("view/suhu.php");
      $("#kelem").load("view/kelem.php");
      $("#cahaya").load("view/cahaya.php");
      $("#s_d").load("view/s_d.php");
      $("#k_d").load("view/k_d.php");
      $("#c_d").load("view/c_d.php");

      $("#waktu").load("view/waktu.php");

      $("#graf").load("view/data.php");

      var refreshId = setInterval(function () {
        $("#suhu").load('view/suhu.php?randval=' + Math.random());
        $("#kelem").load('view/kelem.php?randval=' + Math.random());
        $("#cahaya").load('view/cahaya.php?randval=' + Math.random());
        $("#s_d").load('view/s_d.php?randval=' + Math.random());
        $("#k_d").load('view/k_d.php?randval=' + Math.random());
        $("#c_d").load('view/c_d.php?randval=' + Math.random());

        $("#waktu").load('view/waktu.php?randval=' + Math.random());

        $("#graf").load('view/data.php?randval=' + Math.random());
        }, 3000);
      // }, 5000);
    });
  </script>

<!-- <script type="text/javascript">
var refreshId = setInterval(function () {
  $("#responcontainer").load("view/data.php");
}, 5000); -->
  <!-- </script> -->
<!--  -->

</head>

<body id="page-top">

  <!-- Page Wrapper -->
  <div id="wrapper">

    <!-- Sidebar -->
    <!-- <ul class="navbar-nav bg-gradient-primary sidebar sidebar-dark accordion" id="accordionSidebar"> -->
    <ul class="navbar-nav bg-secondary sidebar sidebar-dark accordion" id="accordionSidebar">

      <!-- Sidebar - Brand -->
      <a class="sidebar-brand d-flex align-items-center justify-content-center" href="index.php">
        <div class="sidebar-brand-icon rotate-n-15">
          <i class="fas fa-robot"></i>
        </div>
        <div class="sidebar-brand-text mx-3">IOT</div>
      </a>

      <!-- Divider -->
      <hr class="sidebar-divider my-0">

      <!-- Nav Item - Dashboard -->
      <li class="nav-item active">
        <a class="nav-link" href="index.php">
          <i class="fas fa-fw fa-tachometer-alt"></i>
          <span>Dashboard</span></a>
      </li>

<!-- Divider -->
<hr class="sidebar-divider my-0">


      <!-- coba -->


<!-- Divider -->
<hr class="sidebar-divider my-0">


      <!-- Nav Item - Dashboard -->
      <li class="nav-item">
        <a class="nav-link" href="tables.php">
          <i class="fas fa-fw fa-table"></i>
          <span>Tables</span></a>
      </li>

    </ul>
    <!-- End of Sidebar -->

    <!-- Content Wrapper -->
    <div id="content-wrapper" class="d-flex flex-column">

      <!-- Main Content -->
      <div id="content">

<!--  -->

        <!-- Topbar -->
        <nav class="navbar navbar-expand navbar-light bg-white topbar mb-4 static-top shadow">

<!-- Sidebar Toggle (Topbar) -->
<form class="form-inline">
    <button id="sidebarToggleTop" class="btn btn-link d-md-none rounded-circle mr-3">
        <i class="fa fa-bars"></i>
    </button>
</form>



<!-- Topbar Navbar -->
<ul class="navbar-nav ml-auto">

    <!-- Nav Item - Search Dropdown (Visible Only XS) -->
    <li class="nav-item dropdown no-arrow d-sm-none">
        <a class="nav-link dropdown-toggle" href="#" id="searchDropdown" role="button"
            data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            <i class="fas fa-search fa-fw"></i>
        </a>
        <!-- Dropdown - Messages -->
        <div class="dropdown-menu dropdown-menu-right p-3 shadow animated--grow-in"
            aria-labelledby="searchDropdown">
            <form class="form-inline mr-auto w-100 navbar-search">
                <div class="input-group">
                    <input type="text" class="form-control bg-light border-0 small"
                        placeholder="Search for..." aria-label="Search"
                        aria-describedby="basic-addon2">
                    <div class="input-group-append">
                        <button class="btn btn-primary" type="button">
                            <i class="fas fa-search fa-sm"></i>
                        </button>
                    </div>
                </div>
            </form>
        </div>
    </li>

    <!-- Nav Item - Alerts -->
    
    <!-- Nav Item - Messages -->
    

    <div class="topbar-divider d-none d-sm-block"></div>

    <!-- Nav Item - User Information -->
    <li class="nav-item dropdown no-arrow">
                            <a class="nav-link dropdown-toggle" href="#" id="userDropdown" role="button"
                                data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                                <span class="mr-2 d-none d-lg-inline text-gray-600 small">IoT</span>
                                <img class="img-profile rounded-circle"
                                    src="img/bprotic.png">
                            </a>
                            <!-- Dropdown - User Information -->
                            <div class="dropdown-menu dropdown-menu-right shadow animated--grow-in"
                                aria-labelledby="userDropdown">
                                <a class="dropdown-item" href="#">
                                    <i class="fas fa-user fa-sm fa-fw mr-2 text-gray-400"></i>
                                    Profile
                                </a>
                                <a class="dropdown-item" href="#">
                                    <i class="fas fa-cogs fa-sm fa-fw mr-2 text-gray-400"></i>
                                    Settings
                                </a>
                                <a class="dropdown-item" href="#">
                                    <i class="fas fa-list fa-sm fa-fw mr-2 text-gray-400"></i>
                                    Activity Log
                                </a>
                                <div class="dropdown-divider"></div>
                                <a class="dropdown-item" href="#" data-toggle="modal" data-target="#logoutModal">
                                    <i class="fas fa-sign-out-alt fa-sm fa-fw mr-2 text-gray-400"></i>
                                    Logout
                                </a>
                            </div>
                        </li>

                    </ul>

                </nav>
<!-- End of Topbar -->



        <!-- Begin Page Content -->
        <div class="container-fluid">

          <!-- Page Heading -->
          <div class="d-sm-flex align-items-center justify-content-between mb-4">
            <h1 class="h3 mb-0 text-gray-800">Monitoring Kumbung Jamur</h1>
          </div>

          <!-- Content Row -->
          <div class="row">

            <!-- Suhu -->
            <!-- <div class="col-xl-8 col-lg-7"> -->
            <div class="col-xl-4 col-md-6 mb-4">  
            <div class="card border-left-primary shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-primary text-uppercase mb-1">Suhu</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <div id="suhu"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-temperature-high fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <!-- Kelembaban -->
            <div class="col-xl-4 col-md-6 mb-4">
              <div class="card border-left-success shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-success text-uppercase mb-1">Kelembapan</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <div id="kelem"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-water fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <!-- Sensor LDR/Cahaya -->
            <div class="col-xl-4 col-md-6 mb-4">
              <div class="card border-left-info shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-info text-uppercase mb-1">Cahaya</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <div id="cahaya"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-adjust fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

<!-- Nilai Akhir / Defuzifikasi Suhu -->
                  <div class="col-xl-4 col-md-6 mb-4">  
                      <div class="card border-left-primary shadow h-100 py-2">
                          <div class="card-body">
                            <div class="row no-gutters align-items-center">
                              <div class="col mr-2">
                                <div class="text-xs font-weight-bold text-primary text-uppercase mb-1">Defuzzyfikasi Suhu</div>
                                <div class="h5 mb-0 font-weight-bold text-gray-800">
                                  <div id="s_d"></div>
                                </div>
                              </div>
                              <div class="col-auto">
                                <i class="fas fa-temperature-high fa-2x text-gray-300"></i>
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>

<!-- Nilai Akhir / Defuzzyfikasi Kelembapan -->

            <div class="col-xl-4 col-md-6 mb-4">
              <div class="card border-left-success shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-success text-uppercase mb-1">Defuzzyfikasi Kelembapan</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <div id="k_d"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-water fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <!-- Nilai Akhir / Defuzzyfikasi Cahaya -->
            <div class="col-xl-4 col-md-6 mb-4">
              <div class="card border-left-info shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-info text-uppercase mb-1">Defuzzyfikasi Cahaya</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <div id="c_d"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-adjust fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

          <!-- Waktu -->
          <div class="col-xl-12 col-lg-7">
          <div class="card border-left-warning shadow h-100 py-2">
                <div class="card-body">
                  <div class="row no-gutters align-items-center">
                    <div class="col mr-2">
                      <div class="text-xs font-weight-bold text-warning text-uppercase mb-1">Waktu</div>
                      <div class="h5 mb-0 font-weight-bold text-gray-800">
                        <!-- <div id="waktu" align="center"></div> -->
                        <div id="waktu" align="center"></div>
                      </div>
                    </div>
                    <div class="col-auto">
                      <i class="fas fa-calendar fa-2x text-gray-300"></i>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            
          </div>
<br>
          <!-- tempat untuk tampil grafik  -->
          <div class="container" style="text-align: center;">
            <h3>Grafik Sensor Secara Realtime</h3>
            <p>(Data yang ditampilkan 5 data terakhir)</p>
          </div>

          <!-- div untuk grafik -->
        <div class="container">
        <div class="container" id="graf" style="width: 80%; text-align: center">
      </div>
        </div>

        <!--  -->


          <!-- Footer -->
          <footer class="sticky-footer bg-white">
                <div class="container my-auto">
                    <div class="copyright text-center my-auto">
                        <span>Copyright &copy; My Website 2021</span>
                    </div>
                </div>
            </footer>
            <!-- End of Footer -->
        </div>
      </div>


<!-- Bootstrap core JavaScript-->
<script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

    <!-- Core plugin JavaScript-->
    <script src="vendor/jquery-easing/jquery.easing.min.js"></script>


    <!-- Page level plugins -->
    <script src="vendor/datatables/jquery.dataTables.min.js"></script>
    <script src="vendor/datatables/dataTables.bootstrap4.min.js"></script>


</body>

</html>