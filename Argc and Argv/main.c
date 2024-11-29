#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    int total = 0;
    for (int i = 1; i < argc; i++) {
        int num = strtol(argv[i], NULL, 10);
        total += num;
    }
    printf("The total of arguments is: %d\n", total);
    return 0;
}