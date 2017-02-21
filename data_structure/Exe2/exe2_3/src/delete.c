#include "dec.h"
#include "enter.h"
#include "delete.h"

void del()
{
    int p, i;
    node *pt, *prv_node;

    if (head == tail && head == NULL) {
        printf("link list is empty node can't be deleted \n");
    } else {
        printf("enter node you want to delete:");
        scanf("%d", &p);
        
        if (count < p) {
            printf("no of total nodes in link list is %d ", count);
            printf("you are trying to delete node %d which is not present \n", p);
        } else {
            pt = head;
            for(i=1; i<=count; i++) {
                prv_node = pt;
                pt = pt->next;
                if (p == 1) {
                    tail->next = prv_node->next;
                    pt->prev = prv_node->prev;
                    head = pt;
                    count--;
                    free(prv_node);
                    printf("node deleted \n");
                    break;
                } else if (i = p - 1) {
                    prv_node->next = pt->next;
                    pt->next->prev = prv_node;
                    count--;
                    free(pt);
                    printf("node deleted \n");
                    break;
                }
            }
        }
    }
}
