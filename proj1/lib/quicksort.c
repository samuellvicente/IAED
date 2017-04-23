#include <stdio.h>
#include <string.h>
#include "header.h"

int partition(int a[], int l, int r, Msg msg_lst[]) {
    int c;
    int i = l-1;
    int j = r;
    //char v[MAX_FRASE + 1] = msg_lst[a[r]].message;
    while (i < j) { 
        while ((c = strcmp(msg_lst[a[++i]].message, msg_lst[a[r]].message)) < 0);
        while ((c = strcmp(msg_lst[a[r]].message, msg_lst[a[--j]].message)) < 0)
            if (j == l)
                break;
        if (i < j)
            exch(a[i], a[j]);

    }

    exch(a[i], a[r]);
    return i;
}

void quicksort(int a[], int l, int r, Msg msg_lst[]) {
    int i;
    
    if (r <= l)
        return;
    
    i = partition(a, l, r, msg_lst);
    quicksort(a, l, i-1, msg_lst);
    quicksort(a, i+1, r, msg_lst);
}


