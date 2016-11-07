#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "linked_list.h"

void run_all_tests() {
    test_new_list();
    test_push_front();
    test_push_back();
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
