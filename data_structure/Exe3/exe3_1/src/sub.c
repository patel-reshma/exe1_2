#include <stdio.h>
#include "sub.h"

int max_n(int array[], int n) {
    int num = array[0];
    int i;

    for(i = 1; i <= n; i++) {
        if (array[i] > num) {
            num = array[i];
        }
        return num;
    }    
}

void sort(int array[], int n, int dig) 
{
    int final[n];
    int i,count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(array[i] / dig) % 10]++;
    }

    for (i = 1; i < 10; i++) {
    count[i] += count[i -1];
    }

    for (i = n -1; i >= 0; i--) {
        final[count[(array[i] / dig) % 10] - 1] = array[i];
        count[(array[i] / dig) % 10]--;
    }

    for(i = 0 ; i < n; i++) {
        array[i] = final[i];
    }
}
