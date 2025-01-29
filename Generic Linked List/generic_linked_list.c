#include "generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static node_t *create_node(void *data, size_t size) {
    if (!data) {
        printf("data is NULL.\n");
        return NULL;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = malloc(size);
    if (!(new_node->data)) {
        fprintf(stderr, "Failed to allocate memory for new node data.\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, data, size);

    new_node->next = NULL;
    return new_node;
}

static void destroy_node(node_t **node) {
    if (!node || !(*node)) {
        return;
    }

    free((*node)->data);
    free(*node);
    *node = NULL;
}

node_t *append_node(node_t **head, void *data, size_t size) {
    if (!head || !data) {
        fprintf(stderr, "Error: Head pointer or data is NULL.\n");
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
    if (!head || !data) {
        printf("Insert node head is NULL.\n");
        return NULL;
    }

    node_t *new_node = create_node(data, size);
    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    node_t *prev = *head;
    for (unsigned int i = 0; i < (position - 1); i++) {
        prev = prev->next;
        if (!prev) {
            printf("Insert node out of bound.\n");
            destroy_node(&new_node);
            return NULL;
        }
    }
    new_node->next = prev->next;
    prev->next = new_node;

    return new_node;
}

node_t *find_node(node_t *head, void *data, size_t size) {
    if (!head) {
        printf("Find node head is NULL.\n");
        return NULL;
    }

    node_t *current = head;
    while (current) {
        if (memcmp(current->data, data, size) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

node_t *update_node(node_t *node, void *data, size_t size) {
    if (!node || !data) {
        fprintf(stderr, "Error: Node or data is NULL.\n");
        return NULL;
    }

    void *new_data = realloc(node->data, size);
    if (!new_data) {
        fprintf(stderr, "Failed to allocate memory for new data.\n");
        return node;
    }
    memcpy(new_data, data, size);
    node->data = new_data;

    return node;
}

void delete_node(node_t **head, void *data, size_t size) {
    if (!head || !(*head)) {
        printf("List is empty.\n");
        return;
    }

    node_t *current = *head;
    if (memcmp(current->data, data, size) == 0) {
        *head = (*head)->next;
        destroy_node(&current);
        return;
    }

    node_t *prev = current;
    current = current->next;
    while (current) {
        if (memcmp(current->data, data, size) == 0) {
            prev->next = current->next;
            destroy_node(&current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

void print_list(node_t *head, void (*print_funcs[])(void *)) {
    if (!head) {
        printf("Print list head does not exists.\n");
        return;
    }

    node_t *current = head;
    int index = 0;
    while (current) {
        if (!print_funcs[index]) {
            fprintf(stderr, "Error: Missing print function for node %d\n", index);
            return;
        }
        print_funcs[index](current->data);

        if (current->next) {
            printf(" -> ");
        }

        current = current->next;
        index++;
    }
    printf("\n");
}

void free_list(node_t **head) {
    while (*head) {
        node_t *current = *head;
        *head = (*head)->next;
        destroy_node(&current);
    }
    *head = NULL;
}