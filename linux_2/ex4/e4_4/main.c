#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "thread.h"

FILE* fp;

main()
{
    pthread_t tid1,tid2;
    //pthread_attr_t atr;
    fp = fopen("temp", "w");
    if(fp == NULL) {
    printf("file can't be open");
    }
    pthread_create(&tid1,NULL,&write_1,NULL);
    printf("tid1 created \n");
    pthread_create(&tid2,NULL,&write_2,NULL);
    printf("tid2 created \n");
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    fclose(fp);
}

