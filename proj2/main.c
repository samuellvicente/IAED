// Samuel Vicente	87704
// Rafael Branco	87698
// tg026			20.05.2017

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "header.h" 
#include "Item.h"
#include "avl.h"

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

	// Procura key na arvore
	Item a = avlSearch(root, key);

	// Caso encontre
	if (a != NULL) { 
		addItemStock(a, stock);

		// Se subtrair ao max_item nao podemos garantir a sua integridade
		if (stock < 0 && max_item == a)
			max_item = NULL;
		// Casos abaixo garante que "a" sera o novo max_item
		else if (max_item != NULL && 
				(less(stock(max_item), stock(a)) || (equal(stock(max_item), stock(a)) && less(key(a), key(max_item))))) 
			max_item = a;
	}
	// Caso nao encontre
	else {
		a = createNewItem(key, stock);

		// Casos abaixo garantem que "a" sera o novo max_item
		if (root == NULL
		|| (root != NULL && max_item != NULL && (less(stock(max_item), stock(a)) 
		|| (equal(stock(max_item), stock(a)) && less(key(a), key(max_item))))))
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

	// Se o maior for removido nao sabemos qual e' o novo max_item
	if (max_item != NULL && equal(key(max_item), key)) 
		max_item = NULL;
	
	avlDelete(&root, key);
}

void executeM() {
	// Determina o max_item
	if (root == NULL)
		max_item = NULL;
	else if (max_item == NULL)
		avlSort(root, updateMax);

	// Imprime se existir
	if (max_item != NULL) 
		printItem(max_item);
}

void executeX() {
	printCounter(avlFree(&root));
}

void updateMax(Item item) {
	if((max_item != NULL && less(stock(max_item), stock(item))) || max_item == NULL)
		max_item = item;
}
