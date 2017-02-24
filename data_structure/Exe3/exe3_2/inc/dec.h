#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 20
struct cont {               /*structure dat of node */
    int id;
    char name[MAX];
    struct cont *next; /*structure points to next node*/
};

typedef struct cont node;  
node* head;
void failure();

#endif
