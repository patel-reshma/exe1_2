////////////////////////////////*******************************************************************************
// Copyright(c) <2017>, Volansys Technologies
// 
// Description:
// In this file I have created child process which creates another child process
// and observed their PID, PPID   
// 
// Author       - Reshma patel
//
//*******************************************************************************
//
// Jan/19/2017, Reshma, Created ()
//
// ******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t ret;
    pid_t ret1;
    int   status, i;

    ret = fork();
    if(ret > 0) {
        printf("patent1 with process id %d \n", getpid());
        printf("parent1 with PPID %d \n", getppid());
        printf("parent1:hello \n");
        ret = wait( &status);
    }
    
    else if (ret == 0) {
        ret1 = fork();
        if(ret1 >0) {
            printf("child1 with pid %d \n", getpid());
            printf("child1 with PPID %d \n", getppid());
            printf("child1:world \n");
            exit(0);
        }
        else {
            printf("child2 with pid %d \n", getpid());
            printf("child2 with PPID %d \n", getppid());
            printf("child2: hello world");
        }
    }
    return 0;
}


