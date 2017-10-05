// Frank and Tanya
// MAY 22 2017
// lab12


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int       data;
};

struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
struct node *delete_first(struct node *head);
struct node *delete_last(struct node *head);
struct node *delete_contains(int i, struct node *head);
void print_list(struct node *head);
struct node *reverse(struct node *list);

#define MAX_LINE 4096

// simple main function to test delete_first, delete_last, delete_contains, reverse

int
main(int argc, char *argv[]) {
    char line[MAX_LINE];
    struct node *list_head = NULL;

    while (1) {
        printf("list = ");
        print_list(list_head);
        printf("\n");

        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "quit") == 0) {
            return 0;
        } else if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
        } else if (strcmp(line, "delete_first") == 0) {
            list_head = delete_first(list_head);
        } else if (strcmp(line, "delete_last") == 0) {
            list_head = delete_last(list_head);
        } else if (strcmp(line, "delete_contains") == 0) {
            list_head = delete_contains(argument, list_head);
        } else if (strcmp(line, "reverse") == 0) {
            list_head = reverse(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }
    }
}

// delete first node in list

struct node *delete_first(struct node *head) {
    if(head == NULL){
        // deal with empty lists
        return NULL;
    } else if(head -> next != NULL){
        // deal with other lists
        struct node *h = head -> next;
        free(head);
        head = h;
    } else {
        return NULL;
    }
    return head;
}

// delete last node in list

struct node *delete_last(struct node *head) {
    
    if(head == NULL){
        // deal with empty list
        return NULL;
    } else if(head -> next == NULL){
        // deal with single element
        free(head);
        return NULL;
    } else {
        // other lists
        struct node *cur = head;
        struct node *nex = head -> next;
        // loop until the last element
        while(nex -> next != NULL){
            cur = cur -> next;
            nex = nex -> next;
        }
        // change the 'next' for the second to last element
        cur -> next = NULL;
        // delete last element
        free(nex);
    }
    
    return head;
}

// delete first node containing specified int

struct node *delete_contains(int i, struct node *head) {
    if(head == NULL){
        // deal with empty list
        return NULL;
    } else if(head -> next == NULL){
        // deal with single element
        if(head -> data == i){
            free(head);
            return NULL;
        }
    } else {
        struct node *cur = head;
        struct node *nex = head -> next;
        // deal with two element list
        if(nex -> next == NULL){
            if(cur -> data == i){
                head = nex;
                free(cur);
            } else if(nex -> data == i){
                cur -> next = NULL;
                free(nex);
            }
        // more than 2 element
        } else {
            while(nex -> next != NULL){
                if(cur -> data == i){
                    // if the first element fits condition
                    head = nex;
                    // delete element
                    free(cur);
                    break;
                } else if(nex -> data == i){
                    // if it's not the 1st one
                    cur -> next = nex -> next;
                    // delete element
                    free(nex);
                    break;
                }
                cur = cur -> next;
                nex = nex -> next;
            }  
        } 
    }
    return head;
}

// reverse the nodes in list

struct node *reverse(struct node *head) {
    if(head == NULL){
        // deal with empty list
        return NULL;
    } else {
        // non-empty list
        struct node *cur = head;
        struct node *nex = head -> next;
        struct node *pre = NULL;
        // run the loop before reaching the last node
        while(nex != NULL){
            // change the pointer to point to the previous node
            cur -> next = pre;
            // move onwards
            pre = cur;
            cur = nex;
            nex = nex -> next;                        
        }
        // set next for last node
        cur -> next = pre;
        head = cur;    
    }

    return head;
}

// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    struct node *n =  create_node(value, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *create_node(int data, struct node *next) {
    struct node *n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}
