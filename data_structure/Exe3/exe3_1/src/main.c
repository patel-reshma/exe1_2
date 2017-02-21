#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algo.h"

#define MAX 50

int main()
{
    int array[MAX], i, n;
    struct timespec tBefore, tAfter;  
    char ch[2];
    
    printf("How many numbers you want to sort:  ");
    scanf("%d", &n);
    if( n == 0)
    {
        printf("please enter valid input \n");
        exit(1);
    }
    printf("\nEnter %d numbers : ", n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    while(1) {

        printf("select one sorting method \n");
        printf("Enter B for bubble sort \n");
        printf("Enter R for Radix sort \n");
        printf("Enter Q for quick sort \n");
        printf("Enter E to exit \n");

        scanf("%s", ch);
    
        switch(ch[0]) {
            case 'B':

                clock_gettime(CLOCK_MONOTONIC, &tBefore);
                bubble_sort(array, n);
                clock_gettime(CLOCK_MONOTONIC, &tAfter);

                display(array, n);
                printf("Time for execution : %.9f seconds \n",
                            ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                             - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
                break;

            case 'R':
           
                clock_gettime(CLOCK_MONOTONIC, &tBefore);
                radix_sort(array, n);
                clock_gettime(CLOCK_MONOTONIC, &tAfter);

                display(array, n);
                printf("Time for execution : %.9f seconds \n",
                            ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                             - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
                break;
            
            case 'Q':
                clock_gettime(CLOCK_MONOTONIC, &tBefore);
                quick_sort(array, 0, n-1);
                clock_gettime(CLOCK_MONOTONIC, &tAfter);

                display(array, n);
                printf("Time for execution : %.9f seconds \n",
                            ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                             - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
                break;
            
            case 'E':
                exit(0);

            default:
                break;
        }

    }

    return 0;
}

