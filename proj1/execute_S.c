#include <stdio.h>
#include <string.h>
#include "header.h"

void execute_S(){
    for(int a = 0; a < MAX_MSG; index_copy[a] = a, a++); // cria copia de index do vector das mensagens REVER!!!!!

    quicksort(index_copy, 0, total_msg - 1, message_list);

    for(int a = 0; a < total_msg; printf("%s\n", message_list[index_copy[a++]].message));
}
