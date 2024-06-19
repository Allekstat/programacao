#include <stdio.h>
#include <stdlib.h>
main() {
	char continuar = 's';
	while(continuar == 's') {
		float valor, cotacao, total;
		printf("Digite o valor a ser convertido em reais: $ "); scanf("%f", &valor);
		if (valor < 10) {
			printf("Nao pode converter um valor menor que $10 dolares");
		} else {
			printf("Digite o valor da cotacao do dolar: $ "); scanf("%f", &cotacao);
			total = valor * cotacao;
			printf("O valor convertido corresponde a: R$ %.2f", total);
		}
		printf("\nDeseja fazer outra conversao? [s/n] "); scanf("%s", &continuar);
		printf("\n");
	}
}
