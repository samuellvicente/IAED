#include <stdio.h>
#include "header.h"

void execute_L(){
    unsigned int a; 
    printf("*TOTAL MESSAGES:%u\n", total_msg);
    for(a = 0; a < total_msg; printf("%hu:%s\n", message_list[a].user_id, message_list[a].message), a++);
}
