#ifndef __MAIN__
#define __MAIN__

#include <stdlib.h>
#include "Item.h"
#include "avl.h"

// VARIAVEIS GLOBAIS

Item max_item = NULL;
link root;

// PROTOTIPOS

void executeA(); 
void executeL();
void executeM();
void executeR();
void executeX();
void updateMax(Item item);

#endif

