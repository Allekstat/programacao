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
		if(strcmp(comandos[i], comando) == 0) {
			if(i < 1) {
				return i - 1;
			} else {
				return i;
			}
		}
	}
	return 0;
}

// int comando_indice() {}

// int checar(char* comando) {
// 	if (strcmp(comando, "sair") == 0) {
// 		return -1;
// 	} else if (strcmp(comando, "help") == 0) {
// 		return 1;
// 	} else if (strcmp(comando, "listar") == 0) {
// 		return 2;
// 	} else {
// 		return 0;
// 	}
// }

void comando_funcao(int codigo) {
	int i;
	switch(codigo) {
		case -1:
			exit();
			break;
		case 1:
			for(i = 0; i < sizeof(comandos); i++) {
				printf(" < %s", comandos[i]);
				printf(" \t\t\t %s", descricoes[i]);
			}
			break;
		case 2:
			for(i = 0; i < 256; i++) {
				char ascii = i;
				printf(" < char[%i]  = \"%c\";\n", i, ascii);
			}
			break;
		default:;
	}
}
int main(int arguments_count, char* arguments_array[]) {
	if(arguments_count > 1) {
		comando_funcao(comando_existe(arguments_array[1]));
	} else {
		char input[16];
		while(comando_existe(input) != -1) {
			printf(" > "); scanf("%s", &input);
			comando_funcao(comando_existe(input));
		}
	}
	return 0;
}
