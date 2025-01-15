#include "sorting.h"
#include "tests/test_sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example() {
    int example_array[] = {42, 17, 56, 33, 8, 27, 99, 13, 64};
    int len = sizeof(example_array) / sizeof(example_array[0]);

    int *copied_array = (int *)malloc(len * sizeof(int));
    if (!copied_array) {
        fprintf(stderr, "Failed to allocate memory for copied_array");
        exit(EXIT_FAILURE);
    }
    memcpy(copied_array, example_array, len * sizeof(int));

    printf("Original array:\n");
    print_arr(example_array, len);

    // Bubble Sort
    bubble_sort(copied_array, len, ascending);
    printf("\nBubble Sort (Ascending):\n");
    print_arr(copied_array, len);

    // Selection Sort
    selection_sort(copied_array, len, descending);
    printf("\nSelection Sort (Descending):\n");
    print_arr(copied_array, len);

    // Insertion Sort
    insertion_sort(copied_array, len, ascending);
    printf("\nInsertion Sort (Ascending):\n");
    print_arr(copied_array, len);

    // Quick Sort
    quick_sort(copied_array, len, descending);
    printf("\nQuick Sort (Descending):\n");
    print_arr(copied_array, len);

    // Heap Sort
    heap_sort(copied_array, len, ascending);
    printf("\nHeap Sort (Ascending):\n");
    print_arr(copied_array, len);

    // Merge Sort
    merge_sort(copied_array, len, descending);
    printf("\nMerge Sort (Descending):\n");
    print_arr(copied_array, len);

    free(copied_array);
}

int main(void) {
    run_all_sort_tests();
    example();
    return 0;
}