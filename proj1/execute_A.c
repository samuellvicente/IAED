#include <stdio.h>
#include "header.h"

void execute_A() {
    unsigned short a;
    char c;

    scanf("%hu", &message_list[index_msg].user_id); // guarda user_id
    getchar();

    for(a = 0; (c = getchar()) != '\n'; message_list[index_msg].message[a++] = c); // guarda msg
    message_list[index_msg].message[a] = '\0';

    if(a > longest_msg) // atualiza longest_msg
        longest_msg = a;

    ++user_list[message_list[index_msg++].user_id];
}
