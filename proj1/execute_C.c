#include <stdio.h>
#include "header.h"

void execute_C() {
    unsigned int cnt = 0, a, i, j, slen;
    char s[MAX_FRASE + 1];

    //scanf("%s", s);
    //getchar();
    
    for(slen = 0; (s[slen] = getchar()) != '\n'; slen++); // guarda msg
    s[slen] = '\0';
	
	for(a = 0; a < total_msg; a++)
		for(i = 0; message_list[a].message[i] != '\0'; i++)
			if(wchar(message_list[a].message[i]) || i == 0) {
				for( ; wchar(message_list[a].message[i]); i++); // avanca ate encontrar um char nao branco
				if(wchar(message_list[a].message[i+slen])) {
					for(j = 0; message_list[a].message[i+j] == s[j] && s[j] != '\0'; j++);
					if(s[j] == '\0' && wchar(message_list[a].message[i+j]))
						cnt++;
				}
			}
	printf("*WORD %s:%u\n", s, cnt);
}
