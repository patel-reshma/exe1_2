#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED

typedef struct cont{
    int id;
    struct cont *left_b, *right_b;
}node;

extern node *root;
node *new_n;

void failure();
#endif
