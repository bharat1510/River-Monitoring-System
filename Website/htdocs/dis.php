<?php
$host    = "localhost";
$user    = "root";
$pass    = "";
$db_name = "registration";

$connection = mysqli_connect($host, $user, $pass, $db_name);
if(mysqli_connect_errno()){
    die("connection failed: "
        . mysqli_connect_error()
        . " (" . mysqli_connect_errno()
        . ")");
}

$result = mysqli_query($connection,"SELECT * FROM data");
$all_property = array(); 
?>
<html>
<head>
	<title>Displaying Analsis</title>
	<link href="ana.css" type="text/css">
</head>
<body>
	<table class="data-table">
		<caption class="title">River Monitering Analsis</caption>
		<style type="text/css">
		body {
			font-size: 15px;
			color: #343d44;
			font-family: "segoe-ui", "open-sans", tahoma, arial;
			padding: 0;
			margin: 0;
		}
		table {
			margin: auto;
			font-family: "Lucida Sans Unicode", "Lucida Grande", "Segoe Ui";
			font-size: 12px;
		}
		
		.data-table {
			border-collapse: collapse;
			font-size: 14px;
			min-width: 537px;
		}

		.data-table th, 
		.data-table td {
			border: 1px solid #e1edff;
			padding: 7px 17px;
		}
		.data-table caption {
			margin: 7px;
		}
		.data-table thead th {
			background-color: #508abb;
			color: #FFFFFF;
			border-color: #6ea1cc !important;
			text-transform: uppercase;
		}
		</style>
		</table>
</body>
</html>
<?php 
echo '<table class="data-table">
        <tr class="data-heading">'; 
while ($property = mysqli_fetch_field($result)) {
    echo '<td>' . $property->name . '</td>'; 
    array_push($all_property, $property->name);  
}
echo '</tr>'; 

while ($row = mysqli_fetch_array($result)) {
    echo "<tr>";
    foreach ($all_property as $item) {
        echo '<td>' . $row[$item] . '</td>'; 
    }
    echo '</tr>';
}
echo "</table>";
?>