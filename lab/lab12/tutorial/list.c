#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void printlist(struct node *list) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");

}

int member(int value, struct node *list) {
    while(list != NULL){
        if(list -> data == value){
            return 1;
        }
        list = list -> NULL;
    }
    return 0;
}

struct node *list_append(struct node *list1, struct node *list2) {
    struct node *a = list1;
    if(list1 == NULL){
        return list2;
    } else {
        while(a -> next != NULL){
            a= a -> next;
        }
        a -> next = list2;
    }
    
    return list1;
}

struct node *insert_ordered(int item, struct node *list) {
    struct node *new = malloc(sizeof(struct node));
    new -> data = item;
    new -> next = NULL;

    if(list == NULL){
        return new;
    } else if(list -> next == NULL){
        if(item <= list -> data){
            new -> next = list;
            return new;
        } else {
            list -> next = new;
            return list;
        }
    } else {
        struct node *head;
        struct node *a=list;
        struct node *b=list-> next;
    
        if(item <= list -> data){
            new->next = list;
            return new;
        }
        while(b != NULL){
            if(item == b -> data){
                a -> next = new;
                new -> next = b;
            }
            a = a -> next;
            b = b -> next;
        }
    }           
                
    return list;
}

struct node *merge_sorted(struct node *list1, struct node *list2) {
                                                                                                                                              
    return NULL;
}
