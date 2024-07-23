<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Response</title>
</head>
<body>
	<?php 
		$log_data = array("admin"=> array("password"), "scott"=> array("tiger"), "super"=> array("idontknow"));
		if($_SERVER["REQUEST_METHOD"] == "POST")
		{
			if (isset($_POST['valid']))
			{
				if(!empty($_POST['usrname']) && !empty($_POST['pwd']))
				{
					$uid = $_POST['usrname'];
					$pwd = $_POST['pwd'];
					if (array_key_exists($uid, $log_data))
					{
						if ($log_data[$uid][0] === $pwd)
						{
							header("Location: welcome.html");
						}
						else
							header("Location: sorry.html");
					}
					else
						header("Location: sorry.html");	
				}
				else
					echo "Enter username or password!!";
			}
			elseif (isset($_POST['rst'])) 
			{
				$keys = array_keys($log_data);
				echo "<b><big>"."Before Reset"."</big></b>"."<br/>";
				for($i=0; $i < count($log_data); $i++)
				{
					echo "Username: ". $keys[$i]. "<br/>";
					echo "Password: ". $log_data[$keys[$i]][0]. "<br/>"."<br/>";
				}
				if(!empty($_POST['usrname']) && !empty($_POST['pwd']) && !empty($_POST['rstpwd']))
				{
					$uid = $_POST['usrname'];
					$pwd = $_POST['pwd'];
					if (array_key_exists($uid, $log_data))
					{
						if ($log_data[$uid][0] === $pwd)
						{
							$log_data[$uid] = array($_POST["rstpwd"]);
						}
						else
							echo "Username or password is incorrect!!";
					}
					else
						echo "Username or password is incorrect!!";	
				}
				else
					echo "Enter username or password!!";

				echo "<b><big>"."After Reset"."</big></b>"."<br/>";
				for($i=0; $i < count($log_data); $i++)
				{
					echo "Username: ". $keys[$i]. "<br/>";
					echo "Password: ". $log_data[$keys[$i]][0]. "<br/>"."<br/>";
				}
			}
		}
		
	?>
</body>
</html>