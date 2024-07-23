<?php
// Predefined list of username and password pairs
$users = [
    "user1" => "password1",
    "user2" => "password2",
    "user3" => "password3"
];

// Retrieve the entered credentials from the form
$login = $_POST['login'];
$password = $_POST['password'];

// Check if the entered credentials match any entry in the associative array
if (array_key_exists($login, $users) && $users[$login] === $password) {
    // Redirect to Welcome.html for a valid match
    header("Location: welcome.html");
} else {
    // Redirect to Sorry.html for an invalid match
    header("Location: sorry.html");
}
exit();
?>
