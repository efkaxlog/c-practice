#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "linked_list.h"

void run_all_tests() {
    test_new_list();
    test_push_front();
    test_push_back();
    test_size();
    test_empty();
    test_value_at();
    test_insert();
}

void test_new_list() {
    LinkedList* list = new_list();
    assert(list->head == 0);
    assert(list->tail == 0);
    free(list);
}

void test_push_front() {
    LinkedList *list = new_list();
    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 3);
    assert(list->head->data == 3);
    assert(list->head->next->data == 2);
    assert(list->tail->data == 1);
    destroy_list(list);
}

void test_push_back() {
    LinkedList *list = new_list();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    assert(list->head->data == 1);
    assert(list->head->next->data == 2);
    assert(list->tail->data == 3);
    destroy_list(list);
}

void test_size() {
    LinkedList *list = new_list();
    int nodes = 10;
    for (int i=0; i<nodes; i++) {
        push_back(list, i);
    }
    assert(size(list) == 10);
    destroy_list(list);
}

void test_empty() {
    LinkedList *list = new_list();
    assert(empty(list) == 1);
    destroy_list(list);
}

void test_value_at() {
    LinkedList *list = new_list();
    push_back(list, 5);
    push_back(list, 10);
    push_back(list, 15);
    assert(value_at(list, 0) == 5);
    assert(value_at(list, 1) == 10);
    assert(value_at(list, 2) == 15);
    destroy_list(list);
}

void test_insert() {
    LinkedList *list = new_list();
    insert(list, 0, 0);
    assert(list->head->data == 0);
    assert(list->tail->data == 0);
    insert(list, 0, 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 0);
    insert(list, 1, 2);
    assert(list->head->data == 1);
    assert(value_at(list, 1) == 2);
    assert(list->tail->data == 0);
    destroy_list(list);
}
