#include <stdio.h>

// * initialized once and live till the end of the program
void check_static_var () {
    static int static_int = 0;
    static_int++;
    printf("static_int: %d\n", static_int);
}

int initialized_int () {
    return 100;
}

// * 其他檔案存取不到此函式
// * 其他檔案內可以宣告同名字的函式
static void static_func () {
    printf("this is static function, other file can declare same name\n");
}


int main (void) {
    static int a;

    // * initialized as 0 if not initialized explicitly
    printf("a: %d\n", a);

    // ! will occur error, can only be initialized using constant literals
    // static int b = initialized_int();

    check_static_var();
    check_static_var();

    return 0;
}