#include <stdio.h>

typedef enum {
    ASCENDING,
    DESCENDING
} SortType;

void print_triangle(int width, char fill_char, char background_char, SortType sort_type) {
    if (width <= 0) {
        printf("Invalid width: %d. Width must be positive.\n", width);
        return;
    }

    for (int i = 0; i < width; i++) {
        int print_number = (sort_type == ASCENDING) ? (i + 1) : (width - i);

        for (int j = 0; j < print_number; j++) {
            printf("%c", fill_char);
        }
        for (int j = 0; j < (width - print_number); j++) {
            printf("%c", background_char);
        }
        printf("\n");
    }
}

void print_diamond(int width, char fill_char, char background_char) {
    if (width <= 0 || width % 2 == 0) {
        printf("Width must be a positive odd number.\n");
        return;
    }

    int half_width = width / 2;
    for (int i = 0; i <= half_width; i++) {
        for (int j = 0; j < (half_width - i); j++) {
            printf("%c", background_char);
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("%c", fill_char);
        }
        for (int j = 0; j < (half_width - i); j++) {
            printf("%c", background_char);
        }
        printf("\n");
    }

    for (int i = half_width - 1; i >= 0; i--) {
        for (int j = 0; j < (half_width - i); j++) {
            printf("%c", background_char);
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("%c", fill_char);
        }
        for (int j = 0; j < (half_width - i); j++) {
            printf("%c", background_char);
        }
        printf("\n");
    }
}

int main(void) {
    int width = 9;
    char fill_char = '*';
    char background_char = '-';

    print_triangle(width, fill_char, background_char, ASCENDING);
    print_triangle(width, fill_char, background_char, DESCENDING);
    print_triangle(width, background_char, fill_char, DESCENDING);
    print_triangle(width, background_char, fill_char, ASCENDING);
    print_diamond(width, fill_char, background_char);

    return 0;
}