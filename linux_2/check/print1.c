#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int my_print(char *p)
{
    while(write(1, p++, 1));
}

main()
{
    write(1, "hello world", strlen("hello world")); 
}

