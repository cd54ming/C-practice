#include <stdio.h>
#include <string.h>

#define PI 3.1415926

typedef struct shape_t {
    char name[20];
    double (*area)(struct shape_t *self);
} shape_t;

void shape_init(shape_t *shape, char *name) {
    strncpy(shape->name, name, sizeof(shape->name));
    shape->area = NULL;
}

double shape_area(shape_t *shape) {
    if (shape->area) {
        return shape->area(shape);
    }

    return 0.0;
}

typedef struct circle_t {
    shape_t base;
    double radius;
} circle_t;

// 指標型別的轉換只是重新解讀記憶體佈局，記憶體的配置大小與範圍並不會改變
// 此範例是將 shape 轉型成 circle_t *，讓 circle 變數可以存取結構中的 radius 成員
double circle_area(shape_t *shape) {
    circle_t *circle = (circle_t *)shape;
    return PI * circle->radius * circle->radius;
}

void circle_init(circle_t *circle, char *name, double radius) {
    shape_init(&circle->base, name);
    circle->radius = radius;
    circle->base.area = circle_area;
}

int main(void) {
    shape_t generic_shape;
    shape_init(&generic_shape, "Generic Shape");
    printf("Area of %s: %.5f\n", generic_shape.name, shape_area(&generic_shape));

    circle_t my_circle;
    circle_init(&my_circle, "My Circle", 3);
    printf("Area of %s: %.5f\n", my_circle.base.name, shape_area((shape_t *)&my_circle));

    return 0;
}