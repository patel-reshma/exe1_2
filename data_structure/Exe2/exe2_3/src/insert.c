#include "dec.h"
#include "enter.h"
#include "insert.h"

void insert_beg()
{
    home = enter_node();

    if(head == tail && head == NULL) {
        printf("initially no node in list");
        head = tail = home;
        head->next = tail->next = NULL;
        head->prev = tail->prev = NULL;
        printf("first node inserted \n");
    } else {
        home->next = head;
        head->prev = home;
        head = home;
        head->prev = tail;
        tail->next = head;
        printf("node inserted \n");
    }
}

void insert_mid()
{
    int i, p;
    node *ptr, *prv_node;

    printf("enter point where you want to insert node:");
    scanf("%d", &p);
    home = enter_node();

    if(head == tail && head == NULL) {
        if(p == 1) {
            head = tail = home;
            head->prev = tail->prev = NULL;
            head->next = tail->next = NULL;
        } else {
            printf("linklist is empty you can't enter node at %d position \n ", p);
        }
    } else {
        if (count < p) {
            printf("link list has %d nodes entered value %d is above this limit \n", count, p);
        } else {
            ptr = head;
            for(i=1; i<=count; i++) {
                prv_node = ptr;
                ptr = ptr->next;
                if(i == p-1) {
                    prv_node->next = home;
                    home->prev = prv_node;
                    home->next = ptr;
                    ptr->prev = home;
                    printf("node inserted \n");
                    break;
                }
            }
        }
    }
}

void insert_end()
{
    home = enter_node();

    if( head == tail && head == NULL) {
        head = tail = home;
        tail->prev = head->prev = NULL;
        tail->next = head->next = NULL;
        printf("initially list is empty first node inserted \n");
    } else {
        tail->next = home;
        home->prev = tail;
        tail = home;
        head->prev = tail;
        tail->next = head;
        printf("node inserted \n");
    }
}
