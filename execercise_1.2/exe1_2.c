////////////////////////////////*******************************************************************************
// Copyright(c) <2017>, Volansys Technologies
// 
// Description:
// In this file I have created child process which prints 1 to 10000.
// upto whatever time child is processing parent will wait for child complition.	
//    
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
    int   status, i;
    int   role = -1;

    ret = fork();
    if (ret > 0) {
  
        ret = wait( &status );
        printf("Parent: This is the parent process (pid %d)\n", getpid());
        for (i = 0 ; i < 1 ; i++) {
            printf("Parent: At count %d\n", i);
        }
        
        role = 0;
    } else if (ret == 0) {
        printf("Child: This is the child process (pid %d)\n",getpid());
        for (i = 1 ; i < 10001 ; i++) {
            printf("Child: At count %d\n", i);
          
            }
        exit(0);
       role = 1;
    } else {
        printf("Parent: Error trying to fork() (%d)\n", errno);
    }
    printf("%s : Exiting...\n", ((role == 0) ? "Parent" : "Child"));
    return 0;







}

