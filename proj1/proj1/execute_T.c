#include <stdio.h>
#include "header.h"

void execute_T(){
    unsigned short max_entry = user_list[0], user; 
    
    // encontra o maior numero de submissoes
    for(user = 1; user < MAX_USR; user++)
        if(max_entry < user_list[user])
            max_entry = user_list[user];
    
    for(user = 0; user < MAX_USR; user ++)
        if(user_list[user] == max_entry)
            printf("*MOST ACTIVE USER:%hu:%hu\n",user, user_list[user]);

}

