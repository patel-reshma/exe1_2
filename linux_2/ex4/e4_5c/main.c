#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "sem2.h"

sem_t sem1;
FILE* fp;

main()
{
    sem_init(&sem1,0,2);
    pthread_t tid1,tid2;
    int i = 0; 
    if((fp = fopen("temp","w")) == NULL) {
        printf("file can't be open");
    } 
    else {
        for (i=0;i<20;i++) {
            fprintf(fp,"%d \n", i);
            }
            fclose(fp);
        }

    
    if((fp = fopen("temp","r")) == NULL) {
        printf("file can't be open");
    }
    
    /*creating thread with tid1 */
    pthread_create(&tid1, NULL, &read_1, NULL);
    
    /*creating thread with tid2 */
    pthread_create(&tid2, NULL, &read_2, NULL);

    pthread_join(tid1,NULL);
    printf("thread 1 completed");

    pthread_join(tid2,NULL);
    printf("thread 2 completed");
    
    fclose(fp);
    
    sem_destroy(&sem1);
}

