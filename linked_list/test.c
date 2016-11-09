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
    test_remove_node();
    test_pop_front();
    test_pop_back();
    test_front_value();
    test_back_value();
    test_remove_value();
    test_value_n_from_end();
    test_reverse();
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
    insert(list, 0, 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 1);
    insert(list, 1, 2);
    assert(list->head->data == 1);
    assert(value_at(list, 1) == 2);
    assert(list->tail->data == 2);
    destroy_list(list);
}


void test_remove_node() {
    LinkedList *list = new_list();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    remove_node(list, 0);
    assert(list->head->data == 2);
    push_back(list, 4);
    push_back(list, 5); // list now 2, 3, 4, 5
    remove_node(list, 3); // index 3, value 5
    assert(list->tail->data == 4);
    remove_node(list, 1); // list now 2, 4
    assert(list->head->data == 2);
    assert(list->tail->data == 4);
    assert(size(list) == 2);
    destroy_list(list);
}

void test_pop_front() {
    LinkedList *list = new_list();
    assert(pop_front(list) == -1); // empty list
    push_back(list, 1);
    assert(pop_front(list) == 1);
    assert(list->head == 0);
    assert(list->tail == 0);
    assert(size(list) == 0);
    push_back(list, 1);
    push_back(list, 2);
    assert(pop_front(list) == 1);
    assert(list->head == list->tail); // 1 node in list
    assert(size(list) == 1);
    assert(value_at(list, 0) == 2);
    assert(list->head->data == 2);
    assert(pop_front(list) == 2);
    destroy_list(list);
}

void test_pop_back() {
    LinkedList *list = new_list();
    assert(pop_back(list) == -1); // empty list
    push_back(list, 1);
    assert(pop_back(list) == 1);
    assert(list->head == 0);
    assert(list->tail == 0);
    assert(size(list) == 0);
    push_back(list, 1);
    push_back(list, 2);
    assert(pop_back(list) == 2);
    assert(list->head == list->tail); // 1 node in list
    assert(size(list) == 1);
    assert(value_at(list, 0) == 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 1);
    assert(pop_front(list) == 1);
    destroy_list(list);
}

void test_front_value() {
    LinkedList *list = new_list();
    assert(front_value(list) == -1);
    push_back(list, 1);
    assert(front_value(list) == 1);
    destroy_list(list);
}

void test_back_value() {
    LinkedList *list = new_list();
    assert(back_value(list) == -1);
    push_back(list, 1);
    assert(back_value(list) == 1);
    destroy_list(list);
}

void test_remove_value() {
    LinkedList *list = new_list();
    for (int i=1; i<6; i++) {
        push_back(list, i);
    }
    remove_value(list, 1);
    assert(list->head->data == 2);
    remove_value(list, 5);
    assert(list->tail->data == 4);
    remove_value(list, 3);
    assert(list->head->next == list->tail);
    destroy_list(list);
}

void test_value_n_from_end() {
    LinkedList *list = new_list();
    for (int i=1; i<11; i++) {
        push_back(list, i);
    }
    assert(value_n_from_end(list, 9) == list->head->data);
    assert(value_n_from_end(list, 0) == list->tail->data);
    assert(value_n_from_end(list, 1) == 9);
    assert(value_n_from_end(list, 5) == 5);
    destroy_list(list);
}

void test_reverse() {
    LinkedList *list = new_list();
    for (int i=0; i<10; i++) {
        push_back(list, i);
    }
    reverse(&list);
    assert(list->head->data == 9);
    assert(list->tail->data == 0);
    destroy_list(list);
}
