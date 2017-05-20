#ifndef __ITEM__
#define __ITEM__

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// Macros

#define key(A) (A->key)
#define stock(A) (A->stock)
#define less(A, B) (A < B) 
#define equal(A, B) (A == B)

// Estruturas

typedef uint32_t Key;	// inteiro de 32 bits
typedef unsigned int Stock;
typedef struct product* Item;

struct product {
	Key key;
	Stock stock;
};

// Prototipos

Item newItem(Key key, Stock stock);
Item createNewItem (Key key, long stock);
void freeItem(Item item);
void addItemStock(Item item, long value);
void printItem(Item item);

Key scanKey();

Stock scanStock(); // nao usado

#endif 
