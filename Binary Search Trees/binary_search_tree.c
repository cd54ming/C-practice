#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"

typedef struct QueueNode {
    BinaryTreeNode* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    int size;
    QueueNode* front;
    QueueNode* rear;
} Queue;

static Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

static QueueNode* queue_create_node(BinaryTreeNode* node) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = node;
    new_node->next = NULL;
    return new_node;
}

static bool queue_is_empty(Queue* queue) {
    return (queue->front == NULL);
}

static void queue_enqueue(Queue* queue, BinaryTreeNode* node) {
    QueueNode* new_node = queue_create_node(node);

    if (queue_is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

static BinaryTreeNode* queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue)) {
        return NULL;
    }

    QueueNode* temp = queue->front;
    BinaryTreeNode* retval = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;

    return retval;
}

static void queue_free(Queue* queue) {
    QueueNode* current = queue->front;
    QueueNode* prev;

    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }

    free(queue);
}

BinarySearchTree* binary_search_tree_init() {
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

BinaryTreeNode* binary_tree_create_node(int val) {
    BinaryTreeNode* new_node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

static BinaryTreeNode* insert_node_helper(BinaryTreeNode* root, BinaryTreeNode* node) {
    if (root == NULL) {
        return node;
    }

    if (node->val < root->val) {
        root->left = insert_node_helper(root->left, node);
    } else if (node->val > root->val) {
        root->right = insert_node_helper(root->right, node);
    }

    return root;
}

BinaryTreeNode* insert_node_recursive(BinarySearchTree* tree, int val) {
    BinaryTreeNode* new_node = binary_tree_create_node(val);
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        tree->root = insert_node_helper(tree->root, new_node);
    }
    return new_node;
}

BinaryTreeNode* insert_node(BinarySearchTree* tree, int val) {
    BinaryTreeNode* new_node = binary_tree_create_node(val);

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        BinaryTreeNode* parent_node = NULL;
        BinaryTreeNode* current_node = tree->root;

        while (current_node != NULL) {
            parent_node = current_node;
            if (val > current_node->val) {
                current_node = current_node->right;
            } else if (val < current_node->val) {
                current_node = current_node->left;
            } else {
                printf("node is already exist.\n");
                // remember to free the new node
                free(new_node);
                return current_node;
            }
        }
        if (val > parent_node->val) {
            parent_node->right = new_node;
        } else {
            parent_node->left = new_node;
        }
    }

    return new_node;
}

BinaryTreeNode* search_node_helper(BinaryTreeNode* node, int val) {
    if (node == NULL) {
        return NULL;
    }

    if (node->val == val) {
        return node;
    }

    return (val > node->val)
        ? search_node_helper(node->right, val)
        : search_node_helper(node->left, val);
}

BinaryTreeNode* search_node_recursive(BinarySearchTree* tree, int val) {
    if (tree->root == NULL) {
        return NULL;
    }

    return search_node_helper(tree->root, val);
}

BinaryTreeNode* search_node(BinarySearchTree* tree, int val) {
    if (tree->root == NULL) {
        return NULL;
    }

    BinaryTreeNode* current_node = tree->root;
    while (current_node != NULL) {
        if (current_node->val == val) {
            return current_node;
        }
        current_node = (val > current_node->val) ? current_node->right : current_node->left;
    }

    return NULL;
}

static BinaryTreeNode* find_max_node_helper(BinaryTreeNode* node) {
    if (node->right == NULL) {
        return node;
    }

    return find_max_node_helper(node->right);
}

BinaryTreeNode* find_max_node_recursive(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return NULL;
    }

    return find_max_node_helper(tree->root);
}

BinaryTreeNode* find_max_node(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return NULL;
    }

    BinaryTreeNode* max_node = tree->root;
    while (max_node->right) {
        max_node = max_node->right;
    }

    return max_node;
}

static BinaryTreeNode* find_min_node_helper(BinaryTreeNode* node) {
    if (node->left == NULL) {
        return node;
    }

    return find_min_node_helper(node->left);
}

