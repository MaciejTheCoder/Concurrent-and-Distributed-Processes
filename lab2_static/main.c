#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/** Comparing integers */
int compare_int(void *data_a, void *data_b){
    if (*(int *)data_a <= *(int *)data_b) {
        return 1;
    }
    else {
        return 0;
    };
}

/** Comparing chars */
int compare_char(void *data_a, void *data_b){
    if (*(char *)data_a <= *(char *)data_b) {
        return 1;
    }
    else {
        return 0;
    };
}

/** main */
int main () {
    
    struct List *list_1 = new_list(compare_int);
    struct List *list_2 = new_list(compare_char);

    char keyInput;

    printf("INT LIST \n");
    printf("a - add element\n");
    printf("d - pop element\n");
    printf("q - quit\n");

    while((keyInput = getchar()) != 'q') 
    {
        switch(keyInput)
        {
            case 'a':
                printf("Type int to add: \n");
                int * buffer = (int *)malloc(sizeof(int));
                scanf("%d", buffer);
                push(&list_1, buffer);
                printList(&list_1, printInt);
                printf("\n");
                getchar();
                break;
            case 'd':
                pop(&list_1);
                printList(&list_1, printInt);
                printf("\n");
                getchar();
                break;
            default:
                printf("Wrong value");
                getchar();
                continue;
        }
    }

    printf("CHAR LIST \n");
    printf("a - add element\n");
    printf("d - pop element\n");
    printf("q - quit\n");
    getchar();
    while((keyInput = getchar()) != 'q') 
    {
        switch(keyInput)
        {
            case 'a':
                printf("Type char to add: \n");
                getchar();
                char * buffer = (char *)malloc(sizeof(char));
                scanf("%c", buffer);
                push(&list_2, buffer);
                printList(&list_2, printChar);
                printf("\n");
                getchar();
                break;
            case 'd':
                pop(&list_2);
                printList(&list_2, printChar);
                printf("\n");
                getchar();
                break;
            default:
                printf("Wrong value");
                getchar();
                continue;
        }
    }
    return 0;
}