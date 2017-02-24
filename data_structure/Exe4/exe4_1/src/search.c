#include "dec.h"

void linear_search(int array[], int n)
{
    int i, j, v, p[MAX];
    int count = 0;
    int size;

    printf("enter no of element search list");
    scanf("%d", &v);

    for(j = 0; j < v; j++) {
        printf("enter number to be searched\n");
        scanf("%d", &p[j]);
    }

    for(j = 0; j < v; j++) {
        for(i = 0; i < n; i++) {
            if(array[i] == p[j]) {
                printf("%d found at index %d.\n", p[j], i + 1);
                count++;
            } 
        }
    }

    if(count == 0) {
        printf("no match found\n");
    }
    
    size = (sizeof(array) + sizeof(n) + sizeof(v) + sizeof(p) + sizeof(j)
            + (2 * sizeof(i)) + sizeof(count));
    printf("memory space of function %d bytes \n", size);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int n)
{
    int i, j;
    for (i = 1;  i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
        }
    }
}

void binary_search(int array[], int n)
{
    int low, high, mid, v[MAX], j, p, size;

    printf("enter no of search element\n");
    scanf("%d", &p);

    for(j = 0; j < p; j++) {
        printf("enter number to be searched\n");
        scanf("%d", &v[j]);
    }

    for(j = 0; j < p; j++) {
        low = 0;
        high = n - 1;
        mid = low + (high - low) / 2;
        while(low <= high) {
            if(array[mid] < v[j]) {
                low = mid + 1;
            } else if(array[mid] == v[j]) {
                printf("%d found at index %d \n", v[j], mid + 1);
                break;
            } else {
                high = mid - 1;
            }

            mid = low + (high - low) / 2;
        }

        if(low > high) {
            printf("no match found \n");
        }
    }

    size = (sizeof(array) + sizeof(n) + sizeof(low) + sizeof(high)
            + sizeof(mid) + sizeof(v) + sizeof(p) + (2 * sizeof(j)));
    printf("memory space of function %d bytes \n", size);
}
