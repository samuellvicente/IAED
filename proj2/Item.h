#ifndef __ITEM__
#define __ITEM__

#include <stdint.h>

// Macros

#define key(A) (A->key)
#define less(A, B) (A < B) 
#define equal(A, B) (A == B)

// Estrutura

typedef uint32_t Key;
typedef unsigned int Stock;
typedef struct product* Item;

struct product {
	Key key;
	Stock stock;
};

// Prototipos

Item newItem(Key key, Stock stock);
void freeItem(Item item);
void addItemStock(Item item, int value);
void printItem(Item);

Key scanKey();
Stock scanStock();

#endif 

