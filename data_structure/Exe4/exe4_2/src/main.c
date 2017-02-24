#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dec.h"
#include "enter.h"
#include "search.h"

int main()
{
    char ch, t;
    int n;
    struct timespec tAfter, tBefore;
    node *p, *parent;

    do {
        printf("Enter your choice:\n");
        printf("Enter C to create node in tree\n");
        printf("Enter P to display tree in preorder\n");
        printf("Enter I to display tree in Inorder\n");
        printf("Enter O to display tree in postorder\n");
        printf("Enter L to display tree in levelorder\n");
        printf("Enter S to search value from the tree\n");
        
        scanf(" %c", &ch);

        switch(ch) {
        case 'c':
        case 'C':
            create_node();
            break;
        
        case 'P':
        case 'p':
            clock_gettime(CLOCK_MONOTONIC, &tBefore);
            pre(root);
            clock_gettime(CLOCK_MONOTONIC, &tAfter);

            printf("Time for execution : %.9f seconds \n",
                    ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
            break;
        case 'I':
        case 'i':
            clock_gettime(CLOCK_MONOTONIC, &tBefore);
            inord(root);
            clock_gettime(CLOCK_MONOTONIC, &tAfter);

            printf("Time for execution : %.9f seconds \n",
                    ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
            break;
        case 'O':
        case 'o':
            clock_gettime(CLOCK_MONOTONIC, &tBefore);
            post(root);
            clock_gettime(CLOCK_MONOTONIC, &tAfter);

            printf("Time for execution : %.9f seconds \n",
                    ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
            break;
        case 'L':
        case 'l':
            clock_gettime(CLOCK_MONOTONIC, &tBefore);
            level(root);
            clock_gettime(CLOCK_MONOTONIC, &tAfter);

            printf("Time for execution : %.9f seconds \n",
                    ((double)tAfter.tv_sec + 1.0e-9 * tAfter.tv_nsec)
                        - ((double)tBefore.tv_sec + 1.0e-9 * tBefore.tv_nsec));
            break;
        case 'S':
        case 's':
            printf("enter num to be searched\n");
            scanf("%d", &n);
            p = search(root, n, &parent);
            printf("%d parent node %d\n", p->id, parent->id);
        break;
        
        default:
            break;
        }
        printf("to continue enter y/Y \n");
        scanf(" %c", &t);
    } while(t == 'y' || t == 'Y');
}

