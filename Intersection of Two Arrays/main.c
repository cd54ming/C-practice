#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// * Learn how to use realloc

bool is_element_in_array(int arr[], int arr_size, int element) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }

    return false;
}

int *intersection(int arr1[], int arr1_size, int arr2[], int arr2_size, int *intersection_size) {
    int *intersection_arr;
    *intersection_size = 0;

    for (int i = 0; i < arr2_size; i++) {
        if (is_element_in_array(arr1, arr1_size, arr2[i]) &&
            !is_element_in_array(intersection_arr, *intersection_size, arr2[i])) {
            intersection_arr =
                (int *)realloc(intersection_arr, ((*intersection_size) + 1) * sizeof(int));
            intersection_arr[(*intersection_size)++] = arr2[i];
        }
    }

    return intersection_arr;
}

int main(void) {
    int arr1[] = {0, 1, 2, 3, 4, 5, 6};
    int arr2[] = {4, 9, 2, 1, 0};
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    int intersection_size = 0;
    int *intersection_arr = intersection(arr1, arr1_size, arr2, arr2_size, &intersection_size);

    printf("intersection is: { ");
    for (int i = 0; i < intersection_size; i++) {
        printf("%d", intersection_arr[i]);
        if (i != intersection_size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");

    free(intersection_arr);

    return 0;
}