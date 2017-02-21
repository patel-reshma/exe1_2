#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 1024

pthread_cond_t read;
pthread_cond_t write;
pthread_mutex_t mu;
pthread_t tid1,tid2;

FILE* fp;
char* buf;
char ch;
int word_count,count_w;

void* disp();
void* count();

int main(void)
{
//    char* buf;
//    char ch;
    
    if((fp = fopen("temp_read","r")) == NULL) {
        fprintf(stderr, "file temp_read is not available");
        exit(1);
    }

    pthread_cond_init(&read, NULL);
    pthread_cond_init(&write, NULL);
    
    /*thread that will display*/
    pthread_create(&tid1, NULL, &disp, NULL);

    /*thread that will count*/
    pthread_create(&tid2, NULL, &count, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

void* count()
{
    //pthread_mutex_lock(&mu);
    buf = (char*)malloc((sizeof(char))*SIZE); 
    word_count = 0;
        do {
            pthread_mutex_lock(&mu);
            //pthraed_cond_signal(&read);
            pthread_cond_wait(&write, &mu);
            fread(buf,SIZE,1,fp);
            //printf("%s \n after NULL \n", buf);
            buf[SIZE] = '\0';
            //printf("%s \n ", buf);
            while(*buf != '\0') {
                count_w = 0;
                if( (*buf) == '\n' || (*buf) == '\t' || isspace(*buf)) {
                    count_w++;
                    word_count = word_count + count_w;
                }
                *buf++;
            // printf("%d \n", word_count);
            }
            pthread_cond_signal(&read);
            //printf("word count = %d \n", word_count);
            //printf("iteration completed \n");
            pthread_mutex_unlock(&mu);
        } while((ch = getc(fp)) != EOF);
        
        fclose(fp);
        printf("word_counted successfully \n");
}

void* disp()
{
    while(1) {
        pthread_mutex_lock(&mu);
        pthread_cond_signal(&write);
		pthread_mutex_unlock(&mu);
        pthread_cond_wait(&read, &mu);
        printf("word_count = %d \n", word_count);
        
    }
}
