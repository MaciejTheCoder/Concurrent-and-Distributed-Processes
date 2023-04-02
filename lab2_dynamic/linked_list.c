#include "linked_list.h"

struct List *new_list(int (*fptr)(void *,void *)) {
    struct List *list;
    list = (struct List*)malloc(sizeof(struct List)); /** Allocating memory for a new Node */
    list->head = NULL;
    list->fptr = fptr;
    return list;
}

/** push new element to the list */
void push(struct List **list, void *new_data) {
    struct Node *new_node, *prev, *next; /** creating Nodes */
    new_node = (struct Node*)malloc(sizeof(struct Node)); /** Allocating memory for a new Node */
    new_node->data = malloc(sizeof(new_data)); /** Allocating memory for data of the new Node */
    new_node->data = new_data;
    new_node->next = NULL;
    
    if ((*list)->head == NULL) { /** List is empty */
        (*list)->head = new_node;
    }
    else {
        prev = NULL; 
        next = (*list)->head;
        while(next!=NULL && (*list)->fptr(next->data,new_data) == 1 ) { /** when next is not null -> iterate until next is smaller or equal */
            prev = next;
            next = next->next;
        }
        if(prev!=NULL){
            new_node->next = prev->next;
            prev->next = new_node;
        }
        else{ /** prev is null so adding new head */
            new_node->next = (*list)->head;
            (*list)->head = new_node;
        }
    }
}

// /** poping head */
void pop(struct List **list) {

    if ((*list)->head != NULL) { /** If head exitsts */
        struct Node *temp = (*list)->head; /** Creating temporary structure */
        (*list)->head = (*list)->head->next;  /** Next Node is new head */
        free(temp); /** Delocating memory */
    }

}

/** print the whole list */
void printList(struct List **list, void (*fptr)(void *))
{   
    struct Node *temp = (*list)->head; /** Creating temporary structure */
    while (temp != NULL)
    {
        (*fptr)(temp->data);
        temp = temp->next;
    }
    free(temp); /** Delocating memory */
}
 
/** Printing an integer */
void printInt(void *n)
{
   printf(" %d", *(int *)n);
}
 
/** Printing a char */
void printChar(void *c)
{
   printf(" %c", *(char *)c);
}
 