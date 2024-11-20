#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../binary_search_tree.h"

void test_insert_node_recursive() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node_recursive(tree, 5);
    insert_node_recursive(tree, 3);
    insert_node_recursive(tree, 7);
    insert_node_recursive(tree, 2);
    insert_node_recursive(tree, 4);
    insert_node_recursive(tree, 6);
    insert_node_recursive(tree, 8);

    if (tree->root == NULL || tree->root->val != 5) {
        printf("Test insert_node_recursive failed: root node incorrect\n");
        exit(1);
    }
    if (tree->root->left == NULL || tree->root->left->val != 3) {
        printf("Test insert_node_recursive failed: left child of root incorrect\n");
        exit(1);
    }
    if (tree->root->right == NULL || tree->root->right->val != 7) {
        printf("Test insert_node_recursive failed: right child of root incorrect\n");
        exit(1);
    }
    if (tree->root->left->left == NULL || tree->root->left->left->val != 2) {
        printf("Test insert_node_recursive failed: left child of root incorrect\n");
        exit(1);
    }
    printf("Test insert_node_recursive passed\n");
}

void test_insert_node() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    if (tree->root == NULL || tree->root->val != 5) {
        printf("Test insert_node failed: root node incorrect\n");
        exit(1);
    }
    if (tree->root->left == NULL || tree->root->left->val != 3) {
        printf("Test insert_node failed: left child of root incorrect\n");
        exit(1);
    }
    if (tree->root->right == NULL || tree->root->right->val != 7) {
        printf("Test insert_node failed: right child of root incorrect\n");
        exit(1);
    }
    if (tree->root->left->left == NULL || tree->root->left->left->val != 2) {
        printf("Test insert_node failed: left child of root incorrect\n");
        exit(1);
    }
    printf("Test insert_node passed\n");
}

void test_search_node_recursive() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node_recursive(tree, 5);
    insert_node_recursive(tree, 3);
    insert_node_recursive(tree, 7);
    insert_node_recursive(tree, 2);
    insert_node_recursive(tree, 4);
    insert_node_recursive(tree, 6);
    insert_node_recursive(tree, 8);

    assert(search_node_recursive(tree, 5) != NULL && "Test search_node_recursive failed: could not find 5");
    assert(search_node_recursive(tree, 3) != NULL && "Test search_node_recursive failed: could not find 3");
    assert(search_node_recursive(tree, 7) != NULL && "Test search_node_recursive failed: could not find 7");
    assert(search_node_recursive(tree, 2) != NULL && "Test search_node_recursive failed: could not find 2");
    assert(search_node_recursive(tree, 4) != NULL && "Test search_node_recursive failed: could not find 4");
    assert(search_node_recursive(tree, 6) != NULL && "Test search_node_recursive failed: could not find 6");
    assert(search_node_recursive(tree, 8) != NULL && "Test search_node_recursive failed: could not find 8");
    assert(search_node_recursive(tree, 10) == NULL && "Test search_node_recursive failed: found non-existent 10");

    printf("Test search_node_recursive passed\n");
}

void test_search_node() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    assert(search_node(tree, 5) != NULL && "Test search_node failed: could not find 5");
    assert(search_node(tree, 3) != NULL && "Test search_node failed: could not find 3");
    assert(search_node(tree, 7) != NULL && "Test search_node failed: could not find 7");
    assert(search_node(tree, 2) != NULL && "Test search_node failed: could not find 2");
    assert(search_node(tree, 4) != NULL && "Test search_node failed: could not find 4");
    assert(search_node(tree, 6) != NULL && "Test search_node failed: could not find 6");
    assert(search_node(tree, 8) != NULL && "Test search_node failed: could not find 8");
    assert(search_node(tree, 10) == NULL && "Test search_node failed: found non-existent 10");

    printf("Test search_node passed\n");
}

void test_find_max_node_recursive() {
    BinarySearchTree* tree = binary_search_tree_init();
    BinaryTreeNode* max_node = NULL;

    insert_node_recursive(tree, 5);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 5 && "Test find_max_node_recursive failed: max node is not 5");

    insert_node_recursive(tree, 3);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 5 && "Test find_max_node_recursive failed: max node is not 5");

    insert_node_recursive(tree, 7);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node_recursive failed: max node is not 7");

    insert_node_recursive(tree, 2);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node_recursive failed: max node is not 7");

    insert_node_recursive(tree, 4);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node_recursive failed: max node is not 7");

    insert_node_recursive(tree, 6);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node_recursive failed: max node is not 7");

    insert_node_recursive(tree, 8);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 8 && "Test find_max_node_recursive failed: max node is not 8");

    insert_node_recursive(tree, 9);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node_recursive failed: max node is not 9");

    insert_node_recursive(tree, 0);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node_recursive failed: max node is not 9");

    insert_node_recursive(tree, 1);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node_recursive failed: max node is not 9");

    insert_node_recursive(tree, 10);
    max_node = find_max_node_recursive(tree);
    assert(max_node != NULL && max_node->val == 10 && "Test find_max_node_recursive failed: max node is not 10");

    // int total_nodes = 11;
    // levelorder_traversal(tree, total_nodes);

    printf("Test find_max_node_recursive passed\n");
}

