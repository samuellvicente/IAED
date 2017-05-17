#include <stdlib.h>
#include "Item.h"
 
Item newItem(unsigned int key, unsigned int stock) {
	Item new = (Item)malloc(sizeof(struct product));
	new->key = key;
	new->stock = stock;
	return new;
}

void freeItem(Item item) {
	free(item);
}

void addItemStock(Item item, int value) {
	int v = item->stock + value;
	if (v<0) item->stock = 0;
	else item->stock = v;
}
