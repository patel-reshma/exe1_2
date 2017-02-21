#include <stdio.h>
#include "algo.h" 
#include "sub.h"

void display(int array[], int n) {
    int i;
    printf("\nSorted array is \n");
    for (i = 0; i < n; i++) {
        printf("%d \n", array[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int p[], int n)
{
    int i, j;
    for (i = 1;  i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            if (p[j] > p[j+1])
                swap(&p[j], &p[j+1]);
        }
    }
}

void radix_sort(int p[], int n)
{
    int max, dig_p;
    max = max_n(p, n);

    for(dig_p = 1; max / dig_p > 0; dig_p = dig_p * 10) {
        sort(p, n, dig_p);
    }
}

void quick_sort(int p[], int a, int b)
{
    int pi, i, j, temp;
    if(a < b) {
        pi = a;
        i = a;
        j = b;
        while(i < j) {
            while(p[i] <= p[pi] && i <= b) {
                i++;
            }
            while(p[j] > p[pi] && j >= a) {
                j--;
            }
            if(i < j) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
        temp = p[j];
        p[j] = p[pi];
        p[pi] = temp;
        quick_sort(p, a, j - 1);
        quick_sort(p, j + 1, b);
    }
}

