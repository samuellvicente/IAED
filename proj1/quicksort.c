#include <stdio.h>
#include <string.h>
#include "header.h"

int partition(int a[], int l, int r) {
    int i = l-1;
    int j = r;
    int v = a[r];

    while(i < j) {
        while(msg_less(a[++i], v));
        while(msg_less(v, a[--j]))
            if(j == l)
                break;
        if(i < j)
            exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

void quicksort(int a[], int l, int r) {
    int i;
    
    if(r <= l)
        return;
    
    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}


unsigned short msg_less(int a, int b) {
    short r = strcmp(message_list[a].message,message_list[b].message);

	return ( r < 0 || ( r == 0 && message_list[a].user_id < message_list[b].user_id ));
}
