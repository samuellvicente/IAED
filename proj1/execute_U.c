#include <stdio.h>
#include "header.h"

void execute_U(){
    unsigned short user, a;
    
    scanf("%hu", &user);

    for(a = 0; message_list[a].message[0] != '\0'; message_list[a].user_id == user ? printf("%s\n", message_list[a++].message) : a++);
}
