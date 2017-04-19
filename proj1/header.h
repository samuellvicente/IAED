#ifndef HEADER
#define HEADER
#define MAX_FRASE


typedef struct msg {
    User u; // < 1000 && >= 0
    char frase[MAX_FRASE];

} Msg;

typedef struct user {
    int id; // < 1000 && >= 0
    int activity;
} User;

#endif
