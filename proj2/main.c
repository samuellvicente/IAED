#include <stdio.h>
#include <stdlib.h>
#include "header.h" 
#include "Item.h"
#include "avl.h"

link root;

Key total_keys = 0;

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
				executeL();
				break;
			case 'm':
				//executeM();
				break;
			case 'r':
				//executeR();
				break;
			case 'x':
				executeX();
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
	long stock;
	scanf("%li", &stock);
	getchar();

	Item a = avlSearch(root, key);

	if (a) 
		addItemStock(a, stock);
	else {
		avlInsert(&root, createNewItem(key, stock));
		total_keys++;
	}
}

void executeL() {
	avlSort(root, printItem); 	
}

void executeX() {
	avlFree(&root);
    printf("%u\n", total_keys);
}
