<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $username = $_POST['login'];
    $password = $_POST['password'];


    if ($username === "Calcutta" && $password === "University") {
 
        header("Location: welcome.html");
        exit;
    } else {

        header("Location: sorry.html");
        exit;
    }
}
?>
