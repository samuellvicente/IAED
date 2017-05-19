#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "avl.h"
#include "Item.h"

int height(link h) {
	if (h == NULL) return 0;
	return h->height;
}

int balanceFactor(link h) {
    if(h == NULL) return 0;
    return height(h->left) - height(h->right);
}

void updateHeight(link h) {
	int height_left = height(h->left);
	int height_right = height(h->right);
	h->height = height_left > height_right ?  height_left + 1 : height_right + 1;
}

link rotL(link h) {
	link x = h->right;
	h->right = x->left;
	x->left = h;
	updateHeight(h);
	updateHeight(x);
	return x;
}

link rotR(link h) {
	link x = h->left;
	h->left = x->right;
	x->right = h;
	updateHeight(h);
	updateHeight(x);
	return x;
}

link rotLR(link h) {
	if (h==NULL) return h;
	h->left = rotL(h->left);
	return rotR(h);
}

link rotRL(link h) {
	if (h==NULL) return h;
	h->right = rotR(h->right);
	return rotL(h);
}

link newNode(Item item, link left, link right) {
	link new = (link)malloc(sizeof(struct node));
	new->item = item;
	new->left = left;
	new->right = right;
	new->height = 1;
	return new;
}

void avlInit(link* root) {
	*root = NULL;
}

link max(link h) {
	if (h == NULL || h->right == NULL)	return h;
	else								return max(h->right);
} 

link balance(link h) {
	if (h == NULL) return h;
	int balance_factor = balanceFactor(h);
	if(balance_factor > 1) {
		if (balanceFactor(h->left) >= 0)	h = rotR(h);
		else								h = rotLR(h);
	} else if(balance_factor < -1) {
		if (balanceFactor(h->right) <= 0)	h = rotL(h);
		else								h = rotRL(h);
	} else {
		updateHeight(h);
	}
	return h; 
}

Item searchR(link h, Key v) {
	if (h == NULL)				return NULL;
	if (equal(v, key(h->item)))	return h->item;
	if (less(v, key(h->item)))	return searchR(h->left, v);
	else						return searchR(h->right, v);
} 

Item avlSearch(link root, Key v) {
	return searchR(root, v);
}

link insertR(link h, Item item) {
	if (h == NULL)						return newNode(item, NULL, NULL);
	if (less(key(item), key(h->item)))	h->left = insertR(h->left, item);
	else 								h->right = insertR(h->right, item);

	h=balance(h);
	return h; 
}

void avlInsert(link* root, Item item) {
	*root = insertR(*root, item);
}

link deleteR(link h, Key k) {
	if (h==NULL) return h;
	else if (less(k, key(h->item)))		h->left = deleteR(h->left, k);
	else if (less(key(h->item), k))		h->right = deleteR(h->right, k);
	else{
		if (h->left != NULL && h->right != NULL) {
			link aux=max(h->left);
			exchangeItem(h, aux);
			h->left = deleteR(h->left, key(aux->item));
		}
		else {
			link aux = h;
			if (h->left == NULL && h->right == NULL)	h = NULL;
			else if (h->left == NULL)					h = h->right;
			else 										h = h->left;
			freeItem(aux->item);
			free(aux);
		}
	}
	h = balance(h);
	return h;
}

void avlDelete(link* root, Key k) {
	*root = deleteR(*root, k);
}

link freeR(link h, Counter* count) {
    if (h==NULL)		return h;
    h->left = freeR(h->left, count);
    h->right = freeR(h->right, count);
	// sempre que remove node adiciona ao count
	(*count)++;
    return deleteR(h,key(h->item));
}

Counter avlFree(link* root) {
	// armazena o numero de nodes libertados da arvore
	Counter count = 0;
	*root = freeR(*root, &count);
	return count;
}

void sortR(link h, void (*visit)(Item)) {
	if (h == NULL) return;
	sortR(h->left, (*visit));
	(*visit)(h->item);
	sortR(h->right, (*visit));
}

void avlSort(link h, void (*visit)(Item)) {
	sortR(h, visit);
}

void printCounter(Counter counter) {
	printf("%" PRIx32 "\n", counter);
}

