
<!DOCTYPE html>
<html>

<head>

<link rel='stylesheet' href='.\index.css'>
<title>calculadora</title>
<?php include '.\includes\bootstrap.html' ?>

</head>

<body>

<?php
include '.\includes\funcoes.php';
$x = isset($_GET['x']) ? $_GET['x'] : '';
$y = isset($_GET['y']) ? $_GET['y'] : '';
$o = isset($_GET['op']) ? $_GET['op'] : '';
?>

<h1>alexsander</h1>

<form method='get'>
	<label for='numero_x'>Número A</label>
	<input id='numero_x' name='x' type='number' step='0.001' <?php echo 'value="'.$x.'"'; ?>>
	<select id='operacao' name='op'>
		<option <?php if ($o == 1) { echo 'selected'; } ?> value='1'>soma</option>
		<option <?php if ($o == 2) { echo 'selected'; } ?> value='2'>subtração</option>
		<option <?php if ($o == 3) { echo 'selected'; } ?> value='3'>multiplicação</option>
		<option <?php if ($o == 4) { echo 'selected'; } ?> value='4'>divisão</option>
	</select>
	<input id='numero_y' name='y' type='number' step='0.001' <?php echo 'value="'.$y.'"'; ?>>
	<span>resultado -> <?php echo calcular($x, $y, $o); ?></span>
	<input type='submit'>
</form>

</body>

</html>
