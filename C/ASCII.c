#include <stdio.h>
int main(int arguments_count, char* arguments_array[]) {
	int i;
	for(i = 0; i < 256; i++) {
		char ascii = i;
		printf("char[%i]  = \"%c\";\n", i, ascii);
	}
	return 0;
}