BinaryTreeNode* find_min_node_recursive(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return NULL;
    }

    return find_min_node_helper(tree->root);
}

BinaryTreeNode* find_min_node(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return NULL;
    }

    BinaryTreeNode* min_node = tree->root;
    while (min_node->left) {
        min_node = min_node->left;
    }

    return min_node;
}

void replace_and_free(BinaryTreeNode** parent_link, BinaryTreeNode* new_node) {
    BinaryTreeNode* old_node = *parent_link;
    *parent_link = new_node;
    free(old_node);
}

static void delete_node_helper(BinaryTreeNode** parent_link, BinaryTreeNode* node, int val) {
    if (node == NULL) {
        return;
    }

    if (node->val == val) {
        if (node->left == NULL || node->right == NULL) {
            BinaryTreeNode* replacement = (node->left != NULL) ? node->left : node->right;
            replace_and_free(parent_link, replacement);
        } else {
            BinaryTreeNode* left_max_node = find_max_node_helper(node->left);
            node->val = left_max_node->val;
            delete_node_helper(&node->left, node->left, left_max_node->val);
        }
    } else if (val > node->val) {
        delete_node_helper(&node->right, node->right, val);
    } else {
        delete_node_helper(&node->left, node->left, val);
    }
}

void delete_node_recursive(BinarySearchTree* tree, int val) {
    if (tree->root == NULL) {
        return;
    }

    delete_node_helper(&tree->root, tree->root, val);
}

void delete_node(BinarySearchTree* tree, int val) {
    if (tree->root == NULL) {
        return;
    }

    BinaryTreeNode** current_node_parent_link = &tree->root;
    BinaryTreeNode* current_node = tree->root;
    while (current_node != NULL) {
        if (current_node->val == val) {
            if (current_node->left == NULL || current_node->right == NULL) {
                *current_node_parent_link = (current_node->left != NULL) ? current_node->left : current_node->right;
                free(current_node);
                return;
            } else {
                BinaryTreeNode* right_min_node = find_min_node_helper(current_node->right);
                current_node->val = right_min_node->val;
                BinarySearchTree* right_subtree = binary_search_tree_init();
                right_subtree->root = current_node->right;
                delete_node(right_subtree, right_min_node->val);
                return;
            }
        }

        if (val > current_node->val) {
            current_node_parent_link = &(current_node->right);
            current_node = current_node->right;
        } else {
            current_node_parent_link = &(current_node->left);
            current_node = current_node->left;
        }
    }

    return;
}

static void inorder_traversal_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return;
    }

    inorder_traversal_helper(node->left);
    printf("%d ", node->val);
    inorder_traversal_helper(node->right);
}

void inorder_traversal(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return;
    }

    inorder_traversal_helper(tree->root);
}

static void preorder_traversal_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->val);
    preorder_traversal_helper(node->left);
    preorder_traversal_helper(node->right);
}

void preorder_traversal(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return;
    }

    return preorder_traversal_helper(tree->root);
}

static void postorder_traversal_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return;
    }

    postorder_traversal_helper(node->left);
    postorder_traversal_helper(node->right);
    printf("%d ", node->val);
}

void postorder_traversal(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        return;
    }

    postorder_traversal_helper(tree->root);
}

void levelorder_traversal(BinarySearchTree* tree, int total_nodes) {
    if (tree->root == NULL) {
        printf("tree is empty\n");
        return;
    }

    int printed_nodes = 0;
    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (printed_nodes < total_nodes) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node == NULL) {
            printf(" ,N");
            queue_enqueue(queue, NULL);
            queue_enqueue(queue, NULL);
        } else {
            if (printed_nodes != 0) {
                printf(" ,");
            }
            printf("%d", current_node->val);
            printed_nodes++;
            queue_enqueue(queue, current_node->left);
            queue_enqueue(queue, current_node->right);
        }
    }
    printf("\n");
}
