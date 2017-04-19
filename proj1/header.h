#ifndef HEADER
#define HEADER
#define MAX_FRASE 140
#define MAX_USR 1000
#define MAX_MSG 10000

typedef struct msg {
    unsigned short uid; // < 1000 && >= 0
    char frase[MAX_FRASE + 1];
} Msg;

unsigned short u[MAX_USR];
Msg m[MAX_MSG];

#endif
