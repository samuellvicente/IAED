#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "Item.h"
 
Item newItem(Key key, Stock stock) {
	Item new = (Item)malloc(sizeof(struct product));
	new->key = key;
	new->stock = stock;
	return new;
}

void freeItem(Item item) {
	free(item);
}

void addItemStock(Item item, long value) { //esta fdd !!!!!
	long v = item->stock + value;
	if (v < 0)	item->stock = 0;
	else		item->stock = v;
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
