#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 1024
pthread_mutex_t mu;
FILE* fr;
FILE* fm;
char* buf;

void main()
{
    int j = 0;
    if((fr = fopen("temp_r","wb")) == NULL){
        printf("temp_r not available");
    } else {
            for(j=0;j<500;j++) {
                fprintf(fr,"%d \n", j);
            }
    }
    fclose(fr);
    
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
