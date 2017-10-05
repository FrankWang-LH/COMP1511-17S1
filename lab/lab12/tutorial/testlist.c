#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void testMember(void);
void testAppend1(void);
void testAppend2(void);
void testAppend3(void);
void testInsertOrdered1(void);
void testInsertOrdered2(void);
void testInsertOrdered3(void);
void testInsertOrdered4(void);
void testMergeSorted1(void);
void testMergeSorted2(void);
void testMergeSorted3(void);
void testMergeSorted4(void);
void testMergeSorted5(void);


int main (void) {
    testMember();
    testAppend1();
    testAppend2();
    testAppend3();
    testInsertOrdered1();
    testInsertOrdered2();
    testInsertOrdered3();
    testInsertOrdered4();
    testMergeSorted1();
    testMergeSorted2();
    testMergeSorted3();
    testMergeSorted4();
    testMergeSorted5();

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}


void testMember(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing membership of list:\n");
    printlist(&n1);
    printf("\n");

    assert(member(10, &n1));
    assert(member(20, &n1));
    assert(member(30, &n1));
    assert(!member(5, &n1));

    printf("Passed!\nTesting membership of emptylist:\n");

    assert(!member(10, NULL));

    printf("Passed\n");
}

void testAppend1(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    struct node n6 = {60, NULL};
    struct node n5 = {50, &n6};
    struct node n4 = {40, &n5};

    printf("Testing append.\nFrom list:\n");
    printlist(&n4);
    printf("\nOnto list:\n");
    printlist(&n1);
    printf("\n");

    struct node *appended = list_append(&n1, &n4);

    printf("After append:");
    printlist(appended);
    printf("\n");

    assert(appended == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == &n4);
    assert(n4.next == &n5);
    assert(n5.next == &n6);
    assert(n6.next == NULL);

    printf("Passed!\n");
}

void testAppend2(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing append.\nFrom list:\n");
    printlist(NULL);
    printf("\nOnto list:\n");
    printlist(&n1);
    printf("\n");

    struct node *appended = list_append(&n1, NULL);

    printf("After append:");
    printlist(appended);
    printf("\n");

    assert(appended == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == NULL);

    printf("Passed!\n");
}

void testAppend3(void) {
    struct node n6 = {60, NULL};
    struct node n5 = {50, &n6};
    struct node n4 = {40, &n5};

    printf("Testing append.\nFrom list:\n");
    printlist(&n4);
    printf("\nOnto list:\n");
    printlist(NULL);
    printf("\n");

    struct node *appended = list_append(NULL, &n4);

    printf("After append:");
    printlist(appended);
    printf("\n");

    assert(appended == &n4);
    assert(n4.next == &n5);
    assert(n5.next == &n6);
    assert(n6.next == NULL);

    printf("Passed!\n");
}

void testInsertOrdered1(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing insert %d ordered into list:\n", 15);
    printlist(&n1);
    printf("\n");

    struct node *appended = insert_ordered(15, &n1);

    printf("After insert:");
    printlist(appended);
    printf("\n");

    assert(appended == &n1);

    struct node *inserted = n1.next;
    assert(inserted->data == 15);
    assert(inserted->next == &n2);

    assert(n2.next == &n3);
    assert(n3.next == NULL);

    free(inserted);

    printf("Passed!\n");
}

void testInsertOrdered2(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing insert %d ordered into list:\n", 5);
    printlist(&n1);
    printf("\n");

    struct node *appended = insert_ordered(5, &n1);

    printf("After insert:");
    printlist(appended);
    printf("\n");

    struct node *inserted = appended;
    assert(inserted->data == 5);
    assert(inserted->next == &n1);

    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == NULL);

    free(inserted);

    printf("Passed!\n");
}


void testInsertOrdered3(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing insert %d ordered into list:\n", 35);
    printlist(&n1);
    printf("\n");

    struct node *appended = insert_ordered(35, &n1);

    printf("After insert:");
    printlist(appended);
    printf("\n");

    assert(appended == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);

    struct node *inserted = n3.next;
    assert(inserted->data == 35);
    assert(inserted->next == NULL);

    free(inserted);

    printf("Passed!\n");
}

