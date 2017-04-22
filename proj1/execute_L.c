#include <stdio.h>
#include "header.h"

void execute_L(){
    unsigned short a;

    printf("*TOTAL MESSAGES:%hu\n", total_msg);
    for(a = 0; message_list[a].message[0] != '\0'; printf("%s\n", message_list[a++].message));
}
