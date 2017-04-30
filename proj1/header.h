#ifndef HEADER

#define HEADER
#define MAX_FRASE 140
#define MAX_USR 1000
#define MAX_MSG 10000


// MACROS

#define exch(A, B) { int temp = A; A = B; B = temp; }
#define wchar(A) ( A == ';' || A == ',' || A == ' ' || A == '\t' || A == '.' || A == '\0' )


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
