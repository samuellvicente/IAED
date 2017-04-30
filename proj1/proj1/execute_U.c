#include <stdio.h>
#include "header.h"

void execute_U(){
    unsigned short user;
    unsigned int a;
    
    // guarda o user id
    scanf("%hu", &user);
    getchar();

    printf("*MESSAGES FROM USER:%hu\n", user);
    for(a = 0; a < total_msg; a++)
        if(message_list[a].user_id == user)
            printf("%s\n", message_list[a].message);
}
