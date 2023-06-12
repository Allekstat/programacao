#include <stdio.h>
#include <string.h>
int main(int arguments_count, char* arguments_array[]) {
	if(arguments_count > 1) {
		if (strcmp(arguments_array[1], "list") == 0) {
			int i;
			for(i = 0; i < 256; i++) {
				char ascii = i;
				printf("char[%i]  = \"%c\";\n", i, ascii);
			}
		}
	}
	return 0;
}
