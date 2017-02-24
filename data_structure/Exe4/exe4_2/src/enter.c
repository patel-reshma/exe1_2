#include <stdio.h>
#include <stdlib.h>
#include "dec.h"
#include "enter.h"

node* temp;

node* getnode()
{
    if((temp = (node*)malloc(sizeof(node))) == NULL) {
        failure("memory allocation failure");
    }

    temp->left_b = NULL;
    temp->right_b = NULL;
    
    return temp;
}

void partition(node *root, node *new_n)
{
    if (new_n->id < root->id) {
        if (root->left_b == NULL)
            root->left_b = new_n;
        else
            partition(root->left_b, new_n);
    }

    if (new_n->id > root->id) {
        if (root->right_b == NULL)
            root->right_b = new_n;
        else
            partition(root->right_b, new_n);
    }
}

void create_node()
{
    char ch;
    
    do {
        new_n = getnode();
        printf("enter node id:");
        scanf("%d", &new_n->id);

        if(root == NULL) {
            root = new_n;
        } else {
            partition(root, new_n);
        }

        printf("enter q to quit node insertion ");
        scanf(" %c", &ch);

    } while (ch != 'q');
}

void pre(node* ptr)
{
    if(ptr != NULL) {
        printf("id %d \n" , ptr->id);
        pre(ptr->left_b);
        pre(ptr->right_b);
    }
}

void inord(node* ptr)
{
    if(ptr != NULL) {
        inord(ptr->left_b);
        printf("id %d \n" , ptr->id);
        inord(ptr->right_b);
    }
}

void post(node* ptr)
{
    if(ptr != NULL) {
        post(ptr->left_b);
        post(ptr->right_b);
        printf("id %d \n" , ptr->id);
    }
}

int len(node* ptr)
{
    int left, right;
    
    if(ptr == NULL) {
        return 0;
    
    } else {

        left = len(ptr->left_b);
        right = len(ptr->right_b);

        if(left > right) {
            return (left + 1);
        } else {
            return (right + 1);
        }
    }
}

void print_node(node* ptr, int i)
{
    if (ptr == NULL) {
        return;
    }
    
    if (i == 1) {
        printf("id %d\n", ptr->id);
    } else if (i > 1) {
        print_node(ptr->left_b, i-1);
        print_node(ptr->right_b, i-1);
    }
}

void level(node* ptr)
{
    int h,i;
    h = len(ptr);

    for(i = 1; i <= h; i++) {
        print_node(ptr, i);
    }
}

