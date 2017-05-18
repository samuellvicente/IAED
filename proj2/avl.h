#ifndef __AVL__
#define __AVL__

#include <stdlib.h>
#include "Item.h"

// Macros

#define exchangeItem(A, B) {Item x = A->item; A->item = B->item; B->item = x;}

// Estrutura

typedef struct node* link;

struct node {
	Item item;
	link left, right;
	int height;
};

// Variaveis

// Prototipos

int height(link h);
link rotR(link h);
link rotL(link h);
link rotLR(link h);
link rotRL(link h);
int balanceFactor(link h); // balance factor
void updateHeight(link h);
link newNode(Item item, link left, link right);
void avlInit(link* root);
void avlInsert(link* root, Item item);
void avlSearch(link root, Key v);
void avlDelete(link* root, Key k); 
void avlFree(link* root);

Item searchR(link,Item);
link insertR(link h, Item item);
link deleteR(link h,Key k);
void sort(link,void (*visit)(Item));
link freeR(link h);

#endif 
