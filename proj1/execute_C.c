#include <stdio.h>
#include "header.h"

void execute_C() {
    unsigned int cnt = 0, a, i, j, wordlen;
    char word[MAX_FRASE + 1];
    
    //guarda padrao a procurar
    for(wordlen = 0; (word[wordlen] = getchar()) != '\n'; wordlen++);
    word[wordlen] = '\0';
	
	for(a = 0; a < total_msg; a++)
		for(i = 0; message_list[a].message[i] != '\0'; i++)
			if(wchar(message_list[a].message[i]) || i == 0) {
                // avanca na mensagem ate encontrar um caracter nao branco
				for( ; wchar(message_list[a].message[i]) && message_list[a].message[i] != '\0'; i++);
                // verifica se o tamanho da palavra encontrada e igual ao do padrao
				if(wchar(message_list[a].message[i+wordlen])) {
                    // verifica se cada letra ate ao final da palavra e igual ao padrao
					for(j = 0; message_list[a].message[i+j] == word[j] && j != wordlen; j++);
                    // chegar ao fim do padrao significa que todas as letras sao iguais
                    if(j == wordlen)
						cnt++;
				}
			}
	printf("*WORD %s:%u\n", word, cnt);
}
