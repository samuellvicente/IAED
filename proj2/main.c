#include <stdio.h>

int main() {
	char c;
	while (1) {
		c = getchar();
		getchar();
		switch (c) {
			case 'a':
				break;
			case 'l':
				break;
			case 'm':
				break;
			case 'r':
				break;
			case 'x':
				return 0;
			default:
				puts("ERRO: Comando desconhecido.");
		}
	}
	return 0;
}
