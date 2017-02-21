#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 3
#define N 3
#define NUM_THREADS 10

int A [M][K];
int B [K][N];
int C [M][N];

struct v {
   int i; /* row */
   int j; /* column */
};

void *runner(void *param); /* the thread */

int main()
{
int i,j, count = 0;

printf("\nEnter First Matrix : n");

for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        scanf("%d", &A[i][j]);
    }
}            

printf("\nEnter Second Matrix:n");
for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        scanf("%d", &B[i][j]);
    }
}
                    
printf("The First Matrix is: \n");

for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        printf(" %d ", A[i][j]);
    }
    printf("\n");
}
                            
printf("The Second Matrix is : \n");

for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        printf(" %d ", B[i][j]);
    }
    printf("\n");
}


for(i = 0; i < M; i++) {
    for(j = 0; j < N; j++) {
        //Assign a row and column for each thread
        struct v *data = (struct v *) malloc(sizeof(struct v));
        data->i = i;
        data->j = j;
        /* Now create the thread passing it data as a parameter */
        pthread_t tid;       //Thread ID
        pthread_attr_t attr; //Set of thread attributes
        //Get the default attributes
        pthread_attr_init(&attr);
        //Create the thread
        pthread_create(&tid,&attr,runner,data);
		pthread_join(tid, NULL);
      }
   }


   //Print out the resulting matrix
   printf("resultant matrix is \n");
   
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

//The thread will begin control in this function
void *runner(void *param) {
    struct v *data = param; // the structure that holds our data
    int n, sum = 0; //the counter and sum

   //Row multiplied by column
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   //assign the sum to its coordinate
   C[data->i][data->j] = sum;

   //Exit the thread
   pthread_exit(0);
}