void testInsertOrdered4(void) {
    printf("Testing insert %d ordered into empty list.\n", 35);

    struct node *appended = insert_ordered(35, NULL);

    printf("After insert:");
    printlist(appended);
    printf("\n");

    struct node *inserted = appended;
    assert(inserted->data == 35);
    assert(inserted->next == NULL);
    free(inserted);

    printf("Passed!\n");
}


void testMergeSorted1(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    struct node n6 = {60, NULL};
    struct node n5 = {50, &n6};
    struct node n4 = {40, &n5};

    printf("Testing merge sorted.\nList 1:\n");
    printlist(&n4);
    printf("\nList 2:\n");
    printlist(&n1);
    printf("\n");

    struct node *merged = merge_sorted(&n1, &n4);

    printf("Merged:");
    printlist(merged);
    printf("\n");

    assert(merged == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == &n4);
    assert(n4.next == &n5);
    assert(n5.next == &n6);
    assert(n6.next == NULL);

    printf("Passed!\n");
}

void testMergeSorted2(void) {
    struct node n3 = {60, NULL};
    struct node n2 = {40, &n3};
    struct node n1 = {20, &n2};

    struct node n6 = {50, NULL};
    struct node n5 = {30, &n6};
    struct node n4 = {10, &n5};

    printf("Testing merge sorted.\nList 1:\n");
    printlist(&n4);
    printf("\nList 2:\n");
    printlist(&n1);
    printf("\n");

    struct node *merged = merge_sorted(&n1, &n4);

    printf("Merged:");
    printlist(merged);
    printf("\n");

    assert(merged == &n4);
    assert(n1.next == &n5);
    assert(n2.next == &n6);
    assert(n3.next == NULL);
    assert(n4.next == &n1);
    assert(n5.next == &n2);
    assert(n6.next == &n3);

    printf("Passed!\n");
}



void testMergeSorted3(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    struct node n6 = {60, NULL};
    struct node n5 = {50, &n6};
    struct node n4 = {40, &n5};

    printf("Testing merge sorted.\nList 1:\n");
    printlist(&n4);
    printf("\nList 2:\n");
    printlist(&n1);
    printf("\n");

    struct node *merged = merge_sorted(&n1, &n4);

    printf("Merged:");
    printlist(merged);
    printf("\n");

    assert(merged == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == &n4);
    assert(n4.next == &n5);
    assert(n5.next == &n6);
    assert(n6.next == NULL);

    printf("Passed!\n");
}

void testMergeSorted4(void) {
    struct node n3 = {60, NULL};
    struct node n2 = {40, &n3};
    struct node n1 = {20, &n2};
    struct node n0 = {10, &n1};

    struct node n6 = {50, NULL};
    struct node n5 = {30, &n6};

    printf("Testing merge sorted.\nList 1:\n");
    printlist(&n5);
    printf("\nList 2:\n");
    printlist(&n0);
    printf("\n");

    struct node *merged = merge_sorted(&n0, &n5);

    printf("Merged:");
    printlist(merged);
    printf("\n");

    assert(merged == &n0);
    assert(n1.next == &n5);
    assert(n2.next == &n6);
    assert(n3.next == NULL);
    assert(n0.next == &n1);
    assert(n5.next == &n2);
    assert(n6.next == &n3);

    printf("Passed!\n");
}

void testMergeSorted5(void) {
    struct node n3 = {30, NULL};
    struct node n2 = {20, &n3};
    struct node n1 = {10, &n2};

    printf("Testing merge sorted.\nList 1:\n");
    printlist(NULL);
    printf("\nList 2:\n");
    printlist(&n1);
    printf("\n");

    struct node *merged = merge_sorted(&n1, NULL);

    printf("Merged:");
    printlist(merged);
    printf("\n");

    assert(merged == &n1);
    assert(n1.next == &n2);
    assert(n2.next == &n3);
    assert(n3.next == NULL);

    printf("Passed!\n");
}
