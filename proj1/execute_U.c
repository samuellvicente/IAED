#include <stdio.h>
#include "header.h"

void execute_U(){
    unsigned short user;
    
    scanf("%hu\n", &user);

    for(unsigned int a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; message_list[a].user_id == user ? printf("%s\n", message_list[a++].message) : a++);
}
