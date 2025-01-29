#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

#include <stddef.h>

typedef struct node_t {
    void *data;
    struct node_t *next;
} node_t;

node_t *append_node(node_t **head, void *data, size_t size);
node_t *insert_node(node_t **head, void *data, size_t size, unsigned int position);
node_t *find_node(node_t *head, void *data, size_t size);
node_t *update_node(node_t *node, void *data, size_t size);
void delete_node(node_t **head, void *data, size_t size);
void print_list(node_t *head, void (*print_func[])(void *));
void free_list(node_t **head);

#endif