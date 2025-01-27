#include "linked_list.h"
#include <stdio.h>

void example() {
    node_t *head = NULL;

    // 添加節點
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);
    printf("After appending nodes: ");
    print_list(head);

    // 插入節點
    insert_node(&head, 4, 1); // 在位置 1 插入節點 4
    printf("After inserting node 4 at position 1: ");
    print_list(head);

    // 查找節點
    node_t *found_node = find_node(head, 2);
    if (found_node) {
        printf("Node with data 2 found.\n");
    } else {
        printf("Node with data 2 not found.\n");
    }

    // 更新節點
    update_node(found_node, 5);
    printf("After updating node 2 to 5: ");
    print_list(head);

    // 刪除節點
    delete_node(&head, 1);
    printf("After deleting node with data 1: ");
    print_list(head);

    // 釋放鏈表
    free_list(&head);
    printf("After freeing the list: ");
    print_list(head);
}

int main() {
    example();
    return 0;
}