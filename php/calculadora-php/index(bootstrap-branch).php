
<!DOCTYPE html>
<html>

<head>
	<!-- <link rel='stylesheet' href='.\index.css'> -->
	<title>calculadora</title>
	<?php include '.\modulos\bootstrap.html' ?>
</head>

<body>
	<?php
	include '.\modulos\lib.php';
	$x = isset($_GET['x']) ? $_GET['x'] : 0;
	$y = isset($_GET['y']) ? $_GET['y'] : 0;
	$o = isset($_GET['op']) ? $_GET['op'] : 0;
	?>
	<!-- <h1>alexsander</h1> -->
	<!-- <div class='container'> -->
	<div class='row'>
		<div class='col'>
			<input class='form-control bg-primary-subtle' type='number' step='0.001' value='1' />
		</div>
	</div>
	<div class='row'>
		<div class='col'>
			<input class='form-control bg-primary-subtle' value='soma' />
		</div>
	</div>
	<div class='row'>
		<div class='col'>
			<input class='form-control bg-primary-subtle' type='number' step='0.001' value='2' />
		</div>
	</div>
	<div class='row'>
		<div class='col'>
			<input class='btn btn-primary' type='button' value='enviar' />
		</div>
	</div>
	<!-- </div> -->

	<!-- <form id='formulario' class='container' method='get'> -->
	<!-- <div id='caixa' class='col'> -->

	<!-- <div id='entrada_x' class='col'>
		<input id='numero_x' class='form-control' name='x' type='number' step='0.001' value=<?php echo $x ?>>
	</div>

	<div id='opcao_controle' class='col'>
		<select id='operacao' class='form-select' name='op'>
			<option <?php if ($o == 1) {
				echo 'selected';
			}
			; ?> value='1'>soma</option>
			<option <?php if ($o == 2) {
				echo 'selected';
			}
			; ?> value='2'>subtração</option>
			<option <?php if ($o == 3) {
				echo 'selected';
			}
			; ?> value='3'>multiplicação</option>
			<option <?php if ($o == 4) {
				echo 'selected';
			}
			; ?> value='4'>divisão</option>
		</select>
	</div>

	<div id='entrada-y' class='col'>
		<input id='numero_y' class='form-control' name='y' type='number' step='0.001' value='<?php echo $y ?>'>
	</div>

	<!-x- </div> -x->

	<!-x- </form> -x->
	</div>
	<div id='saida' class='row'>
		<div class='col-6'>
			<div class='form-text'>resultado ->
				<?php echo calcular($x, $y, $o); ?>
			</div> <!-- <output name='res' for='numero_x numero_y'></output> -x->
		</div>
	</div>

	<div id='botoes' class='row'>
		<div class='col-4'>
			<input type='submit' class='btn btn-primary'>
		</div>
	</div>
	</div> -->
</body>

</html>
