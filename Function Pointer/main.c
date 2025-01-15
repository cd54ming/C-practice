#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

typedef int(*operation)(int, int);

int execute_operation(operation op, int a, int b) {
    return op(a, b);
}

int main(void) {
    int a = 10;
    int b = 5;
    // 另一種宣告方式
    // operation ops[] = { add, subtract, multiply, divide };
    int (*ops[])(int, int) = { add, subtract, multiply, divide };
    const char* op_names[] = { "add", "subtract", "multiply", "divide" };

    for (int i = 0; i < sizeof(ops) / sizeof(*ops); i++) {
        printf("%d %s %d is: %d\n", a, op_names[i], b, execute_operation(ops[i], a, b));
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}