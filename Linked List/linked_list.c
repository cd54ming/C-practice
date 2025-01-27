#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node_t *append_node(node_t **head, int data) {
    node_t *new_node = create_node(data);

    if (*head == NULL) {
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

node_t *insert_node(node_t **head, int data, unsigned int position) {
    node_t *new_node = create_node(data);

    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    node_t *current = *head;
    for (unsigned int i = 0; (current != NULL) && (i < position - 1); i++) {
        current = current->next;
    }

    if (!current) {
        free(new_node);
        printf("Position out of bounds\n");
        return NULL;
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}

node_t *find_node(node_t *head, int data) {
    node_t *current = head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    return current;
}

void delete_node(node_t **head, int data) {
    if (*head == NULL) {
        printf("list is empty.\n");
        return;
    }

    node_t *target_node = *head;
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(target_node);
        return;
    }

    node_t *prev_node = NULL;
    while (target_node && target_node->data != data) {
        prev_node = target_node;
        target_node = target_node->next;
    }

    if (!target_node) {
        printf("Value %d not found in the list\n", data);
        return;
    }

    prev_node->next = target_node->next;
    free(target_node);
}

void update_node(node_t *node, int data) {
    if (!node) {
        printf("Node does not exist.\n");
        return;
    }

    node->data = data;
}

void print_list(node_t *head) {
    if (!(head)) {
        printf("List is empty.\n");
        return;
    }

    node_t *current = head;
    while (current) {
        printf("%d", current->data);
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
        free(temp);
    }
    *head = NULL;
}