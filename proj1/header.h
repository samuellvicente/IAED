#ifndef HEADER

#define HEADER
#define MAX_FRASE 140
#define MAX_USR 1000
#define MAX_MSG 10000

#define exch(A, B) { int temp = A; A = B; B = temp; }
#define wchar(A) ( A == ';' || A == ',' || A == ' ' || A == '\t' || A == '.' || A == '\0' )//(( A < 'a' || A > 'z' ) && ( A < 'A' || A > 'Z' ) && ( A < '0' || A > '9'))

// ESTRUTURAS

typedef struct msg {
    unsigned short user_id; // < 1000 && >= 0
    char message[MAX_FRASE + 1];
} Msg;

// VARIAVEIS GLOBAIS

unsigned short user_list[MAX_USR];
Msg message_list[MAX_MSG];
unsigned short longest_msg; // guarda o tamanho da maior msg
unsigned int index_msg; // posicao no vetor da ultima msg
unsigned int total_msg; // numero total de mensagens
int index_copy[MAX_MSG];  //rever !!!!

// PROTOTIPOS

int forum();
void execute_A(); 
void execute_L();
void execute_U();
void execute_O();
void execute_T();
void execute_S();
void quicksort(int a[], int l, int r);
void execute_C();
void execute_X();
unsigned short msg_less(Msg a, Msg b);

#endif
