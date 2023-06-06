#include <stdio.h>
#include <stdlib.h>
main() {
	int n1, n2, t;
	printf("Digite um valor para o numero 1: "); scanf("%i", &n1);
	printf("Digite um valor para o numero 2: "); scanf("%i", &n2);
	t = n1 + n2;
	printf("Total: %i ", t);
	if(t > 10) {
		printf("\nTotal maior que 10");
	} else {
		printf("\nTotal menor ou igual a 10");
	}
}
