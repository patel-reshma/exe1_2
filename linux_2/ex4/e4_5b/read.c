#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 1024

FILE* fr;
FILE* fm;
char* buf;

void* read()
{
    fm = fopen("temp_w","w");
    if(fm == NULL) {
    printf("file temp_w is not available");
    }
    //pthread_mutex_lock(&mu);
    
    fr = fopen("temp_r","rb");
    if(fr == NULL) {
    printf("file temp_r is not available");
    }
    buf = (char*)malloc(sizeof(char)*SIZE);
    while((fread(buf,SIZE,1,fr)) != 0) {
        *buf = *buf + 5;
        fwrite((buf),1,SIZE,fm);
        
    }
    fclose(fm);
    fclose(fr);
    printf("encryption completed \n");
}
