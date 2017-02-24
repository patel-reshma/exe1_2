#include "dec.h"
#include "sort.h"
void sort_i(node** head_ref, node* new)
{
    node* p;
    if(*head_ref == NULL || (*head_ref)->id > new->id) {
        new->next = *head_ref;
        *head_ref = new;
    } else {
        p= *head_ref;
        while(p->next != NULL && p->next->id <= new->id) {
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
}

void sort_n(node** head_ref)
{
    node* sort = NULL;
    node* p = *head_ref;
    node* nxt;

    while(p != NULL) {
        nxt = p->next;
        sort_i(&sort, p);
        p = nxt;
    }

    *head_ref = sort;
}

        
