#include <stdlib.h>
#include <stdio.h>

#include "dec.h"
#include "enter.h"
#include "search.h"

node* search(node* ptr, int n, node** head)
{
    node* temp;
    temp = ptr;

    while(temp != NULL) {
        if(temp->id == n) {
            printf("%d id present\n", temp->id);
            return temp;
        }
        *head = temp;

        if(temp->id > n) {
            temp = temp->left_b;
        } else {
            temp = temp->right_b;
        }
    }
    return NULL;
}
