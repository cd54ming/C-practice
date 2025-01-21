#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Reference: https://youtu.be/gRt_l2H8wBA?si=UrI3r3-eav9z8IrI

// 型別決定了資料的「儲存方式」與「運算行為」
// char 是唯一被標準直接定義大小的型別，固定為 1 byte
// 其他型別大小是 implementation-defined（實作定義），會依據編譯器而有所不同
// 一般遵循以下關係：
// short (2 bytes) <= int (4 bytes) <= long (4 或 8 bytes) <= long long (8 bytes)

int main(void) {
    printf("Size of bool: %zu bytes\n", sizeof(bool)); // after C99
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of short int: %zu bytes\n", sizeof(short int));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long int: %zu bytes\n", sizeof(long));
    printf("Size of long long int: %zu bytes\n", sizeof(long long)); // after C99
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));

    printf("========================================\n");

    int arr[] = {1, 2, 3};
    int(*p)[3] = &arr;
    printf("Size of void *: %zu bytes\n", sizeof(void *));
    printf("Size of int*: %zu bytes\n", sizeof(int *));
    printf("Size of char*: %zu bytes\n", sizeof(char *));
    printf("Size of long long int*: %zu bytes\n", sizeof(long long int *));
    printf("Size of void*: %zu bytes\n", sizeof(void *));
    printf("Size of function pointer: %zu bytes\n", sizeof(void (*)()));
    printf("Size of pointer to 3-int element array: %zu bytes\n", sizeof(p));
    printf("Size of 3-int element array: %zu bytes\n", sizeof(*p));

    return 0;
}
