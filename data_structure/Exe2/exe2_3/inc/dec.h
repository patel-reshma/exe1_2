#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/* structure contain node details */
struct cont {
    int id;
//    int key;
    struct cont* next;
    struct cont* prev;
};

typedef struct cont node;

node *home;
extern node *head, *tail ;

void failure(char*);

extern int count;

#endif
