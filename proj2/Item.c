#include "Item.h"
#include <stdlib.h>
 
Item newItem(unsigned int key, unsigned int stock) {
	Item new = (Item)malloc(sizeof(Item));
	new->key = key;
	new->stock = stock;
	return new;
}


void freeItem(Item item){
	free(item);
}


short int cmpItem(Item a, Item b) {
	if (a->key > b->key) return 1;
	else if (a->key == a->key) return 0;
	return -1;
}


void addItemStock(Item item, int value){
	int v = item->stock + value;
	if (v<0) item->stock = 0;
	if (v>0) item->stock = v;
}
