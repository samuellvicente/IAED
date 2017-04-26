#include <stdio.h>
#include "header.h"

void execute_T(){
    unsigned short max_entry = user_list[0], user;  //numero de submissoes do user com mais submissoes

    for(user = 1; user < MAX_USR; max_entry < user_list[user] ? max_entry = user_list[user++] : user++);   // encontra o maior numero de submissoes
    
    for(user = 0; user < MAX_USR; user_list[user] == max_entry ? printf("*MOST ACTIVE USER:%hu:%hu\n",user, user_list[user]), user++ : user ++);

}

