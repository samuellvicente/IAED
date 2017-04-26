#include <stdio.h>
#include <string.h>
#include "header.h"

void execute_S() {
    unsigned int a;

    for(a = 0; a < total_msg; index_copy[a] = a, a++); // cria copia de index do vector das mensagens

    quicksort(index_copy, 0, total_msg - 1);

    printf("*SORTED MESSAGES:%u\n", total_msg);
    for(a = 0; a < total_msg; printf("%hu:%s\n",message_list[index_copy[a]].user_id, message_list[index_copy[a]].message), a++);
}
