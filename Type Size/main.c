#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// 基本原則：char 1 byte, short 2 bytes, 標準 int 4 bytes, long 4 or 8 bytes, float 4 bytes, double 8 bytes, long long 8 bytes, bool 1 byte

int main(void) {
    char char_type = 'a';
    int int_type = 1;
    short int short_type = 1;
    long int long_type = 1;
    long long int long_long_type = 1;

    printf("size of char type is: %lu bytes\n", sizeof(char_type));
    printf("size of int type is: %lu bytes\n", sizeof(int_type));
    printf("size of short int type is: %lu bytes\n", sizeof(short_type));
    printf("size of long int type is: %lu bytes\n", sizeof(long_type));
    printf("size of long long int type is: %lu bytes\n", sizeof(long_long_type));

    unsigned char unsigned_char_type = 'a';
    unsigned int unsigned_int_type = 1;
    unsigned short unsigned_short_type = 1;
    unsigned long unsigned_long_type = 1;
    unsigned long long  unsigned_long_long_int_type = 1;


    printf("size of unsigned char type is: %lu bytes\n", sizeof(unsigned_char_type));
    printf("size of unsigned int type is: %lu bytes\n", sizeof(unsigned_int_type));
    printf("size of unsigned short int type is: %lu bytes\n", sizeof(unsigned_short_type));
    printf("size of unsigned long int type is: %lu bytes\n", sizeof(unsigned_long_type));
    printf("size of unsigned long long int type is: %lu bytes\n", sizeof(unsigned_long_long_int_type));

    signed char signed_char_type = 'a';
    signed int signed_int_type = 1;
    signed short signed_short_type = 1;
    signed long signed_long_type = 1;
    signed long long signed_long_long_type = 1;

    printf("size of signed char type is: %lu bytes\n", sizeof(signed_char_type));
    printf("size of signed int type is: %lu bytes\n", sizeof(signed_int_type));
    printf("size of signed short int type is: %lu bytes\n", sizeof(signed_short_type));
    printf("size of signed long int type is: %lu bytes\n", sizeof(signed_long_type));
    printf("size of signed long long int type is: %lu bytes\n", sizeof(signed_long_long_type));

    float float_type = 1.0f;
    double double_type = 1.0;
    long double long_double_type = 1.0;

    printf("size of float type is: %lu bytes\n", sizeof(float_type));
    printf("size of double type is: %lu bytes\n", sizeof(double_type));
    printf("size of long double type is: %lu bytes\n", sizeof(long_double_type));

    // in C99
    bool bool_type = 1;
    printf("size of bool type is: %lu bytes\n", sizeof(bool_type));

    return 0;
}
