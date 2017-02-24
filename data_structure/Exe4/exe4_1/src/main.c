#include <stdio.h>
#include <time.h>

#include "dec.h"

#define MAX 50

int main()
{
    int i, n;
    char ch, t;
    struct timespec tAfter, tBefore;
    
    printf("enter no of element in array \n");
    scanf("%d", &n);
    
    if(n == 0) {
        printf("enter valid number\n");
    }

    for(i = 0; i < n; i++) {
        printf("enter %d elemnt of array ", i+1);
        scanf("%d", &array[i]);
    }
    
    do {

        printf("Enter your choice \n");
        printf("Enter L for linear search \n");
        printf("Enter B for binary search \n");
    
        scanf(" %c", &ch);

        switch(ch) {
            case 'L':
            case 'l':

                clock_gettime(CLOCK_MONOTONIC, &tBefore);
                linear_search(array, n); 
                clock_gettime(CLOCK_MONOTONIC, &tAfter);

                printf("Time for execution : %.9f seconds \n",
                        ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
                break;

            case 'B':
            case 'b':

                bubble_sort(array, n); 
            
                clock_gettime(CLOCK_MONOTONIC, &tBefore);
                binary_search(array, n); 
                clock_gettime(CLOCK_MONOTONIC, &tAfter);

                printf("Time for execution : %.9f seconds \n",
                        ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
                break;

            default:
                printf("enter valid input\n"); break;
        }
        printf("enter y/Y to continue searching\n");
        scanf(" %c", &t);
        
    } while(t == 'y' || t == 'Y');
}

