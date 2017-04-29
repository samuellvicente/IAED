#include <stdio.h>
#include "header.h"

void execute_S() {
    int index_copy[MAX_MSG];  
    unsigned int a;
    
    // inicia o vector auxiliar com os index 
    for(a = 0; a < total_msg; a++)
        index_copy[a] = a;
    
    quicksort(index_copy, 0, total_msg - 1);

    printf("*SORTED MESSAGES:%u\n", total_msg);
    for(a = 0; a < total_msg; a++)
        printf("%hu:%s\n",message_list[index_copy[a]].user_id, message_list[index_copy[a]].message);
}
