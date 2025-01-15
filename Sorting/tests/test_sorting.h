
#ifndef TEST_SORTING_H
#define TEST_SORTING_H

#include "../sorting.h"

void test_sort(int *arr, int len, compare_func_t compare);
void print_arr(int *arr, int len);
void run_sort_and_test(sort_func_t sort_func, int *arr, int len, const char *sort_name);
void run_all_sort_tests();

#endif
