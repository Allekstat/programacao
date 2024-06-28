
<?php
function calcular($a, $b, $operacao)
{
	switch ($operacao) {
		case 1:
			return $a + $b;
			break;
		case 2:
			return $a - $b;
			break;
		case 3:
			return $a * $b;
			break;
		case 4:
			if ($b == 0) {
				return 'Infinity';
			} else {
				return $a / $b;
			}
			break;
		default:
			return 1 / 'x';
	}
}
