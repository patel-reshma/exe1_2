#include <stdio.h>
#include <pthread.h>

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
