#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    void *data;
} node_t;

int compare_nodes(const void *a, const void *b) {
    int data_a = *((int *)(((node_t *)a)->data));
    int data_b = *((int *)(((node_t *)b)->data));
    return (data_a > data_b) - (data_a < data_b);
}

// * my_qsort supports sorting structure types.
void example() {
    int values[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(values) / sizeof(values[0]);

    node_t nodes[n];
    for (size_t i = 0; i < n; i++) {
        nodes[i].data = &values[i];
    }

    printf("Before sorting:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", *((int *)nodes[i].data));
    }
    printf("\n");

    qsort(nodes, n, sizeof(node_t), compare_nodes);

    printf("After sorting:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", *((int *)nodes[i].data));
    }
    printf("\n");
}

int main(void) {
    example();
    return 0;
}