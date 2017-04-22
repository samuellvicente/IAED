#include <stdio.h>
#include "header.h"

void execute_T(){
    unsigned short max_entry = user_list[0], user;  //numero de submissoes do user com mais submissoes

    for(user = 1; user < MAX_USR; max_entry < user_list[user] ? max_entry = user_list[user++] : user++);   // encontra o maior numero de submissoes
    
    for (user = 0; user < MAX_USR; user++)
        if (user_list[user] == max_entry)
            for(unsigned short i = 0; message_list[i].message[0] != '\0' && i < MAX_MSG; user == message_list[i].user_id ? printf("*MOST ACTIVE USER:%hu:%s", user, message_list[i++].message) : i++);
}
