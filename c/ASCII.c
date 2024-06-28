#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* comandos[3] = {"sair", "help", "listar"};

char* descricoes[3] = {
	"Finaliza o programa.",
	"Exibe todos os comandos disponiveis.",
	"Lista todos os caracteres ASCII de 0 a 255."
};

int comando_existe(char* comando) {
	int i;
	for(i = 0; i < sizeof(comandos) / 8; i++) {
		if(strcmp(comandos[i], comando) == 0) {
			if(i == 0) {
				return -1;
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
	if(codigo == -1) {//sair
		exit(0);
	} else if(codigo == 1) {//help
		int i;
		for(i = 0; i < sizeof(comandos) / 8; i++) {
			printf("%s", comandos[i]);
			printf("\t%s\n", descricoes[i]);
		}
	} else if(codigo == 2) {//listar
		int i;
		for(i = 32; i < 256; i++) {
			printf("\tchar[%i]  = \"%c\";\n", i, (char) i);
		}
	}
	/*switch(codigo) {
		case -1://sair
			
			break;
		case 1://help
			//printf(" comandos[0] = %s", comandos[0]);
			//printf(" descricoes[0] = %s", descricoes[0]);
			for(i = 0; i < sizeof(comandos) / 8; i++) {
				printf("%s", comandos[i]);
				printf("\t%s\n", descricoes[i]);
			}
			break;
		case 2://listar
			printf(" < ");
			for(i = 32; i < 256; i++) {
				char ascii = i;
				printf("\tchar[%i]  = \"%c\";\n", i, ascii);
			}
			break;
		default:
			break;
	}*/
}
main(int arguments_count, char* arguments_array[]) {
	if(arguments_count > 1) {
		comando_funcao(comando_existe(arguments_array[1]));
	} else {
		char* input;
		input = "none";
		while(comando_existe(input) != -1) {
			printf(" > "); scanf("%s", &input);
			comando_funcao(comando_existe(input));
		}
	}
}
