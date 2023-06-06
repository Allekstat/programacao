#include <stdio.h>
#include <stdlib.h>
main() {
	char continuar = 's';
	while(continuar == 's') {
		float valor, cotacao, total;
		printf("Digite o valor a ser convertido: "); scanf("%f", &valor);
		printf("Digite o valor da cotacao do dolar: "); scanf("%f", &cotacao);
		total = valor * cotacao;
		printf("O valor convertido corresponde a: %.2f", total);
		printf("\nDeseja continuar? [s/n] "); scanf("%s", &continuar);
	}
}
