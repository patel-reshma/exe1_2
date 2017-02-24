#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*error handling routine*/
void failure(char* a)
{
    fprintf(stderr, "%s \n", a); 
    exit(1);
}

