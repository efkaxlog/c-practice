#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node Node;

struct Node{
    int data;
    Node *next;
};

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

// constructs a new Node
Node* Node_new(int data);

// creates a linked list and returns the pointer to it
LinkedList* new_list();

// inserts a node into a list that is supposed to be empty
void insert_first(LinkedList *list, Node *node);

// frees all memory taken allocated for the list
void destroy_list(LinkedList *list);

// prints all data from head to tail
void print_list(LinkedList *list);

// inserts a new Node at the front of the list
void push_front(LinkedList *list, int data);

// inserts a new Node at the back of the list
void push_back(LinkedList *list, int data);

// returns the number of nodes in a list
int size(LinkedList *list);

// checks whether list is empty
int empty(LinkedList *list);

// returns data variable from Node struct at an index from the list
// does not have any out of bounds error checks
// returns -1 if bad index (very bad, fix later)
int value_at(LinkedList *list, int index);



#endif // LINKED_LIST_H
