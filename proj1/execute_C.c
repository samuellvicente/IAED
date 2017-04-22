#include <stdio.h>
#include "header.h"

void execute_C(){
    unsigned int cnt = 0, a, i, j;
    char s[MAX_FRASE + 1];

    scanf("%s\n", &s);
    
    for(a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; a++)
        for(i = 0; message_list[a].message[i] != '\0'; i++)
            if(message_list[a].message[i] < 'a' || message_list[a].message[i] > 'z' && message_list[a].message[i] < 'A' || message_list[a].message[i] > 'Z' || i == 0) {
                for(j = 0; message_list[a].message[i+j] == s[j]; j++);
                if(s[j] == '\0' && (message_list[a].message[i] < 'a' || message_list[a].message[i] > 'z' && message_list[a].message[i] < 'A' || message_list[a].message[i] > 'Z'))
                    cnt++;
            }
    printf("%d", cnt);
}
