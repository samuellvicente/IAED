#include <stdio.h>
#include "header.h"

void execute_C() {
    unsigned int cnt = 0, a, i, j, patternlen;
    char pattern[MAX_FRASE + 1];
    
    //guarda padrao a procurar
    for(patternlen = 0; (pattern[patternlen] = getchar()) != '\n'; patternlen++);
    pattern[patternlen] = '\0';

    // precorre vector das mensagens
    for(a = 0; a < total_msg; a++)
        // precorre a mensagem
        for(i = 0; message_list[a].message[i] != '\0'; i++)
            if(wchar(message_list[a].message[i]) || i == 0) {
                // avanca na mensagem ate encontrar um caracter nao branco
                for( ; wchar(message_list[a].message[i]) && message_list[a].message[i] != '\0'; i++);
                // verifica se o tamanho da palavra encontrada e igual ao do padrao
                if(wchar(message_list[a].message[i+patternlen])) {
                    // verifica se cada letra ate ao final da palavra e igual ao padrao
                    for(j = 0; message_list[a].message[i+j] == pattern[j] && j != patternlen; j++);
                    // chegar ao final do padrao implica a palavra ser igual
                    if(j == patternlen)
                        cnt++;
                }
            }
    printf("*WORD %s:%u\n", pattern, cnt);
}
