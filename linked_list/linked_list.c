#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* Node_new(int data) {                
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;                
    new_node->next = 0;
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
    printf("\n");
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
    Node *current = list->head;
    if (index == 0) {
        push_front(list, value);
        return;
    }
    Node *new_node = Node_new(value);
    int i = 0;
    while (current) {
        if (index - i == 1) {
            new_node->next = current->next;
            current->next = new_node;
            if (!new_node->next) {
                list->tail = new_node;
            }
            return;
        }
        current = current->next;
        i++;
    }
    // if got here index was larger than nodes in list
}

void remove_node(LinkedList *list, int index) {
    if (empty(list)) {
        return;
    }
    Node *current = list->head;
    if (index == 0 && current) {
        if (current == list->tail) {
            list->tail = 0;
        }   
        list->head = current->next;
        free(current);
        return;
    }
    int i = 0;
    while (current) {
        if (index - i == 1) {
            Node *next = current->next;
            if (next == list->tail) {
                free(list->tail);
                current->next = 0;
                list->tail = current;
            } else {
                current->next = next->next;
                free(next);
            }
            return;
        }
        current = current->next;
        i++;
    }
}

int pop_front(LinkedList *list) {
    Node *head = list->head;
    if (head) {
        int data = head->data;
        remove_node(list, 0);
        return data;
    }
    return -1;
}

int pop_back(LinkedList *list) {
    Node *tail = list->tail;
    if (tail) {
        int data = tail->data;
        Node *current = list->head;
        if (current == tail) {
            remove_node(list, 0);
            return data;
        }
        int i = 0;
        while (current) {
            if (current->next == tail) {
                remove_node(list, i+1);
            }
            current = current->next;
            i++;
        }
        return data;
    }
    return -1;
}

int front_value(LinkedList *list) {
    if (list->head) {
        return list->head->data;
    }
    return -1;
}

int back_value(LinkedList *list) {
    if (list->tail) {
        return list->tail->data;
    }
    return -1;
}

void remove_value(LinkedList *list, int value) {
    Node *node = list->head;
    int i = 0;
    while (node) {
        if (node->data == value) {
            remove_node(list, i);
            return;
        }
        node = node->next;
        i++;
    }
}

int value_n_from_end(LinkedList *list, int index) {
    int real_index = (size(list) - 1) - index;
    return value_at(list, real_index);
}

void reverse(LinkedList **list) {
    LinkedList *reversed = new_list();
    Node *node = (*list)->head;
    while (node) {
        push_front(reversed, node->data);
        node = node->next;
    }
    destroy_list(*list);
    *list = reversed;
}
