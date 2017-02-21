#include "dec.h"
#include "enter.h"

node* enter_node()
{
    if((home = (node*)malloc(sizeof(node))) == NULL) {
        failure("memory allocation failure");
    }

    home->prev = NULL;
    home->next = NULL;

    printf("enter id:");
    scanf("%d", &home->id);
    
    count++;

    return(home);
}

void display()
{
    node* p;
    int i;

    if(head == tail && head == NULL) {
        printf("list is empty");
    } else {
        p = head;
        for(i=0; i<count; i++) {
            printf("node: %d \n", i+1);
            printf("id: %d \n", p->id);
            p = p->next;
        }
    }
}
