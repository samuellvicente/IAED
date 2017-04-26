#include <stdio.h>
#include "header.h"
void execute_U(){
    unsigned short user;
    unsigned int a;

    scanf("%hu", &user);
    getchar();

    printf("*MESSAGES FROM USER:%hu\n", user);
    for(a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; message_list[a].user_id == user ? printf("%s\n", message_list[a++].message) : a++);
}
