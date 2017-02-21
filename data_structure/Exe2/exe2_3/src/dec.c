#include <stdio.h>
#include <stdlib.h>
#include "../inc/dec.h"

node* head = NULL;
node* tail = NULL;
int count = 0;
/*in case of failure*/
void failure(char* p)
{
    fprintf(stderr,"%s \n", p);
    exit(1);
}
