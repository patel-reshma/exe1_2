#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

struct cont {               /*structure dat of node */
    int id;
    char name[MAX];
    struct cont *next_node; /*structure points to next node*/
};

typedef struct cont node;  

node* enter_list();         /*to enter node details*/

void display(node*);        /*to print content of node*/

node* reverse();
/*error handling routine*/
void failure(char* a)
{
    fprintf(stderr, "%s \n", a); 
    exit(1);
}

int main()
{

    node* head;             /*head pointer of link list*/
    
    head = enter_list();    
    display(head);          /*to display node content*/

    head = reverse();
}

node* enter_list()
{
    int i, j;
    node *p, *head;     

    printf("enter number of nodes you want:");
    scanf("%d", &i);        /*enter number of nodes in link list*/

    printf("%d \n", i);
    
    for(j=0; j<i; j++) {
        if(j == 0) {
            if((head = (node*)malloc(sizeof(node))) == NULL) {
                failure("memory allocation failure");
            }
            p = head;
        } else {
            if((p->next_node = (node*)malloc(sizeof(node))) == NULL) {
                failure("memory allocation failure");
            }
            p = p->next_node;
        }
    
        printf("enter id:");
        scanf("%d", &p->id);

        printf("enter name:");
        scanf("%s", p->name);
    }

    p->next_node = NULL;
    return(head);
}

void display(node* head)
{
    node* p;
    p = head;

    do {
        printf("id = %d \nname = %s \n", p->id, p->name);
        p = p->next_node;
    } while(p != NULL); 
    
}


