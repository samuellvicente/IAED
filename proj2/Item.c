#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "Item.h"
#include "math.h"
 
Item newItem(Key key, Stock stock) {
	Item new = (Item)malloc(sizeof(struct product));
	new->key = key;
	new->stock = stock;
	return new;
}

Item createNewItem (Key key, long stock) {
	if (stock < 0)	return newItem(key, 0);
	else			return newItem(key, (Stock) stock);
}

void freeItem(Item item) {
	free(item);
}

void addItemStock(Item item, long value) { 
	long long v = item->stock + value;
	// determina o valor maximo passivel de ser armazenado num tipo Stock 
	Stock max_value_stock = (Stock)(pow(2, 8 * sizeof(Stock)) - 1);
	if (v < 0)							item->stock = 0;
	else if (v < max_value_stock)		item->stock = v;
	// previne overflow
	else								item->stock = max_value_stock;
}

void printItem(Item item) {
	printf("%08" PRIx32 " %u\n", item->key, item->stock);
}

Key scanKey() {
	Key a;
	scanf("%" PRIx32, &a);
	return a;
}

Stock scanStock() {
	Stock a;
	scanf("%u", &a);
	return a;
}
