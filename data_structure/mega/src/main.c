#include "library.h"

int main()
{
    int flag = 0;
    int value, size, pos, data;
    int length = 0;
    int ch = 0;
    void* front = NULL;
    void* end = NULL;
    time_t time;

    printf("\n1. Use Library as a Queue\n");
    printf("2. Use Library as a Stack\n");
    printf("Enter the flag\n");
    scanf("%d", &flag);
 
	if (flag != 1 && flag != 2) {
            printf("Invalid choice\n");
            exit(1);
    }
    
    while(1) {
        printf(" \n 1.Create new Queue");
        printf(" \n 2.Display Data of Queue");
        printf(" \n 3.Insert node");
        printf(" \n 4.Insert node at position");
        printf(" \n 5.Delete node");
        printf(" \n 6.Delete node at position");
        printf(" \n 7.sorting the node");
        printf(" \n 8.Search the data from the list");
        printf(" \n 9.Reverse the list");
        printf(" \n10.Find the size of the list");
        printf(" \n11.Make list empty");
        printf(" \n12.Exit\n");
        printf(" \nChoose Option: ");
        scanf("%d", &ch);

        switch(ch) {
        case 1:
            printf("enter size of queue\n");
            scanf("%d", &size);

            Initlinklist(&front, &end , size, flag);
            break;                        
        
        case 2:
            Displaylist(end);
            break;
        
        case 3:
            printf("Enter the value to insert in Queue\n");
            scanf("%d", &value);
            InsertNode(&front, &end, value, flag);
            break;
        
        case 4:
            printf("Enter the value to insert in list\n");
            scanf("%d", &value);
            printf("Enter the position to insert new node\n");
            scanf("%d", &pos);
            InsertNodeat(&front, &end, value, pos);
            break;
        
        case 5:
            if(end == front)
            front = NULL;
            DeleteNode(&end);
            break;

        case 6:
            printf("Enter node position to delete the node\n");
            scanf("%d", &pos);
            DeleteNodeFrom(&end, pos);
            break;
        
        case 7:
            time = clock();
            SortList(&end);
            time = clock() - time;
            printf("Execution timing: %f seconds\n", 
				(double)(time) / CLOCKS_PER_SEC);
            break;

        case 8:
            printf("Enter Search value\n");
            scanf("%d", &data);
            SearchData (&end, data);
            break;

        case 9:
            front = end;
            ReverseList(&end);
            printf("\nData Reversed ");
            Displaylist(end);
            break;

        case 10:
            
            getListSize (&end, &length);
            printf("Length of the list is %d node\n", length);
            break;

        case 11:
            deletelist(&end);
            front = NULL;
            end = NULL;
            printf("List is deleted\n");
            break;

        case 12:    
            exit (0);

        default:
            printf("\nwrong choice for operation");
	        break;

        }
    } 
    
    return 0;
}


