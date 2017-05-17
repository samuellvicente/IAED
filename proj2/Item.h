#ifndef __ITEM__
#define __ITEM__

// Estrutura

typedef struct product {
	unsigned int key, stock;
} *Item;

// Prototipos

Item newItem(unsigned int key, unsigned int stock);
void freeItem(Item item);
short int cmpItem(Item a, Item b);
void addItemStock(Item item, int value);

#endif 
