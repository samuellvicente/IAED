
#include <stdio.h>
//#include "header.h"
#define MAX_MSG 100
#define total_msg 10
#define less(A, B) (A < B)
#define exch(A, B) { int temp = A; A = B; B = temp; }
//void execute_S(){

int partition(int a[], int l, int r, int vector[]){
    int i = l-1;
    int j = r;
    int v = vector[a[r]];
    
    while (i < j) {
        while (less(vector[a[++i]], v));
        while (less(v, vector[a[--j]]))
            if (j == l)
                break;
        if (i < j)
            exch(a[i], a[j]);
    }

    exch(a[i], a[r]);
    return i;
}
void quicksort(int a[], int l, int r, int vector[]) {
    int i;
    
    if (r <= l)
        return;
    
    i = partition(a, l, r, vector);
    quicksort(a, l, i-1, vector);
    quicksort(a, i+1, r, vector);
}


int main() {
    static int index_cp[MAX_MSG];

    for(int a = 0; a < (total_msg); index_cp[a] = a, a++);
    int vector[10] = {2,1,5,3,4,6,9,7,8,0};
    quicksort(index_cp, 0, total_msg - 1, vector);

    for(int a = 0; a < 10; printf("%d\t%d\t%d\n",vector[index_cp[a]],vector[a], index_cp[a]), a++);
    return 0;
}