void test_find_max_node() {
    BinarySearchTree* tree = binary_search_tree_init();
    BinaryTreeNode* max_node = NULL;

    insert_node(tree, 5);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 5 && "Test find_max_node failed: max node is not 5");

    insert_node(tree, 3);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 5 && "Test find_max_node failed: max node is not 5");

    insert_node(tree, 7);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node failed: max node is not 7");

    insert_node(tree, 2);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node failed: max node is not 7");

    insert_node(tree, 4);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node failed: max node is not 7");

    insert_node(tree, 6);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 7 && "Test find_max_node failed: max node is not 7");

    insert_node(tree, 8);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 8 && "Test find_max_node failed: max node is not 8");

    insert_node(tree, 9);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node failed: max node is not 9");

    insert_node(tree, 0);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node failed: max node is not 9");

    insert_node(tree, 1);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 9 && "Test find_max_node failed: max node is not 9");

    insert_node(tree, 10);
    max_node = find_max_node(tree);
    assert(max_node != NULL && max_node->val == 10 && "Test find_max_node failed: max node is not 10");

    // int total_nodes = 11;
    // levelorder_traversal(tree, total_nodes);

    printf("Test find_max_node passed\n");
}

void test_find_min_node_recursive() {
    BinarySearchTree* tree = binary_search_tree_init();
    BinaryTreeNode* min_node = NULL;

    insert_node_recursive(tree, 5);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 5 && "Test find_min_node failed: min node is not 5");

    insert_node_recursive(tree, 3);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 3 && "Test find_min_node failed: min node is not 3");

    insert_node_recursive(tree, 7);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 3 && "Test find_min_node failed: min node is not 3");

    insert_node_recursive(tree, 2);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node_recursive(tree, 4);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node_recursive(tree, 6);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node_recursive(tree, 8);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node_recursive(tree, 1);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 1 && "Test find_min_node failed: min node is not 1");

    printf("Test find_min_node passed\n");
}

void test_find_min_node() {
    BinarySearchTree* tree = binary_search_tree_init();
    BinaryTreeNode* min_node = NULL;

    insert_node(tree, 5);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 5 && "Test find_min_node failed: min node is not 5");

    insert_node(tree, 3);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 3 && "Test find_min_node failed: min node is not 3");

    insert_node(tree, 7);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 3 && "Test find_min_node failed: min node is not 3");

    insert_node(tree, 2);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node(tree, 4);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node(tree, 6);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node(tree, 8);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 2 && "Test find_min_node failed: min node is not 2");

    insert_node(tree, 1);
    min_node = find_min_node(tree);
    assert(min_node != NULL && min_node->val == 1 && "Test find_min_node failed: min node is not 1");

    printf("Test find_min_node passed\n");
}

void test_delete_node_recursive() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node_recursive(tree, 5);
    insert_node_recursive(tree, 3);
    insert_node_recursive(tree, 7);
    insert_node_recursive(tree, 2);
    insert_node_recursive(tree, 4);
    insert_node_recursive(tree, 6);
    insert_node_recursive(tree, 8);

    delete_node_recursive(tree, 2);
    assert(search_node(tree, 2) == NULL && "Test delete_node_recursive failed: 2 was not deleted");

    delete_node_recursive(tree, 3);
    assert(search_node(tree, 3) == NULL && "Test delete_node_recursive failed: 3 was not deleted");

    delete_node_recursive(tree, 5);
    assert(search_node(tree, 5) == NULL && "Test delete_node_recursive failed: 5 was not deleted");

    delete_node_recursive(tree, 7);
    assert(search_node(tree, 7) == NULL && "Test delete_node_recursive failed: 7 was not deleted");

    printf("Test delete_node_recursive passed\n");
}

void test_delete_node() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    delete_node(tree, 2);
    assert(search_node(tree, 2) == NULL && "Test delete_node failed: 2 was not deleted");

    delete_node(tree, 3);
    assert(search_node(tree, 3) == NULL && "Test delete_node failed: 3 was not deleted");

    delete_node(tree, 5);
    assert(search_node(tree, 5) == NULL && "Test delete_node failed: 5 was not deleted");

    delete_node(tree, 7);
    assert(search_node(tree, 7) == NULL && "Test delete_node failed: 7 was not deleted");

    printf("Test delete_node passed\n");
}

void test_inorder_traversal() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    printf("Inorder traversal: ");
    inorder_traversal(tree);
    printf("\nExpected: 2, 3, 4, 5, 6, 7, 8\n");
}

void test_preorder_traversal() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    printf("Preorder traversal: ");
    preorder_traversal(tree);
    printf("\nExpected: 5, 3, 2, 4, 7, 6, 8\n");
}

void test_postorder_traversal() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);

    printf("Postorder traversal: ");
    postorder_traversal(tree);
    printf("\nExpected: 2, 4, 3, 6, 8, 7, 5\n");
}

void test_levelorder_traversal() {
    BinarySearchTree* tree = binary_search_tree_init();
    insert_node(tree, 5);
    insert_node(tree, 3);
    insert_node(tree, 7);
    insert_node(tree, 2);
    insert_node(tree, 4);
    insert_node(tree, 6);
    insert_node(tree, 8);
    insert_node(tree, 9);
    insert_node(tree, 0);
    insert_node(tree, 1);

    int total_nodes = 10;
    char* expected = "5, 3, 7, 2, 4, 6, 8, 0, N, N, N, N, N, N, 9, N, 1";

    printf("levelorder traversal: ");
    levelorder_traversal(tree, total_nodes);
    printf("Expected: %s\n", expected);
}

void run_all_test() {
    test_insert_node_recursive();
    test_insert_node();
    test_search_node_recursive();
    test_search_node();
    test_find_max_node_recursive();
    test_find_max_node();
    test_find_min_node_recursive();
    test_find_min_node();
    test_delete_node_recursive();
    test_delete_node();
    test_inorder_traversal();
    test_preorder_traversal();
    test_postorder_traversal();
    test_levelorder_traversal();
}

int main(void) {
    run_all_test();
    printf("All tests passed!\n");
    return 0;
}