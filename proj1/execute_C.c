#include <stdio.h>
#include "header.h"

#define wchar(A) (( A < 'a' || A > 'z' ) && ( A < 'A' || A > 'Z' ))

void execute_C(){
    unsigned int cnt = 0, a, i, j;
    char s[MAX_FRASE + 1];

    scanf("%s\n", &s);
    
    for(a = 0; message_list[a].message[0] != '\0' && a < MAX_MSG; a++)
        for(i = 0; message_list[a].message[i] != '\0'; i++)
            if(wchar(message_list[a].message[i]) || i == 0) {
                for(j = 0; message_list[a].message[i+j] == s[j]; j++);
                if(s[j] == '\0' && wchar(message_list[a].message[i]))
                    cnt++;
            }
    printf("%d", cnt);
}
