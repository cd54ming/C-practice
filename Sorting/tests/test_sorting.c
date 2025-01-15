
#include "test_sorting.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 30
#define RANDOM_RANGE 1000

void test_sort(int *arr, int len, compare_func_t compare) {
    if (len <= 1) {
        return;
    }

    for (int i = 0; i < len - 1; i++) {
        // ! 允許元素相同
        if ((arr[i] != arr[i + 1]) && !compare(arr[i], arr[i + 1])) {
            fprintf(stderr, "Sorting test failed: arr[%d] = %d, arr[%d] = %d\n", i, arr[i], i + 1, arr[i + 1]);
            assert(arr[i] <= arr[i + 1]);
        }
    }
}

void print_arr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void run_sort_and_test(sort_func_t sort_func, int *arr, int len, const char *sort_name) {
    printf("\n========== %s Testing Start ==========\n", sort_name);

    int *copied_arr = (int *)malloc(len * sizeof(int));
    if (!copied_arr) {
        perror("Failed to allocate memory for array copy");
        exit(EXIT_FAILURE);
    }

    memcpy(copied_arr, arr, len * sizeof(int));
    printf("\n%s - Ascending Order:\n", sort_name);
    sort_func(copied_arr, len, ascending);
    test_sort(copied_arr, len, ascending);
    printf("Sorted array:   ");
    print_arr(copied_arr, len);
    printf("Ascending order test passed!\n");

    memcpy(copied_arr, arr, len * sizeof(int));
    printf("\n%s - Descending Order:\n", sort_name);
    sort_func(copied_arr, len, descending);
    test_sort(copied_arr, len, descending);
    printf("Sorted array:   ");
    print_arr(copied_arr, len);
    printf("Descending order test passed!\n");

    free(copied_arr);
    printf("\n========== %s Testing Passed ==========\n\n", sort_name);
}

void run_all_sort_tests() {
    int *random_array = malloc(ARRAY_SIZE * sizeof(int));
    if (!random_array) {
        fprintf(stderr, "Failed to allocate memory for random array");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_array[i] = rand() % RANDOM_RANGE;
    }

    run_sort_and_test(bubble_sort, random_array, ARRAY_SIZE, "Bubble Sort");
    run_sort_and_test(selection_sort, random_array, ARRAY_SIZE, "Selection Sort");
    run_sort_and_test(insertion_sort, random_array, ARRAY_SIZE, "Insertion Sort");
    run_sort_and_test(quick_sort, random_array, ARRAY_SIZE, "Quick Sort");
    run_sort_and_test(heap_sort, random_array, ARRAY_SIZE, "Heap Sort");
    run_sort_and_test(merge_sort, random_array, ARRAY_SIZE, "Merge Sort");

    free(random_array);
}