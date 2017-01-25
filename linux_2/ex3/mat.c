/////////////////////////////////////////////
// Copyright(c) <2017>, Volansys Technologies
// * 
// * Description:
// * In this file 3 cross 3 matrix multiplication is implemented 
// * using thread. 
// * 
// 
// * Author       -Reshma patel
// *
//*****************************************************************************
// *
// * History
// *
// * january /20/2017,Reshma, Created  

////////////////////////////
//   standard include
///////////////////////////
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// defines
#define MAX 3

///////////////////////////
// structure
///////////////////////////
struct value {
    int i; /* row */
    int j; /* column */
    int k; 
};

///////////////////////////
//  Global variable
///////////////////////////
int i,j,k;
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int sum = 0;

void *mul(void *);

int main()
{
    //int sum = 0;
    //int i,j,k;

    pthread_t tid;          // thread id
    pthread_attr_t atr;     /* structure attr_t whoes content will be used at
                               time of thread creation*/
    pthread_attr_init(&atr);

    printf("\nEnter First Matrix : ");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }            
    
    printf("\nEnter Second Matrix: ");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("The First Matrix is: \n");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }

    printf("The Second Matrix is : \n");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i <= 2; i++) { 
        for (j = 0; j <= 2; j++) {
            sum = 0;
            for (k = 0; k <= 2; k++) {
                struct  value* data = (struct value*) 
                    malloc(sizeof(struct value));
                data->i = i;
                data->j = j;
                data->k = k;
                //Create the thread
                pthread_create(&tid,&atr,mul,data);
                //Make sure the parent waits for all thread to complet
                // pthread_join(tid, NULL);
            }
            pthread_join(tid, NULL);
            c[i][j] = sum;
        }
    }
    
    printf("\nMultiplication Of Two Matrices : \n");
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
    return (0);
}

void *mul(void* val)
{
    struct value* data = ((struct value*)val);
    sum = sum + a[data->i][data->k] * b[data->k][data->j];
    pthread_exit(0);
}
