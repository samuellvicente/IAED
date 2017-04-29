#ifndef HEADER


#define HEADER
#define MAX_FRASE 140
#define MAX_USR 1000
#define MAX_MSG 10000


#define exch(A, B) { int temp = A; A = B; B = temp; }
#define wchar(A) ( A == ';' || A == ',' || A == ' ' || A == '\t' || A == '.' || A == '\0' )
//#define wchar(A) (( A < 'a' || A > 'z' ) && ( A < 'A' || A > 'Z' ) && ( A < '0' || A > '9'))  <- decidir

// acho que fazer uma funcao e melhor pois assim n temos que usar o strcmp 2 vezes  <- decidir nao funciona also
//#define msg_less(A, B) ( strcmp(message_list[A].message,message_list[B].message) < 0 || ( strcmp(message_list[A].message,message_list[B].message) == 0 && message_list[A].user_id < message_list[B].user_id ) )


// ESTRUTURAS

typedef struct msg {
    unsigned short user_id;
    char message[MAX_FRASE + 1];
    unsigned short lenght_msg;
} Msg;


// VARIAVEIS GLOBAIS

unsigned short user_list[MAX_USR];
Msg message_list[MAX_MSG];
unsigned short longest_msg; 
unsigned int total_msg;


// PROTOTIPOS

int forum();
void execute_A(); 
void execute_L();
void execute_U();
void execute_O();
void execute_T();
void execute_S();
void quicksort(int a[], int l, int r);
unsigned short msg_less(int a, int b);
void execute_C();
void execute_X();

#endif
