#include <stdio.h>

main () {
	int ac, ma, te, ta, t;
	char* m;
	printf("Digite a quantidade de acertos concretos: "); scanf("%i", &ac);
	printf("Digite a quantidade de meios acertos: "); scanf("%i", &ma);
	printf("Digite a quantidade de erros: "); scanf("%i", &te);
	
	ta = ac + ma / 2;
	t = ta - te;
	
	printf("Vo%c%c teve um total de: %i", (char)135, (char)136, t);
	
	if(t > 10) {
		m = "MB";
	} else if(t > 5) {
		m = "B";
	} else if(t > -4) {
		m = "R";
	} else {
		m = "I";
	}
	printf("\nSua nota %c: %s", (char)130, m);
}
