#include <stdio.h>

// * 只會初始化一次並且存活到程式結束
void check_static_var () {
    static int static_int = 0;
    static_int++;
    printf("static_int: %d\n", static_int);
}

int initialized_int () {
    return 100;
}

// * 此函式無法被其他檔案存取
// * 其他檔案中可以宣告同樣名稱的函式
static void static_func () {
    printf("This is a static function; other files can declare a function with the same name\n");
}

int main (void) {
    static int a;

    // * 未初始化的靜態變數會被編譯器自動設為型別的默認值
    // * int 或其他數字型別：0
	// * pointer：NULL
	// * float 或 double：0.0
	// * char：'\0'
    printf("a: %d\n", a);

    // ! 會發生錯誤，初始化在執行 main() 前完成，無法使用執行時才知道的值（如函數回傳值）
    // static int b = initialized_int();

    check_static_var();
    check_static_var();

    return 0;
}