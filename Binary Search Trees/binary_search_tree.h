
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct BinaryTreeNode {
  int val;
  struct BinaryTreeNode* left;
  struct BinaryTreeNode* right;
} BinaryTreeNode;

typedef struct BinarySearchTree {
  BinaryTreeNode* root;
} BinarySearchTree;

BinarySearchTree* binary_search_tree_init();

BinaryTreeNode* insert_node_recursive(BinarySearchTree* tree, int val);

BinaryTreeNode* insert_node(BinarySearchTree* tree, int val);

BinaryTreeNode* search_node_recursive(BinarySearchTree* tree, int val);

BinaryTreeNode* search_node(BinarySearchTree* tree, int val);

BinaryTreeNode* find_max_node_recursive(BinarySearchTree* tree);

BinaryTreeNode* find_max_node(BinarySearchTree* tree);

BinaryTreeNode* find_min_node_recursive(BinarySearchTree* tree);

BinaryTreeNode* find_min_node(BinarySearchTree* tree);

void delete_node_recursive(BinarySearchTree* tree, int val);

void delete_node(BinarySearchTree* tree, int val);

void inorder_traversal(BinarySearchTree* tree);

void preorder_traversal(BinarySearchTree* tree);

void postorder_traversal(BinarySearchTree* tree);

void levelorder_traversal(BinarySearchTree* tree, int total_nodes);
#endif // BINARY_SEARCH_TREE_H