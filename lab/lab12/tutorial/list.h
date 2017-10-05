struct node {
	int data;
	struct node *next;
};

void printlist(struct node *list);
int member(int value, struct node *list);
struct node *list_append(struct node *base, struct node *toAppend);
struct node *insert_ordered(int item, struct node *list);
struct node *merge_sorted(struct node *list1, struct node *list2);

