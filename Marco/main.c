#include <stdio.h>

// marco 只是文本替換，不具型別檢查，容易引起隱藏錯誤。

#define DEBUG_MODE

#define PI 3.1415926
#define AREA_OF_CIRCLE(radius) (radius * radius * PI)

// const 更適合定義常量，可以取代 define
const double EULERS_NUMBER = 2.71828;

// inline 更適合簡單函數，減少潛在錯誤，可以取代 define
// inline function 可減少函數的調用開銷（如壓棧和跳轉），但編譯器還是會根據優化策略決定選擇是否採用
// inline function 適合體積較小的函數，以避免內聯導致程式碼膨脹 (code bloat)
static inline double calculate_exponential(double exponent) {
    // 泰勒展開式
    double result = 1.0;
    double term = 1.0;
    int iterations = 20;  // 計算 20 項，視精度需求而定
    for (int n = 1; n <= iterations; n++) {
        term *= exponent / n;
        result += term;
        if (term < 1e-10) break;
    }
    return result;
}

int main(void) {
    double radius = 5.0;
    double area = AREA_OF_CIRCLE(radius);
    printf("The area of a circle with radius %.2f is %.4f\n", radius, area);

    int power = 3;
    double exponential = calculate_exponential(power);
    printf("Euler's number raised to the power of %d is %.8f\n", power, exponential);

#ifdef DEBUG_MODE
    printf("this is in debug mode.\n");
#endif

    return 0;
}