#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int forum() {
    char command;
    while (1) {
            command = getchar(); // le o comando
            getchar();
            switch (command) {
                case 'A':
                    execute_A();  // executa a funcao responsavel por processar o comando 'A'
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'L':
                    //getchar();    // elimina '\n'
                    execute_L();  // executa a funcao responsavel por processar o comando 'L'
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'U':
                    execute_U();  // executa a funcao responsavel por processar o comando 'U'
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'O':
                    //getchar();
                    execute_O();  // executa a funcao responsavel por processar o comando 'O' 
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'T':
                    //getchar();
                    execute_T();  // executa a funcao responsavel por processar o comando 'T' 
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'S':
                    //getchar();    // elimina \n
                    execute_S();  // executa a funcao responsavel por processar o comando 'S'
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'C':
                    execute_C();  // executa a funcao responsavel por processar o comando 'C'
                    break;        // caso execute sai do loop para procurar o proximo comando
                case 'X':
                    execute_X();  // executa a funcao responsavel por processar o comando 'X' 
                    return EXIT_SUCCESS;  //sai do programa com sucesso
                default:
                    puts("ERRO: Comando desconhecido"); // caso o comando nao seja reconhecido imprime na consola uma mensagem de erro
            }
    }
    return EXIT_FAILURE; // sai do programa com algo que correu mal
}

