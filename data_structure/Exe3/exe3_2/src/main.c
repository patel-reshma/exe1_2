#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "dec.h"
#include "enter.h"
#include "sort.h"

void sig_handler(int signo)
{
    char ch[2];
    node* new;
    
    if (signo == SIGINT) {
        printf("Enter I to insert node.\n");
        printf("Enter E to exit handler.\n");
        printf("enter your choice : ");
        scanf("%s", ch);

        switch(ch[0]) {
            case 'I':
                insert(); 
                sort_n(&head);
                break;
            case 'E':
                break;
            default:
                break;
        }
    }
}

int main()
{
    char ch[2];
    head = enter_list();    
    
    printf("displaying nodes: \n");
    display(head);          /*to display node content*/

    sort_n(&head);          /*sort task*/

    printf("to schedule the task press Y\n");
    scanf("%s", ch);

    while(ch[0] == 'Y') {
        display_t(head);          /*display sorted list*/
        if (signal(SIGINT, sig_handler) == SIG_ERR) {
            printf("\ncan't catch SIGINT\n");
        }
        sleep(1);
    }    
}

