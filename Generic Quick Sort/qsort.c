
#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(char *a, char *b, size_t elem_size) {
    char temp;
    for (size_t i = 0; i < elem_size; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

static int partition(void *arr, int low, int high, size_t elem_size, cmp_func_t cmp) {
    void *pivot = arr + high * elem_size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (cmp(arr + j * elem_size, pivot) < 0) {
            i++;
            swap(arr + i * elem_size, arr + j * elem_size, elem_size);
        }
    }
    swap(arr + (i + 1) * elem_size, pivot, elem_size);

    return i + 1;
}

static void qsort_recursive(void *arr, int low, int high, size_t elem_size, cmp_func_t cmp) {
    if (low < high) {
        int pivot_index = partition(arr, low, high, elem_size, cmp);
        qsort_recursive(arr, low, pivot_index - 1, elem_size, cmp);
        qsort_recursive(arr, pivot_index + 1, high, elem_size, cmp);
    }
}

void my_qsort(void *arr, size_t number_elements, size_t elem_size, cmp_func_t cmp) {
    if (!arr || !cmp || number_elements <= 1) {
        return;
    }
    qsort_recursive(arr, 0, number_elements - 1, elem_size, cmp);
}