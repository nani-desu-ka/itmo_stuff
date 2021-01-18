#include <stdio.h>
#include "rectangle.h"

int main() {
    struct Point pos;
    pos.x = 3;
    pos.y = 3;
    struct Rectangle rectangle;
    RectangleConstructor(&rectangle, 3, 4, pos);
    printf("%f\n", perimeter(rectangle));
    printf("%f\n", square(rectangle));
    return 0;
}
