#include <stdio.h>
#include <stdlib.h>
#include "header.h" 
#include "Item.h"
#include "avl.h"

link root;

Key total_keys = 0;
Key* p_total_keys = &total_keys;

int main() {
	char c;
	avlInit(&root);
	while (1) {
		c = getchar();
		getchar();
		switch (c) {
			case 'a':
				executeA();
				break;
			case 'l':
				//executeL();
				break;
			case 'm':
				//executeM();
				break;
			case 'r':
				//executeR();
				break;
			case 'x':
				//executeX();
				return 0;
			default:
				puts("ERRO: Comando desconhecido.");
		}
	}
	return 0;
}

void executeA() {
	Key key = scanKey();
	getchar();
	Stock stock = scanStock();
	getchar();

	Item a = avlSearch(root, key);

	if (a) 
		addItemStock(a, stock);
	else {
		avlInsert(&root, newItem(key, stock));
		*p_total_keys++;
	}
}
/*
void executeL() {
	
}*/
