/******************************************************************************
 *	Includes
 ******************************************************************************/
#include "library.h"
/*****************************************************************************
 * 	Defines
 *****************************************************************************/
int count = 0;

/**************************************************************************
* function to display error message on any error
**************************************************************************/
void failure (char* p)
{
    fprintf(stderr,"%s \n", p);
    exit(1);
}

int Initlinklist(void **first, void **end, int maxSize, int flag)
{
    node *temp = NULL, *front = NULL;
    int value;
        
	while (count < maxSize) {
		printf("Enter values to store in list \n");
		scanf("%d", &value);
		
        front = *first;
        if((temp = (node*)malloc(sizeof(node))) == NULL) {
            failure("memory allocation failure");
        }

        temp->data = value;
        count++;
        
        if (front == NULL) {
            front = temp;
            front->next = NULL;
            *end = front;
        } else if (flag == 1) {
            front->next = temp;
            front = temp;
            front->next = NULL;
        } else {
            temp->next = *end;
            *end = temp;
        }
    	*first = front;
    }
    return 0;
}

int Displaylist(void* rear)
{
    node* var = rear;
	printf("c = %d\n", count);
   
	if(count != 0) {
        while(var != NULL) {
            printf("%d \t", var->data);
            var = var->next;
        }
        
        printf("\n");

    }else 
        printf("\nQueue is Empty\n");
    
    return 0;
}


int InsertNode(void **first, void **end, int value, int flag)
{
	int ch = 0;
	int i = 0;
	node *temp, *front;

	if((temp = (node*)malloc(sizeof(node))) == NULL) {
        failure("memory allocation failure");
    }

	temp->data = value;
	
    while (i == 0)
	{
		printf("\n1. Enter value at front of queue");
		printf("\n2. Enter value at end of queue");
		printf("\n3. Exit\n");
		printf("\nChoose option:");
		scanf("%d", &ch);

		i = 0;
		
        switch (ch){
		case 1:
			front = *first;
			if (front == NULL)
			{
				front = temp;
				front->next = NULL;
				*first = front;
				*end = front;
			}
			else if (flag == 1)
			{
				temp->next = *end;
				*end = temp;
			}
			else
			{
				temp->next = *end;
				*end = temp;
			}
			count++;
			i++;
			break;

		case 2:
			front = *first;
			if (front == NULL)
			{
				front = temp;
				front->next = NULL;
				*end = front;
			}
			else if (flag == 1)
			{
				front->next = temp;
				front = temp;
				front->next = NULL;
			}
			else
			{
				temp->next = *end;
				*end = temp;
			}
			*first = front;
            count++;
			i++;
			break;

		case 3:
			exit(0);
		default:
			printf("\nwrong choice for operation");
            break;
		}
	}
	return 0;
}

int InsertNodeat(void **first, void **end, int value, int pos)
{
	int i = 0;
    node* new;
    
    if((new = (node*)malloc(sizeof(node))) == NULL) {
        failure("memory allocation failure");
    }

    new->data = value;
    
    if (*end  == NULL && *first == NULL) {
        new->next = NULL;
        *end = new;
        *first = new;
		count++;

        return 0;
    
    } else if (pos == 1) {
		new->next = *first;
        *first = new;
		count++;
    
        return 0;
    }

    node *temp = NULL, *prev = NULL;
    temp = *end;
        
    while(temp != NULL && i < (pos - 1)) {
            prev = temp;
            temp = temp->next;
            i++;
    }
    
    if(temp == NULL) {  
        prev->next = new;
        new->next = NULL;
		count++;        
	} else {
		prev->next  = new;
        new->next  = temp;
		count++;
    }            
    return 0;
}

int DeleteNode(void ** end)
{
    node* var = *end;
    if(count == 0) {
        printf("list empty\n");
        return 0;
    }
    else if (var-> next == NULL) {
        free(var);
        *end  = NULL;
		
        printf("Node delete successfully\n");
        return 0;
    } else {
        node* temp;
        temp = *end;
        temp = temp->next;
        *end = temp;
        free(var);
    }
	count--;
	printf("Node delete successfully\n");
	return 0;
}

int DeleteNodeFrom( void **end, int pos )
{
    node* var = *end;
    if (var == NULL) {
        printf("Empty list\n");
        return 0;
    } else if (pos == 1) {
        node* temp;
        temp = *end;
        temp = temp -> next;
        *end = temp;
        free(var);
        printf("Node delete successfully\n");
		count--;
        return 0;
    } else {
        node *ptr, *prev;
        ptr = *end;
        int index = 0;
        while(index  < (pos -1)) {
            prev = ptr;
            ptr = ptr->next;
            index++;
            if(ptr == NULL) {
                printf("can not delete node\n");
                return 0;
            }
        }
        prev->next = ptr->next;
        free( ptr );
		count--;
        printf("Node deleted successfully\n");
    }
    return 0;
}

int SortList(void **end)
{
    int swapped;
    node* ptr1;
    node* LastPtr = NULL;
    
    do {
        swapped = 0;
        ptr1 = *end;

        while (ptr1->next != LastPtr) {
    
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        LastPtr = ptr1;
    } while (swapped);
    
    printf("sorting done\n");
    
    return 0;
}

int SearchData (void **rear, int data)
{
    int flag = 0;
    if (*rear  == NULL) {
        printf("Empty Link list\n");
        return 0;
    } else {  
		node* ptr = NULL; 
        int number = 0;
        ptr = *rear;
        while (ptr != NULL) {
            number++;
            if (data == ptr->data) {
                printf("Value found at position %d\n", number);
                flag = 1;
            }
            ptr = ptr->next;
        }
    }

    if (!flag)
        printf("Value is not found in Linklist\n");
	
    return 0;
}  

int ReverseList(void **rear)
{
    node* head = *rear;

    if (head == NULL || head->next  == NULL) {
        *rear = head;
        return 0;
    }
    
    node* temp = *rear;
    temp = temp->next;
    *rear = temp;
    ReverseList(rear);
    head->next->next = head;
    head->next = NULL;
	
    return 0;
} 

int getListSize (void **first, int *length)
{
    node* temp = *first;
    
    while(temp != NULL) {
        (*length)++;
        temp = temp->next;
    }

    return 0;
}

int deletelist (void **first)
{
    node* temp = *first;
    
    while(temp != NULL) {
        node* var = temp;
        temp = temp->next;
        free(var);
	}
	
    count = 0;
    return 0;
}
