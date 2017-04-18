#include <stdio.h>
#include <stdlib.h>


void executa_A();
void executa_B();
void executa_X();


int main() {
    char command;
    while (1) {
            command = getchar(); /* le o comando */
            switch (command) {
                case 'A':
                    executa_A(); /* Chama a funcao responsavel pela execucao do comando A */
                    break;
                case 'B':
                    executa_B() ; /* Chama a funcao responsavel pela execucao do comando B */
                    getchar(); /* Se em executa_B NAO lemos o \n, temos de o ler aqui. */
                    break;
                case 'X':
                    executa_X(); /*  Faz o que tem de fazer antes de sair */
                    return EXIT_SUCCESS; /* Termina o programa com sucesso */
                default:
                    puts("ERRO: Comando desconhecido");
            }
    }
    return EXIT_FAILURE; /* se chegou aqui algo correu mal*/
}
