#include <stdio.h>
#include <string.h>
#include "header.h"
extern Msg message_list[MAX_MSG];

int partition(int a[], int l, int r) {
    int i = l-1;
    int j = r;
    //char v[MAX_FRASE + 1] = message_list[a[r]].message;  ELIMINAR O CODIGO REPETIDO
    while (i < j) { 
        while (msg_less(message_list[a[++i]], message_list[a[r]]));
        while (msg_less(message_list[a[r]], message_list[a[--j]]))
            if (j == l)
                break;
        if (i < j)
            exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

void quicksort(int a[], int l, int r) {
    int i;
    
    if (r <= l)
        return;
    
    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

unsigned short msg_less(Msg a, Msg b) {
	if (strcmp(a.message, b.message) < 0)
		return 1;
	else if (strcmp(a.message, b.message) == 0)
		return a.user_id < b.user_id ? 1 : 0;
	else
		return 0;
}
