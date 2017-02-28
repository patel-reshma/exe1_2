/************************************************************************************************
					includes
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*************************************************************************************************
 * Structures
 *************************************************************************************************/
typedef struct node_type{
    int data;
    struct node_type *next;
}node;     

extern int count; 

void failure(char*);

int Initlinklist(void **first, void** end, int maxSize, int flag);

int Displaylist (void *rear);

int InsertNode(void** front, void **rear, int value, int flag);

int InsertNodeat(void** front, void** rear, int value, int pos);

int DeleteNode(void ** rear);

int DeleteNodeFrom (void** rear, int pos);

int SortList(void** rear);

int SearchData (void **rear, int data);

int ReverseList(void ** rear);

int getListSize (void **rear, int *length);

int deletelist(void** rear);


