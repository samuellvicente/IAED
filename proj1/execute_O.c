#include <stdio.h>
#include <string.h>
#include "header.h"

void execute_O(){
    unsigned int a;

    for (a = 0; a < total_msg; a++)
        if(message_list[a].lenght_msg == longest_msg)
            printf("*LONGEST SENTENCE:%hu:%s\n", message_list[a].user_id, message_list[a].message);
}
