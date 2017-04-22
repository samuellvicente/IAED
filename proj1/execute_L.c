#include <stdio.h>
#include "header.h"

void execute_L(){
    printf("*TOTAL MESSAGES:%hu\n", total_msg);

    for(unsigned short a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; printf("%hu:%s\n", message_list[a].user_id, message_list[a].message), a++);
}
