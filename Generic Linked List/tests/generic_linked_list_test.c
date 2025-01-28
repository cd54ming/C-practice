#include "generic_linked_list_test.h"
#include "../generic_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void print_int(void *data) {
    printf("%d", *(int *)data);
}

void print_double(void *data) {
    printf("%f", *(double *)data);
}

void print_float(void *data) {
    printf("%f", *(float *)data);
}

void print_char(void *data) {
    printf("%c", *(char *)data);
}

void append_node_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data3, sizeof(char));
    append_node(&head, &data4, sizeof(float));

    assert(head != NULL);
    assert(*(int *)head->data == 1);
    assert(*(double *)head->next->data == 2.5);
    assert(*(char *)head->next->next->data == 'A');
    assert(*(float *)head->next->next->next->data == 3.14f);
    assert(head->next->next->next->next == NULL);

    free_list(&head);
    printf("append_node_test passed!\n");
}

void insert_node_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data3, sizeof(char));
    insert_node(&head, &data4, sizeof(float), 1);

    assert(head != NULL);
    assert(*(int *)head->data == 1);
    assert(*(float *)head->next->data == 3.14f);
    assert(*(char *)head->next->next->data == 'A');
    assert(head->next->next->next == NULL);

    free_list(&head);
    printf("insert_node_test passed!\n");
}

void find_node_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data4, sizeof(float));

    node_t *found_node = find_node(head, &data2, sizeof(double));
    assert(found_node != NULL);
    assert(*(double *)found_node->data == 2.5);

    char data_not_found = 'Z';
    found_node = find_node(head, &data_not_found, sizeof(char));
    assert(found_node == NULL);

    free_list(&head);
    printf("find_node_test passed!\n");
}

void update_node_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;
    double new_data = 4.5;

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data4, sizeof(float));

    node_t *node_to_update = find_node(head, &data2, sizeof(double));
    update_node(node_to_update, &new_data, sizeof(double));
    assert(*(double *)node_to_update->data == 4.5);

    free_list(&head);
    printf("update_node_test passed!\n");
}

void delete_node_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data4, sizeof(float));

    delete_node(&head, &data2, sizeof(double));
    assert(head != NULL);
    assert(*(int *)head->data == 1);
    assert(*(float *)head->next->data == 3.14f);
    assert(head->next->next == NULL);

    delete_node(&head, &data1, sizeof(int));
    assert(head != NULL);
    assert(*(float *)head->data == 3.14f);
    assert(head->next == NULL);

    delete_node(&head, &data4, sizeof(float));
    assert(head == NULL);

    printf("delete_node_test passed!\n");
}

void print_list_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data3, sizeof(char));

    printf("Expected output: 1 -> 2.500000 -> A\n");
    printf("Actual output: ");
    void (*print_funcs[])(void *) = {print_int, print_double, print_char};
    print_list(head, print_funcs);

    free_list(&head);
    printf("print_list_test passed!\n");
}

void free_list_test() {
    node_t *head = NULL;
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';

    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data3, sizeof(char));

    free_list(&head);
    assert(head == NULL);

    printf("free_list_test passed!\n");
}

void run_all_tests() {
    append_node_test();
    insert_node_test();
    find_node_test();
    update_node_test();
    delete_node_test();
    print_list_test();
    free_list_test();

    printf("All tests passed!\n");
}

int main() {
    run_all_tests();
    return 0;
}