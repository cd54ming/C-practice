#include <stdio.h>

int main(void) {
    short num = 1; // (0000 0001)
    char* c = (char*)&num;

    if ((*c) == 1) {
        printf("System is Little-Endian\n");
    } else {
        printf("System is Big-Endian\n");
    }

    return 0;
}