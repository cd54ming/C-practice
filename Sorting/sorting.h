#ifndef SORTING_H
#define SORTING_H

#include <stdbool.h>

typedef bool (*compare_func_t)(int a, int b);

typedef void (*sort_func_t)(int *arr, int len, compare_func_t compare);

void swap(int *a, int *b);
bool ascending(int a, int b);
bool descending(int a, int b);

void insertion_sort(int *arr, int len, compare_func_t compare);
void selection_sort(int *arr, int len, compare_func_t compare);
void bubble_sort(int *arr, int len, compare_func_t compare);

int partition(int *arr, int low, int high, compare_func_t compare);
void quick_sort_internal(int *arr, int low, int height, compare_func_t compare);
void quick_sort(int *arr, int len, compare_func_t compare);

void heapify(int *arr, int len, int root, compare_func_t compare);
void heap_sort(int *arr, int len, compare_func_t compare);

void merge(int *arr, int left, int mid, int right, compare_func_t compare);
void merge_sort_internal(int *arr, int left, int right, compare_func_t compare);
void merge_sort(int *arr, int len, compare_func_t compare);

#endif