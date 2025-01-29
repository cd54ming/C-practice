#ifndef QSORT_H
#define QSORT_H

#include <stddef.h>

typedef int (*cmp_func_t)(const void *, const void *);

void my_qsort(void *arr, size_t number_elements, size_t elem_size, cmp_func_t cmp);

#endif // QSORT_H