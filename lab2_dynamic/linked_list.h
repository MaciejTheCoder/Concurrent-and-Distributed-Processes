#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/** Node */
struct Node {
    void *data; /** data */
    struct Node *next; /** ponter to the next element in the list*/
};

/** List */
struct List {
    struct Node *head;
    int (*fptr)(void *,void *);
};

/** Constructor of the new list */
struct List *new_list(int (*fptr)(void *,void *));

/** push new element to the list */
void push(struct List **list, void *new_data);

// /** poping head */
void pop(struct List **list);

/** print the whole list */
void printList(struct List **list, void (*fptr)(void *));
 
/** Printing an integer */
void printInt(void *n);
 
/** Printing a char */
void printChar(void *c);
 

#endif