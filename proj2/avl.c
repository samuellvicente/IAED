#include "avl.h"
#include "Item.h"
#include <stdlib.h>

int height(link h) {
	if (h == NULL) return 0;
	return h->height;
}

int balance(link h) {
    if(h == NULL) return 0;
    return height(h->left)-height(h->right);
}

void update_height(link h) {
	int height_left = height(h->left);
	int height_right = height(h->right);
	h->height = height_left > height_right ?  height_left + 1 : height_right + 1;
}

link rotL(link h) {
	link x = h->right;
	h->right = x->left;
	x->left = h;
	update_height(h);
	update_height(x);
	return x;
}

link rotR(link h) {
	link x = h->left;
	h->left = x->right;
	x->right = h;
	update_height(h);
	update_height(x);
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

link AVLbalance(link h) {
	if (h == NULL) return h;
	int balanceFactor = balance(h);
	if(balanceFactor > 1) {
		if (balance(h->left) >= 0)	h = rotR(h);
		else                 		h = rotLR(h);
	} else if(balanceFactor < -1) {
		if (balance(h->right) <= 0)	h = rotL(h);
		else                 		h = rotRL(h);
	} else {
		int height_left = height(h->left), height_right = height(h->right);
		h->height = height_left > height_right ?  height_left + 1 : height_right + 1;
	}
	return h; 
}

link search(link h, Item v) {
	if (h == NULL)			return NULL;
	if (equal(v, h->item))	return h;
	if (less(v, h->item))	return search(h->left, v);
	else					return search(h->right, v);
} 

link insertR(link h, Item item) {
	if (h == NULL)				return newNode(item, NULL, NULL);
	if (less(item, h->item))	h->left = insertR(h->left, item);
	else 						h->right = insertR(h->right, item);

	h=AVLbalance(h);
	return h; 
}
