//#include <stdio.h>
//#include <stdlib.h>
#include "dec.h"
#include "enter.h"
#include "insert.h"
#include "delete.h"

int main()
{
    char ch[2],t;
   while(1){ 
    printf("enter B to insert at beginning \n");
    printf("enter M to insert node in middle \n");
    printf("enter L to insert node at the end \n");
    printf("enter R to delete node\n");
    printf("enter D to display list \n");
    printf("enter E to exit \n");
    scanf("%s", ch);

    switch(ch[0]) {
        case 'B':
            insert_beg();
            break;
        case 'M':
            insert_mid();
            break;
        case 'L':
            insert_end();
            break;
        case 'R':
            del();
            break;
        case 'D':
            display();
            break;
        case 'E':
            exit(0);
        default:
            printf("enter valid character \n");
            break;
        } 
    }
}

