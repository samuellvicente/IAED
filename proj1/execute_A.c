#include <stdio.h>
#include "header.h"

void execute_A() {
    unsigned short len_msg;
    char c;
    static unsigned int index_msg;
    
    scanf("%hu", &message_list[index_msg].user_id);
    getchar();
    
    for(len_msg = 0; (c = getchar()) != '\n'; message_list[index_msg].message[len_msg++] = c);
    message_list[index_msg].message[len_msg] = '\0';

    if(len_msg > longest_msg) 
        longest_msg = len_msg;

    message_list[index_msg].lenght_msg = len_msg;

    // incrementa o contador de submissoes do user
    ++user_list[message_list[index_msg++].user_id];

    ++total_msg;
}
