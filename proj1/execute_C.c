#include <stdio.h>
#include "header.h"

void execute_C() {
    unsigned int cnt = 0, a, i, j;
    char s[MAX_FRASE + 1];

    scanf("%s", s);
    getchar(); 

    for(a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; a++)
        for(i = 0; message_list[a].message[i] != '\0'; i++)
            if(wchar(message_list[a].message[i]) || i == 0) {
		for(; wchar(message_list[a].message[i]); i++);
                for(j = 0; message_list[a].message[i+j] == s[j] && s[j] != '\0'; j++);
                if(s[j] == '\0' && wchar(message_list[a].message[i+j]))
                    cnt++;
            }
    printf("*WORD %s:%u\n", s, cnt);
}

