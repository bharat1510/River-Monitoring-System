<?php

mysql_connect('localhost','root','')
$servername = "192.168.43.191";
$username = "root";
$password = "";
$dbname = "registration";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO store (Temperature, pH,  TDS, Turbidity)
VALUES ('$_GET(temp)' , '$_GET(ph)' , '$_GET(tds)', '$_GET(turb)')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>