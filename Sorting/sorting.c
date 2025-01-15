#include "sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

void merge(int *arr, int left, int mid, int right, compare_func_t compare) {
    int L_size = mid - left + 1;
    int R_size = right - mid;

    int *L = (int *)malloc(L_size * sizeof(int));
    if (L == NULL) {
        fprintf(stderr, "Failed to allocate memory for L");
        exit(EXIT_FAILURE);
    }
    int *R = (int *)malloc(R_size * sizeof(int));
    if (R == NULL) {
        fprintf(stderr, "Failed to allocate memory for R");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < L_size; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < R_size; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < L_size && j < R_size) {
        if (compare(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < L_size) {
        arr[k++] = L[i++];
    }
    while (j < R_size) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

// * 時間複雜度：O(n log n), 穩定排序法
void merge_sort_internal(int *arr, int left, int right, compare_func_t compare) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_internal(arr, left, mid, compare);
        merge_sort_internal(arr, mid + 1, right, compare);

        merge(arr, left, mid, right, compare);
    }
}

void merge_sort(int *arr, int len, compare_func_t compare) {
    merge_sort_internal(arr, 0, len - 1, compare);
}

void heapify(int *arr, int len, int root, compare_func_t compare) {
    int selected = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < len && compare(arr[selected], arr[left])) {
        selected = left;
    }

    if (right < len && compare(arr[selected], arr[right])) {
        selected = right;
    }

    if (selected != root) {
        swap(&arr[selected], &arr[root]);
        heapify(arr, len, selected, compare);
    }
}

// * 時間複雜度：O(n log n), 不穩定排序法
void heap_sort(int *arr, int len, compare_func_t compare) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i, compare);
    }

    for (int i = len - 1; i >= 0; i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0, compare);
    }
}

int partition(int *arr, int low, int high, compare_func_t compare) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// * 時間複雜度：O(n log n), 不穩定排序法（可能受 pivot 選擇影響）
void quick_sort_internal(int *arr, int low, int high, compare_func_t compare) {
    if (low < high) {
        int pivot = partition(arr, low, high, compare);
        quick_sort_internal(arr, low, pivot - 1, compare);
        quick_sort_internal(arr, pivot + 1, high, compare);
    }
}

void quick_sort(int *arr, int len, compare_func_t compare) {
    return quick_sort_internal(arr, 0, len - 1, compare);
}

// * 時間複雜度：O(n^2), 穩定排序法
void insertion_sort(int *arr, int len, compare_func_t compare) {
    for (int i = 1; i < len; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && !compare(arr[j], temp)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// * 時間複雜度：O(n^2), 不穩定排序法
void selection_sort(int *arr, int len, compare_func_t compare) {
    for (int i = 0; i < len - 1; i++) {
        int best_index = i;

        for (int j = i + 1; j < len; j++) {
            if (compare(arr[j], arr[best_index])) {
                best_index = j;
            }
        }

        if (best_index != i) {
            swap(&arr[i], &arr[best_index]);
        }
    }
}

// * 時間複雜度：O(n^2), 穩定排序法
void bubble_sort(int *arr, int len, compare_func_t compare) {
    for (int i = 0; i < len - 1; i++) {
        bool is_sorted = true;

        for (int j = len - 1; j > i; j--) {
            if (compare(arr[j], arr[j - 1])) {
                swap(&arr[j], &arr[j - 1]);
                is_sorted = false;
            }
        }

        if (is_sorted) {
            return;
        }
    }
}