#include "generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static node_t *create_node(void *data, size_t size) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(size);
    if (!new_node->data) {
        fprintf(stderr, "Failed to allocate memory for new node data.\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, data, size);
    new_node->next = NULL;

    return new_node;
}

static void destroy_node(node_t **node) {
    if (!node || !*node)
        return;

    free((*node)->data);
    free(*node);
    *node = NULL;
}

node_t *append_node(node_t **head, void *data, size_t size) {
    if (!head) {
        fprintf(stderr, "Invalid head pointer.\n");
        return NULL;
    }

    node_t *new_node = create_node(data, size);

    if (!(*head)) {
        *head = new_node;
        return new_node;
    }

    node_t *tail = *head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = new_node;
    return new_node;
}

node_t *insert_node(node_t **head, void *data, size_t size, unsigned int position) {
    node_t *new_node = create_node(data, size);

    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    node_t *prev_node = *head;
    for (unsigned int i = 0; i < (position - 1); i++) {
        prev_node = prev_node->next;
        if (!prev_node) {
            printf("Position out of bounds\n");
            destroy_node(&new_node);
            return NULL;
        }
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return new_node;
}

node_t *find_node(node_t *head, void *data, size_t size) {
    node_t *current = head;

    while (current) {
        if (memcmp(current->data, data, size) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void update_node(node_t *node, void *data, size_t size) {
    if (!node || !data) {
        printf("Invalid input.\n");
        return;
    }

    void *new_data = malloc(size);
    if (!new_data) {
        fprintf(stderr, "Failed to allocate memory for new data.\n");
        return;
    }

    memcpy(new_data, data, size);
    free(node->data);
    node->data = new_data;
}

void delete_node(node_t **head, void *data, size_t size) {
    if (!head || !(*head)) {
        printf("List is empty.\n");
        return;
    }

    if (memcmp((*head)->data, data, size) == 0) {
        node_t *temp = *head;
        *head = (*head)->next;
        destroy_node(&temp);
        return;
    }

    node_t *target = *head;
    node_t *prev = NULL;

    while (target && memcmp(target->data, data, size)) {
        prev = target;
        target = target->next;
    }

    if (!target) {
        printf("not found target\n");
        return;
    }

    prev->next = target->next;
    destroy_node(&target);
}

void print_list(node_t *head, void (*print_funcs[])(void *)) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    node_t *current = head;
    int index = 0;

    while (current) {
        if (!print_funcs[index]) {
            fprintf(stderr, "Error: Missing print function for node %d\n", index);
            return;
        }
        print_funcs[index++](current->data);

        if (current->next) {
            printf(" -> ");
        }

        current = current->next;
    }
    printf("\n");
}

void free_list(node_t **head) {
    while (*head) {
        node_t *temp = *head;
        *head = (*head)->next;
        destroy_node(&temp);
    }

    *head = NULL;
}