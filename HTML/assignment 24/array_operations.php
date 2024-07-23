<?php
// Initial array
$colors = [
    5 => 'yellow',
    14 => 'blue',
    3 => 'green',
    22 => 'white'
];

// Store original array for display
$original_colors = $colors;

// Get the first element of the array
$first_element = reset($colors);

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['insert'])) {
        // Get new item position, code and value from the form
        $new_item_position = (int)$_POST['new_item_position'];
        $new_color_code = (int)$_POST['new_color_code'];
        $new_color_name = $_POST['new_color_name'];

        // Insert new item at specified position
        $colors[$new_color_code] = $new_color_name;
        ksort($colors); // Sort array by keys to maintain order
    }

    if (isset($_POST['delete'])) {
        // Delete the last item
        array_pop($colors);
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Array Operations Result</title>
</head>
<body>
    <h2>Array Operations Result</h2>
    <p><strong>First element of the array:</strong> <?php echo $first_element; ?></p>
    <p><strong>Original array:</strong></p>
    <ul>
        <?php
        foreach ($original_colors as $key => $value) {
            echo "<li>Colour code: $key, Colour name: $value</li>";
        }
        ?>
    </ul>
    <p><strong>Changed array:</strong></p>
    <ul>
        <?php
        foreach ($colors as $key => $value) {
            echo "<li>Colour code: $key, Colour name: $value</li>";
        }
        ?>
    </ul>
    <a href="index.html">Back to form</a>
</body>
</html>
