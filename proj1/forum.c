#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int forum() {
    char command;
    while(1) {
            command = getchar(); 
            getchar();
            switch(command) {
                case 'A':
                    execute_A();
                    break;
                case 'L':
                    execute_L();
                    break;
                case 'U':
                    execute_U();
                    break;
                case 'O':
                    execute_O();
                    break;
                case 'T':
                    execute_T();
                    break;
                case 'S':
                    execute_S();
                    break;
                case 'C':
                    execute_C();
                    break;
                case 'X':
                    execute_X(); 
                    return EXIT_SUCCESS;
                default:
                    puts("ERRO: Comando desconhecido"); // caso o comando nao seja reconhecido imprime na consola uma mensagem de erro
            }
    }
    return EXIT_FAILURE;
}

