#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node_t {
    int data;
    struct node_t *next;
} node_t;

node_t *append_node(node_t **head, int data);
node_t *insert_node(node_t **head, int data, unsigned int position);
node_t *find_node(node_t *head, int data);
void delete_node(node_t **head, int data);
void update_node(node_t *node, int data);
void print_list(node_t *head);
void free_list(node_t **head);

#endif