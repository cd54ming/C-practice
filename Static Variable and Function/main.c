// # Static Variable

// - Static variable 在編譯時必須初始化，因此只能使用常量值進行初始化
//     - 如果未明確初始化，默認值為該型別的「零值」，例如：
//         - pointer：NULL
//         - int: 0
//         - double: 0
//         - char: 0
// - **Static variable** 僅初始化一次，並且存活至程式結束
//     - 這是因為它們被分配在 C 語言記憶體空間中的 BSS 或 Data 區域，而非函式的堆疊區（Stack）
//         - BSS 區域：用於未初始化的靜態變數
//         - Data 區域：於已初始化的靜態變數
// - **Static variable** 不能在 **Struct** 中宣告
//     - 這是因為 Struct 要求所有成員變數必須分配在連續的記憶體空間（因為**結構體的成員通過偏移量計算來訪問**）中，但被 static 修飾的變數會被單獨分配到 BSS 區域 或 Data 區域，因此無法滿足結構體記憶體連續性要求
// - 適用場景：
//     - **函式內持久化變數值**
//         - 適用場景
//             - 在函式中需要變數的值在多次調用之間保持不變，但又不希望將其暴露為全域變數
//         - 用途
//             - 計數、累積結果或追蹤狀態
//     - **Singleton Pattern**
//         - 適用場景
//             - 確保某個物件或資源在整個程式中只被初始化一次，例如 Buffer （限制記憶體分配在有限的大小內）或 DB Connect Pool 等
//         - 用途
//             - 節省有限的記憶體空間，避免多次初始化
//     - **限制全域變數的作用域**
//         - 適用場景
//             - 當需要變數具有全域變數的生命週期，但希望其作用域僅限於當前檔案，避免其他檔案干擾
//         - 用途
//             - 提高程式的模組化和可維護性
//     - **快取變數**
//         - 適用場景
//             - 需要重複計算的值，可以使用靜態變數進行快取，以提高效率
//         - 用途
//             - 減少不必要的重複計算，尤其是在遞迴運算中

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