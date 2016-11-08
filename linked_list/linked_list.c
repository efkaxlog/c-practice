#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* Node_new(int data) {                
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;                
    return new_node;                      
}                                         

LinkedList* new_list() {                          
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = 0;
    list->tail = 0;
    return list;                                  
}

void insert_first(LinkedList *list, Node *node) {
    list->head = node;
    list->tail = node;
}

void destroy_list(LinkedList *list) {
    Node *node = list->head;
    Node *next;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void print_list(LinkedList *list) {
    Node *node = list->head;
    while (node != 0) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void push_front(LinkedList *list, int data) {
    Node *head = list->head;
    Node *new_node = Node_new(data);
    new_node->next = head;
    list->head = new_node;
    if (!list->tail) {
        list->tail = new_node;
    }
}

void push_back(LinkedList *list, int data) {
    Node *new_node = Node_new(data);
    new_node->next = 0;
    if (!list->head) {
        insert_first(list, new_node);
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

int size(LinkedList *list) {
    int size = 0;
    Node *node = list->head;
    while (node) {
        size++;
        node = node->next;
    }
    return size;
}

int empty(LinkedList *list) {
    return !list->head;
}

int value_at(LinkedList *list, int index) {
    Node *node = list->head;
    int i = 0;
    while (node && i <= index) {
        if (i == index) {
            return node->data;
        }
        node = node->next;
        i++;
    }
    return -1;
}

void insert(LinkedList *list, int index, int value) {
    Node *new_node = Node_new(value);
    Node *current = list->head;

    if (index == 0) {
        push_front(list, value);
        return;
    }

    int i = 0;
    while (current) {
        if (index - i == 1) {
            new_node->next = current->next;
            current->next = new_node;
            if (!new_node->next) {
                list->tail = new_node;
            }
            break;
        }
        current = current->next;
        i++;
    }
    // if got here index was larger than nodes in list
}
