#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* comandos[] = {"sair", "help", "listar"};
char* descricoes[] = {
	"Finaliza o programa.",
	"Exibe todos os comandos disponíveis.",
	"Lista todos os caracteres ASCII de 0 a 255."
};
int comando_existe(char* comando) {
	int i;
	for(i = 0; i < sizeof(comandos); i++) {
		if(strcmp(comandos[i], input)) {
			return 1;
		}
	}
	return 0;
}
int comando_indice() {
	
}
int checar(char* comando) {
	if (strcmp(comando, "help") == 0) {
		return 1;
	} else if (strcmp(comando, "listar") == 0) {
		return 2;
	} else if (strcmp(comando, "sair") == 0) {
		return -1;
	} else {
		return 0;
	}
}
void funcao(int codigo) {
	int i;
	switch(codigo) {
		case 1:
			
			break;
		case 2:
			for(i = 0; i < 256; i++) {
				char ascii = i;
				printf("char[%i]  = \"%c\";\n", i, ascii);
			}
			break;
		default:;
	}
}
int main(int arguments_count, char* arguments_array[]) {
	if(arguments_count > 1) {
		funcao(checar(arguments_array[1]));
	} else {
		char input[16];
		while(checar(input) != -1) {
			printf(" > "); scanf("%s", &input);
			funcao(checar(input));
		}
	}
	return 0;
}
