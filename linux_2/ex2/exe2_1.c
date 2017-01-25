#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
        mkdir("/home/reshma/workspace/a", S_IRWXU | S_IRWXG | S_IRWXO);   
        //mkdir("./b", S_IRWXU | S_IRWXG | S_IRWXO);   
       // mkdir("./c", S_IRWXU | S_IRWXG | S_IRWXO);   
       // mkdir("./d", S_IRWXU | S_IRWXG | S_IRWXO);   
       // mkdir("./e", S_IRWXU | S_IRWXG | S_IRWXO);   
}
