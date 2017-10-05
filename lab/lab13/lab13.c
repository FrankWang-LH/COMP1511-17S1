#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int       data;
};

int count(int value, struct node *list);
struct node *get_nth(int n, struct node *head);
struct node *insert_nth(int n, struct node *new_node, struct node *head);
struct node *delete_nth(int n, struct node *head);
struct node *delete_odd(struct node *head);

void print_list(struct node *head);
struct node *reverse(struct node *list);
struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
void free_list(struct node *head);

#define MAX_LINE 4096

// simple main function to test count, get_nth, insert_nth, delete_nth, delete_odd

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
            free_list(list_head);
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
        } else if (strcmp(line, "count") == 0) {
            printf("count(%d) returns %d\n", argument, count(argument, list_head));
        } else if (strcmp(line, "get_nth") == 0) {
            struct node *n = get_nth(argument, list_head);
            if (n == NULL) {
                printf("get_nth(%d) returned NULL\n", argument);
            } else {
                printf("get_nth(%d) returned a pointer to a node containing %d\n", argument, n->data);
            }
        } else if (strcmp(line, "delete_nth") == 0) {
            list_head = delete_nth(argument, list_head);
        } else if (strcmp(line, "insert_nth") == 0) {
            // insert a node containing 42
            struct node *new_node = create_node(42, NULL);
            list_head = insert_nth(argument, new_node, list_head);
        } else if (strcmp(line, "delete_odd") == 0) {
            list_head = delete_odd(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }
    }
}

// Return number of nodes in the list containing value.

int count(int value, struct node *head) {
    int val = 0;
    if(head == NULL){
        // deal with empty list
        val= 0;
    } else {
        while(head != NULL){
            if(head -> data == value){
                val++;
            }
            head = head -> next;
        }   
        return val;     
    }
        
    return 0;
}

// Return a pointer to the node in  position n in the list.
// Position 0 is the first node in the list.
// Return NULL if the list has no n-th node.

struct node *get_nth(int n, struct node *head) {
    /*int num = 0;
    struct node *a = head;
    while(a != NULL){
        num++;
        a = a -> next;
    }
    if(head == NULL){
        // deal with empty list
        return NULL;
    } else {
        if(n < 0 || n > num - 1){
            return NULL;
        } else if(n == 0){
            return head;
        } else {
            while(head != NULL && n > 0){
                head = head -> next;
                n--;
            }
        }
    }*/
    
    /*if(head == NULL){
        return NULL;
    } 

    
    while(n > 0 && head != NULL){
        head = head -> next;
        n--;
    }
    if(n != 0){
        return NULL;
    }

    return head;*/

    if(head == NULL || n < 0){
        return NULL;
    } 
    
    if(n > 0){
        return get_nth(n-1,head->next);
    }
    
    return head;
}

// Delete the node in  position  n in the list.
// The first node in the list is in position 0.
// Do nothing if there is no position n in the list.
// The new head of the list is returned.

struct node *delete_nth(int n, struct node *head) {
    /*int num = 0;
    struct node *a = head;
    while(a != NULL){
        num++;
        a = a -> next;
    }
    if(head == NULL){
        // deal with empty list
        return NULL;   
    } else if(n > num - 1 || n < 0){
        return head;
    } else if(head -> next == NULL){
        if(n == 0){
            free(head);
            return NULL;
        }
    } else {
        struct node *nex = head -> next;
        struct node *cur = head;
        if(n == 0){
            head = nex;
            free(cur);
        } else {
            if(n == 1){
                head -> next = nex -> next;
                free(nex);
            } else {
                while(n > 1){
                    n--;
                    nex = nex -> next;
                    cur = cur -> next;
                }
                cur -> next = nex -> next;
                free(nex);
            }
        }
    }*/

    struct node *a = head;
    if(a == NULL || n < 0){
        return head;
    } else {
        if(n == 0){
            head = head -> next;
            free(a);
        } else {
            head -> next = delete_nth(n-1,head->next);
        }
    }
    
    return head;
}

// Delete all nodes of the list containing odd numbers.
// The new head of the list is returned.

struct node *delete_odd(struct node *head) {
    /*if(head == NULL){
        return NULL;
    }

    int num = 0;
    int tot = 0;
    struct node *a = head;
    while(a != NULL){
        if(a -> data % 2 != 0){
            num++;
        }
        tot++;
        a = a -> next;
    }
    
    if(num != 0){
        struct node *cur = head;
        struct node *nex = head -> next;
        
        int i = 0;
        int k = 0;
        if(head -> next == NULL){
            free(head);
            return NULL;
        // deal with two element list
        } else if(nex -> next == NULL){
            if(cur -> data % 2 != 0 && nex -> data % 2 != 0){
                free(nex);
                free(head);
                return NULL;
            } else if(cur -> data % 2 != 0){
                head = nex;
                free(cur);
            } else if(nex -> data % 2 != 0){
                cur -> next = NULL;
                free(nex);
            }
        // more than 2 element
        } else {
            i = 0;
            k = 0;
            while(cur -> data % 2 != 0 && cur -> next != NULL){
                struct node *temp = cur -> next;
                head = temp;
                free(cur);
                cur = temp;
            } 
            nex = cur -> next;
            if(nex != NULL){
                while(nex -> next != NULL){
                    if(nex -> data % 2 == 1){
                        struct node *temp = nex -> next;
                        cur -> next = nex -> next;
                        free(nex);
                        nex = temp;
                    } else {
                        cur = cur -> next;
                        nex = nex -> next;
                    }
                }
                if(nex -> data % 2 == 1){
                    free(nex);
                    cur -> next = NULL;
                }
            } else {
                if(cur -> data % 2 ==1){
                    free(cur);
                    return NULL;
                }
            }
        }
    }*/

    struct node *a = head;
    if(head == NULL){
        return NULL;
    } else {
        if(head -> data % 2 != 0){
            head = head -> next;
            free(a);
            return delete_odd(head);
        } else {
            head->next = delete_odd(head -> next);
        }
    }

    return head;
}


// Insert new_node before position n in the list.
// The first node in the list is in position 0.
// If n == length of the list, new_node is appended to list.
// Otherwise do nothing if there is no position n in the list.
// The new head of the list is returned.

struct node *insert_nth(int n, struct node *new_node, struct node *head) {

    /*if(head == NULL && n == 0){
        head = new_node;
        new_node -> next = NULL;
        return head;
    }

    int num = 0;
    struct node *a = head;
    while(a != NULL){
        num++;
        a = a -> next;
    }

    if(n > num || n < 0){
        return head;
    } else if(n == num){
        struct node *cur = head;
        while(cur -> next != NULL){
            cur = cur -> next;
        }
        cur -> next = new_node;
        new_node -> next = NULL;
    } else {
        struct node *nex = head -> next;
        struct node *cur = head;
        if(n == 0){
            head = new_node;
            new_node -> next = cur;
        } else {
            while(n > 1){
                n--;
                cur = cur -> next;
                nex = nex -> next;
            }
            cur -> next = new_node;
            new_node -> next = nex;  
        }
        
    }*/

    if(head == NULL){
        if(n == 0){
            return new_node;
        } else {
            return NULL;
        }
    } else {
        if(n == 0){
            new_node -> next = head;
            return new_node;
        } else {
            head -> next = insert_nth(n-1,new_node,head->next);
            return head;
        }
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
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return last(head->next);
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

void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}

