#include "qsort_test.h"
#include "../qsort.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct node_t {
    void *data;
    double other_data_1;
    int other_data_2;
    float other_data_3;
} node_t;

static int struct_cmp(const void *a, const void *b) {
    return *(int *)(((node_t *)a)->data) - *(int *)(((node_t *)b)->data);
}

static int char_cmp(const void *a, const void *b) {
    return (*(char *)a) - (*(char *)b);
}

static int double_cmp(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    if (fabs(diff) < 1e-9)
        return 0;
    return (diff > 0) - (diff < 0);
}

static int int_cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

static void qsort_struct_test() {
    int fore_node_data[] = {4, 3, 2, 0, 9, 8, 4, 7, 6, 1, 5};
    int arr_count = sizeof(fore_node_data) / sizeof(fore_node_data[0]);
    node_t node_arr[arr_count];
    for (int i = 0; i < arr_count; i++) {
        node_arr[i] =
            (node_t){.data = &fore_node_data[i], .other_data_1 = i * 1.0, .other_data_2 = i, .other_data_3 = i * 1.0f};
    }

    printf("========================================\n");
    printf("  📌 Sorting Struct Array (qsort)  \n");
    printf("========================================\n");

    printf("🔹 Before Sorting:   ");
    for (int i = 0; i < arr_count; i++) {
        printf("%d ", *(int *)(node_arr[i].data));
    }
    printf("\n");

    my_qsort(node_arr, arr_count, sizeof(node_arr[0]), struct_cmp);

    printf("🔹 After Sorting:    ");
    for (int i = 0; i < arr_count; i++) {
        printf("%d ", *(int *)(node_arr[i].data));
    }
    printf("\n========================================\n\n");
}

static void qsort_char_test() {
    char arr[] = "SortThisString";
    int arr_count = strlen(arr); // exclude '/0'

    printf("========================================\n");
    printf("  📌 Sorting Character Array (qsort)  \n");
    printf("========================================\n");

    printf("🔹 Before Sorting:   ");
    for (int i = 0; i < arr_count; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    my_qsort(arr, arr_count, sizeof(arr[0]), char_cmp);

    printf("🔹 After Sorting:    ");
    for (int i = 0; i < arr_count; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n========================================\n\n");
}

static void qsort_double_test() {
    double arr[] = {0.309, 2.505, 2.702, 4.259, 3.194, 8.231, 7.554, 1.044, 5.919};
    int arr_count = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("  📌 Sorting Double Array (qsort)  \n");
    printf("========================================\n");

    printf("🔹 Before Sorting:   ");
    for (int i = 0; i < arr_count; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    my_qsort(arr, arr_count, sizeof(arr[0]), double_cmp);

    printf("🔹 After Sorting:    ");
    for (int i = 0; i < arr_count; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n========================================\n\n");
}

static void qsort_int_test() {
    int arr[] = {0, 2, 8, 4, 7, 9, 1, 6, 5};
    int arr_count = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("  📌 Sorting Integer Array (qsort)  \n");
    printf("========================================\n");

    printf("🔹 Before Sorting:   ");
    for (int i = 0; i < arr_count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    my_qsort(arr, arr_count, sizeof(arr[0]), int_cmp);

    printf("🔹 After Sorting:    ");
    for (int i = 0; i < arr_count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n========================================\n\n");
}

void run_all_tests() {
    qsort_int_test();
    qsort_double_test();
    qsort_char_test();
    qsort_struct_test();
}

int main(void) {
    run_all_tests();
    return 0;
}