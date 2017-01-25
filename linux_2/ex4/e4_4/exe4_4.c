#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t write;
FILE* fp;
void* write_1()
{
    //pthread_mutex_lock(&write);
    //fp =fopen("temp","a+");
    
    //if(fp == NULL) {
    //printf("file can't be open");
    //}
    int i=0;
    for(i=0;i<=1000;i++) {
        pthread_mutex_lock(&write);
        fprintf(fp,"$%d \n", i);
        pthread_mutex_unlock(&write);
    }
    
    //fclose(fp);
    //pthread_mutex_unlock(&write);
    
    printf("write_1 performed \n");
}

void* write_2()
{
    //pthread_mutex_lock(&write);
    //fp =fopen("temp","a+");
    //if(fp == NULL) {
    //printf("file can't be open");
  // }
    int i = 0;
    for(i=0;i<=1000;i++) {
        pthread_mutex_lock(&write);
        fprintf(fp,"#%d \n", i);
        pthread_mutex_unlock(&write);
        //sleep(1);
    }
    //fclose(fp);
    //pthread_mutex_unlock(&write);
    
    printf("write_2 performed \n");
    
}
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

