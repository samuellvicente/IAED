#include <stdio.h>
#include <stdlib.h>
#include "header.h" 
#include "Item.h"
#include "avl.h"
#include <inttypes.h>

Item max_item = NULL;

link root;

void findMax(Item item) {
	if((max_item != NULL && less(stock(max_item), stock(item))) || max_item == NULL)
		max_item = item;
}

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
				executeM();
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

	
	if (a != NULL) { 
		addItemStock(a, stock);
		if (stock < 0 && max_item == a)
			max_item = NULL;
		if (max_item != NULL && (less(stock(max_item), stock(a)) || (equal(stock(max_item), stock(a)) && less(key(a), key(max_item))))) {
			max_item = a;
		}
	}
	else {
		a = createNewItem(key, stock);
		if (root == NULL || (root != NULL && max_item != NULL && (less(stock(max_item), stock(a)) || (equal(stock(max_item), stock(a)) && less(key(a), key(max_item))))))
			max_item = a;
		avlInsert(&root, a);
	}
}

void executeL() {
	avlSort(root, printItem); 	
}

void executeR() {
	Key key = scanKey();
	getchar();
	//previne segmentation fault
	if (max_item != NULL && equal(key(max_item), key)) 
		max_item = NULL;
		// avlSort(root, findMax);
	
	avlDelete(&root, key);
}

void executeM() {
	if (root == NULL)
		max_item = NULL;
	else if (max_item == NULL)
		avlSort(root, findMax);

	if (max_item != NULL) 
		printItem(max_item);
}

void executeX() {
	printCounter(avlFree(&root));
}

