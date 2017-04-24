#include <stdio.h>
#include <string.h>
#include "header.h"
extern Msg message_list[MAX_MSG];

int partition(int a[], int l, int r) {
    int c;
    int i = l-1;
    int j = r;
    //char v[MAX_FRASE + 1] = message_list[a[r]].message;
    while (i < j) { 
        while ((c = strcmp(message_list[a[++i]].message, message_list[a[r]].message)) < 0);
        while ((c = strcmp(message_list[a[r]].message, message_list[a[--j]].message)) < 0)
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


