#include <stdio.h>
#include <string.h>
#include "header.h"

void execute_O(){
    for (unsigned short a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; strlen(message_list[a].message) == longest_msg ? printf("*LONGEST SENTENCE:%hu:%s\n", message_list[a].user_id, message_list[a].message), a++ : a++);
}
