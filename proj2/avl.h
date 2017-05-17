#ifndef __AVL__
#define __AVL__

#include <stdlib.h>
#include "Item.h"

// Macros

#define updateHeight(A) (A->left > A->right ? A->left++ : A->right++)
#define exchangeItem(A, B) {Item x = A->item; A->item = B->item; B->item = x;}

// Estrutura

typedef struct node* link;

struct node {
	Item item;
	link left, right;
	int height;
};

// Variaveis

static link root = NULL;

// Prototipos

int height(link h);
link rotR(link h);
link rotL(link h);
link rotLR(link h);
link rotRL(link h);
int balance(link h); // balance factor
void update_height(link h);
link newNode(Item item, link left, link right);

Item AVLsearch(link,Item);
void AVLinsert(link*,Item);
link AVLdelete(link,Key);
void AVLsort(link,void (*visit)(Item));
void AVLfree(link*);

#endif 