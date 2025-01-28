#include "generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// 函式指標的列印函式
void print_int(void *data) {
    printf("%d", *(int *)data);
}

void print_float(void *data) {
    printf("%.2f", *(float *)data);
}

void print_double(void *data) {
    printf("%.2f", *(double *)data);
}

void print_char(void *data) {
    printf("%c", *(char *)data);
}

// 動態調整函式指標陣列大小
void resize_function_array(void (***func_array)(void *), size_t count) {
    void (**new_func_array)(void *) = realloc(*func_array, count * sizeof(void (*)(void *)));
    if (!new_func_array) {
        fprintf(stderr, "Failed to allocate memory for new function array.\n");
        free(*func_array);
        exit(EXIT_FAILURE);
    }

    *func_array = new_func_array;
}

// 範例函式
void example() {
    node_t *head = NULL;

    // 節點資料
    int data1 = 1;
    double data2 = 2.5;
    char data3 = 'A';
    float data4 = 3.14f;

    // 初始化函式指標陣列
    size_t func_count = 4;
    void (**print_funcs)(void *) = NULL;
    resize_function_array(&print_funcs, func_count);

    // 添加節點
    append_node(&head, &data1, sizeof(int));
    append_node(&head, &data2, sizeof(double));
    append_node(&head, &data3, sizeof(char));
    append_node(&head, &data4, sizeof(float));

    // 配置函式指標
    print_funcs[0] = print_int;
    print_funcs[1] = print_double;
    print_funcs[2] = print_char;
    print_funcs[3] = print_float;

    // 列印節點
    printf("After appending nodes: ");
    print_list(head, print_funcs);

    // 插入節點
    float data5 = 4.56f;
    insert_node(&head, &data5, sizeof(float), 2);
    resize_function_array(&print_funcs, ++func_count);
    print_funcs[2] = print_float;
    print_funcs[3] = print_char;
    print_funcs[4] = print_float;
    printf("After inserting node: ");
    print_list(head, print_funcs);

    // 查找節點
    node_t *found_node = find_node(head, &data2, sizeof(double));
    if (found_node) {
        printf("Node with data 2.5 found.\n");
    } else {
        printf("Node with data 2.5 not found.\n");
    }

    // 更新節點
    float new_data = 5.5f;
    update_node(found_node, &new_data, sizeof(float));
    print_funcs[1] = print_float;
    printf("After updating node: ");
    print_list(head, print_funcs);

    // 刪除節點
    delete_node(&head, &data1, sizeof(int));
    resize_function_array(&print_funcs, --func_count);
    print_funcs[0] = print_float;
    print_funcs[1] = print_float;
    print_funcs[2] = print_char;
    print_funcs[3] = print_float;
    printf("After deleting node with data 1: ");
    print_list(head, print_funcs);

    // 釋放記憶體
    free_list(&head);
    free(print_funcs);
    printf("After freeing the list: ");
    print_list(head, print_funcs);
}

int main() {
    example();
    return 0;
}
