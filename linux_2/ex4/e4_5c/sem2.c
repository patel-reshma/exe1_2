#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 10

sem_t sem1;
FILE* fp;

void* read_1()
{
    int i=0;
    char* buf;
    buf = (char*)malloc(sizeof(char));
    sem_wait(&sem1);
    for(i=0;i<=SIZE;i++) {
        fread(buf,1,SIZE,fp);
        printf("tid1 \n");
    }
    sem_post(&sem1);
}

void* read_2()
{
    int i;
    char* buf1;
    buf1 = (char*)malloc(sizeof(char));
    sem_wait(&sem1);
    for(i=5;i<=20;i++) {
        fread(buf1,1,SIZE,fp);
        printf("tid2 \n"); 
    }
    sem_post(&sem1);
}

