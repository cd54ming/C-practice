#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int generate_fibonacci_sequence(int **fib_sequence, size_t *sequence_size, int max_value);
void free_fibonacci_sequence(int *fib_sequence);
int fibonacci_search(int array[], size_t array_size, int *fib_sequence, size_t sequence_size, int search_key);

int generate_fibonacci_sequence(int **fib_sequence, size_t *sequence_size, int max_value) {
    size_t current_size = 2;
    int *sequence = (int *)malloc(current_size * sizeof(int));
    if (sequence == NULL) {
        perror("Failed to allocate memory");
        return -1;
    }

    sequence[0] = 0;
    sequence[1] = 1;

    while (sequence[current_size - 1] <= max_value) {
        int *temp = (int *)realloc(sequence, (current_size + 1) * sizeof(int));
        if (temp == NULL) {
            free(sequence);
            perror("Failed to reallocate memory");
            return -1;
        }

        sequence = temp;
        sequence[current_size] = sequence[current_size - 2] + sequence[current_size - 1];
        current_size++;
    }

    *sequence_size = current_size;
    *fib_sequence = sequence;
    return 0;
}

void free_fibonacci_sequence(int *fib_sequence) {
    free(fib_sequence);
}

int fibonacci_search(int array[], size_t array_size, int *fib_sequence, size_t sequence_size, int search_key) {
    int offset = -1;
    int fib_index = sequence_size - 1;

    while (fib_index > 1) {
        int search_index = offset + fib_sequence[fib_index - 2];

        if (search_index > (int)array_size) {
            return -1;
        }

        if (array[search_index] < search_key) {
            fib_index -= 1;
            offset = search_index;
        } else if (array[search_index] > search_key) {
            fib_index -= 2;
        } else {
            return search_index;
        }
    }

    return -1;
}

int fibonacci_search_version2(int array[], size_t array_size, int *fib_sequence, size_t sequence_size, int search_key) {
    int offset = -1;
    int fib_index = sequence_size - 1;

    while (fib_index > 1) {
        int search_index = offset + fib_sequence[fib_index - 1];

        if (search_index > (int)array_size) {
            return -1;
        }

        if (array[search_index] < search_key) {
            fib_index -= 2;
            offset = search_index;
        } else if (array[search_index] > search_key) {
            fib_index -= 1;
        } else {
            return search_index;
        }
    }

    return -1;
}

void test() {
    int search_table[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    size_t table_size = sizeof(search_table) / sizeof(search_table[0]);

    int *fib_sequence = NULL;
    size_t sequence_size = 0;

    if (generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size)) {
        exit(EXIT_FAILURE);
    }

    // Test with valid keys
    for (int i = 0; i < table_size; i++) {
        assert(fibonacci_search(search_table, table_size, fib_sequence, sequence_size, search_table[i]) == i);
    }

    // Test with invalid keys
    int invalid_keys[] = {44, -100, 0, 105, 2000};
    for (int i = 0; i < sizeof(invalid_keys) / sizeof(invalid_keys[0]); i++) {
        assert(fibonacci_search(search_table, table_size, fib_sequence, sequence_size, invalid_keys[i]) == -1);
    }

    // Test with single-element array
    int search_table2[] = {99};
    table_size = sizeof(search_table2) / sizeof(search_table2[0]);
    generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size);
    assert(fibonacci_search(search_table2, table_size, fib_sequence, sequence_size, 99) == 0);
    assert(fibonacci_search(search_table2, table_size, fib_sequence, sequence_size, 100) == -1);

    // Test with empty array
    int search_table3[] = {};
    table_size = sizeof(search_table3) / sizeof(search_table3[0]);
    generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size);
    assert(fibonacci_search(search_table3, table_size, fib_sequence, sequence_size, 50) == -1);

    free_fibonacci_sequence(fib_sequence);
}

void test_version2() {
    int search_table[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    size_t table_size = sizeof(search_table) / sizeof(search_table[0]);

    int *fib_sequence = NULL;
    size_t sequence_size = 0;

    if (generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size)) {
        exit(EXIT_FAILURE);
    }

    // Test with valid keys
    for (int i = 0; i < table_size; i++) {
        assert(fibonacci_search_version2(search_table, table_size, fib_sequence, sequence_size, search_table[i]) == i);
    }

    // Test with invalid keys
    int invalid_keys[] = {44, -100, 0, 105, 2000};
    for (int i = 0; i < sizeof(invalid_keys) / sizeof(invalid_keys[0]); i++) {
        assert(fibonacci_search_version2(search_table, table_size, fib_sequence, sequence_size, invalid_keys[i]) == -1);
    }

    // Test with single-element array
    int search_table2[] = {99};
    table_size = sizeof(search_table2) / sizeof(search_table2[0]);
    generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size);
    assert(fibonacci_search_version2(search_table2, table_size, fib_sequence, sequence_size, 99) == 0);
    assert(fibonacci_search_version2(search_table2, table_size, fib_sequence, sequence_size, 100) == -1);

    // Test with empty array
    int search_table3[] = {};
    table_size = sizeof(search_table3) / sizeof(search_table3[0]);
    generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size);
    assert(fibonacci_search_version2(search_table3, table_size, fib_sequence, sequence_size, 50) == -1);

    free_fibonacci_sequence(fib_sequence);
}

void example () {
    int search_table[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int search_key = 59;
    size_t table_size = sizeof(search_table) / sizeof(search_table[0]);

    int *fib_sequence = NULL;
    size_t sequence_size = 0;

    if (generate_fibonacci_sequence(&fib_sequence, &sequence_size, (int)table_size)) {
        exit(EXIT_FAILURE);
    }

    int result = fibonacci_search(search_table, table_size, fib_sequence, sequence_size, search_key);

    if (result != -1) {
        printf("Key %d found at index: %d\n", search_key, result);
    } else {
        printf("Key %d not found in the table.\n", search_key);
    }

    free_fibonacci_sequence(fib_sequence);
}

int main(void) {
    test();
    test_version2();
    example();
    return 0;
}