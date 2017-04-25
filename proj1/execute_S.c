#include <stdio.h>
#include <string.h>
#include "header.h"

void execute_S(){ 
    for(unsigned int a = 0; a < total_msg; index_copy[a] = a, a++); // cria copia de index do vector das mensagens

    quicksort(index_copy, 0, total_msg - 1);

    printf("*SORTED MESSAGES:%hu\n", total_msg);
    for(int a = 0; a < total_msg; printf("%hu:%s\n",message_list[index_copy[a]].user_id, message_list[index_copy[a]].message), a++);
}
