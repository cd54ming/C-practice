#include <stdio.h>

void swap(int* a, int* b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main(void) {
    int a = 0;
    int b = 0;

    printf("a is: ");
    scanf("%d", &a);
    printf("b is: ");
    scanf("%d", &b);

    swap(&a, &b);
    printf("after swap, now a and b are: %d, %d\n", a, b);

    return 0;
}