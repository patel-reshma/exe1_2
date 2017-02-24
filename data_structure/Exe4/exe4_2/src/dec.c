#include <stdlib.h>
#include <stdio.h>
#include "dec.h"

node *root = NULL;

void failure(char* p)
{
    fprintf(stderr, "%s \n", p);
    exit(1);
}
