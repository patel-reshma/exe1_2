#include "dec.h"
int count = 0;
node* enter_list()
{
    int i, j;
    node *p, *head;     

    printf("enter number of nodes you want:");
    scanf("%d", &i);        /*enter number of nodes in link list*/

    printf("%d \n", i);
    
    for(j=0; j<i; j++) {
        count++;
        if(j == 0) {
            if((head = (node*)malloc(sizeof(node))) == NULL) {
                failure("memory allocation failure");
            }
            p = head;
        } else {
            if((p->next = (node*)malloc(sizeof(node))) == NULL) {
                failure("memory allocation failure");
            }
            p = p->next;
        }
    
        printf("enter id:");
        scanf("%d", &p->id);

        printf("enter name:");
        scanf("%s", p->name);
    }

    p->next = NULL;
    return(head);
}

void display(node* head)
{
    node* p;
    p = head;

    do {
        printf("id = %d\t name = %s \n", p->id, p->name);
        p = p->next;
    } while(p != NULL); 
    
}


void display_t(node* head)
{
    node* p;
    int i=1;
    p = head;

    do {
        printf("task %d is executing\n", i++);
        printf("id = %d\t name = %s \n", p->id, p->name);
        p = p->next;
        sleep(1);
    } while(p != NULL); 
    
}

void insert()
{
    int pos,i;
    node *new,*current,*temp,*temp1;

    new=(node *)malloc(sizeof(node));

    printf("\nEnter the id : ");
    scanf("%d",&new->id);

    printf("\n enter name:");
    scanf("%s", new->name);

    new->next = NULL;
    st :
    printf("nEnter the position : ");
    scanf("%d",&pos);

    if(pos > (count + 1)) {
       printf("\nyour entered position is out of the range of list ");
       goto st;
       }

    if(head == NULL) {
       head = new;
       current = new;
       }
    else {
       temp = head;
             for(i = 1; i < pos-1; i++) {
             temp = temp->next;
             }
       temp1 = temp->next;
       temp->next = new;
       new->next = temp1;
       }
}

