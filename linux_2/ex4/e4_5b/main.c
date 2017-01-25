#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "read.h"
#define SIZE 1024
FILE* fr;

void main()
{
	pthread_t tid1;
    int j = 0;
    if((fr = fopen("temp_r","wb")) == NULL) {
        printf("temp_r not available");
    } else {
            for(j=0;j<500;j++) {
                fprintf(fr,"%d \n", j);
            }
    }
    fclose(fr);
	/* create thread to read from file and encrypt */
	pthread_create(&tid1, NULL, &read, NULL);
	
	printf("thread created");
	pthread_join(tid1, NULL);
}


