#ifndef HEADER
#define HEADER
#define MAX_FRASE 140
#define MAX_USR 1000
#define MAX_MSG 10000

// ESTRUTURAS

typedef struct msg {
    unsigned short sender_id; // < 1000 && >= 0
    char message[MAX_FRASE + 1];
} Msg;


// VARIAVEIS UNIVERSAIS

unsigned short user_list[MAX_USR];
Msg message_list[MAX_MSG];


// PROTOTIPOS #####CHECKAR SE SAO REALMENTE TODAS VOID OU NAO##### 


int forum();
    void execute_A(); 
    void execute_L();
    void execute_U();
    void execute_O();
    void execute_T();
    void execute_S();
    void execute_C();
    void execute_X();


#endif