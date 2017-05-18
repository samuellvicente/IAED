#include <stdio.h>
#include <stdlib.h>
#include "header.h" 
int main() {
	char c;
	while (1) {
		c = getchar();
		getchar();
		switch (c) {
			case 'a':
				execute_a();	
				break;
			case 'l':
				execute_l();
				break;
			case 'm':
				execute_m();
				break;
			case 'r':
				execute_r();
				break;
			case 'x':
				execute_x();
				return 0;
			default:
				puts("ERRO: Comando desconhecido.");
		}
	}
	return 0;
}
