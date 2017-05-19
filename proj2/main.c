#include <stdio.h>
#include <stdlib.h>
#include "header.h" 
#include "Item.h"
#include "avl.h"
#include <inttypes.h>

link root;

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
				executeR();
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
	}
}

void executeL() {
	avlSort(root, printItem); 	
}

void executeR() {
	Key key = scanKey();
	getchar();
	avlDelete(&root, key);

}

void executeX() {
	printCounter(avlFree(&root));
}

