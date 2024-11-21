#include <stdio.h>

int calculate_binary(int decimal) {
    int binary = 0;
    int place = 1;

    while (decimal > 0) {
        int reminder = decimal % 2;
        binary += reminder * place;
        decimal /= 2;
        place *= 10;
    }

    return binary;
}

int main(void) {
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1; // 返回非零值表示錯誤
    }

    int binary = calculate_binary(num);
    printf("%d in binary is: %d\n", num, binary);
    return 0;
}