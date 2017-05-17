#ifndef __ITEM__
#define __ITEM__

// Macros

#define key(A) (A->key)
#define less(A, B) (key(A) < key(B)) 
#define equal(A, B) (key(A) == key(B))

// Estrutura

typedef struct product {
	unsigned int key, stock;
} *Item;

// Prototipos

Item newItem(unsigned int key, unsigned int stock);
void freeItem(Item item);
void addItemStock(Item item, int value);

#endif 
