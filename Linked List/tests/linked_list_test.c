#include "../linked_list.h"
#include <assert.h>
#include <stdio.h>

void append_node_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    assert(head != NULL);
    assert(head->data == 1);
    assert(head->next->data == 2);
    assert(head->next->next->data == 3);
    assert(head->next->next->next == NULL);

    free_list(&head);
    printf("append_node_test passed!\n");
}

void insert_node_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 3);
    insert_node(&head, 2, 1);

    assert(head != NULL);
    assert(head->data == 1);
    assert(head->next->data == 2);
    assert(head->next->next->data == 3);
    assert(head->next->next->next == NULL);

    free_list(&head);
    printf("insert_node_test passed!\n");
}

void find_node_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    node_t *found_node = find_node(head, 2);
    assert(found_node != NULL);
    assert(found_node->data == 2);

    found_node = find_node(head, 4);
    assert(found_node == NULL);

    free_list(&head);
    printf("find_node_test passed!\n");
}

void delete_node_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    delete_node(&head, 2);
    assert(head != NULL);
    assert(head->data == 1);
    assert(head->next->data == 3);
    assert(head->next->next == NULL);

    delete_node(&head, 1);
    assert(head != NULL);
    assert(head->data == 3);
    assert(head->next == NULL);

    delete_node(&head, 3);
    assert(head == NULL);

    printf("delete_node_test passed!\n");
}

void update_node_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    update_node(find_node(head, 2), 4);
    assert(head->next->data == 4);

    free_list(&head);
    printf("update_node_test passed!\n");
}

void print_list_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    printf("Expected output: 1 -> 2 -> 3\n");
    printf("Actual output: ");
    print_list(head);

    free_list(&head);
    printf("print_list_test passed!\n");
}

void free_list_test() {
    node_t *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    free_list(&head);
    assert(head == NULL);

    printf("free_list_test passed!\n");
}

void run_all_tests() {
    append_node_test();
    insert_node_test();
    find_node_test();
    delete_node_test();
    update_node_test();
    print_list_test();
    free_list_test();

    printf("All tests passed!\n");
}

int main() {
    run_all_tests();
    return 0;
}