#ifndef __ITEM__
#define __ITEM__

#include <stdint.h>


// Macros

#define key(A) (A->key)
#define less(A, B) (A < B) 
#define equal(A, B) (A == B)

// Estrutura

typedef UINT32_MAX Key;

typedef struct product {
	unsigned int key, stock;
} *Item;

// Prototipos

Item newItem(unsigned int key, unsigned int stock);
void freeItem(Item item);
void addItemStock(Item item, int value);
#endif 
