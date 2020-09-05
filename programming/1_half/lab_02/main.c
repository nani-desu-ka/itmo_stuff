#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    int x;
    printf("Enter X:");
    scanf("%d", &x);
    float result = 2 * sin(3 * M_PI - 2 * x) * sin(3 * M_PI - 2 * x) * cos(5 * M_PI + 2 * x)
            * cos(5 * M_PI + 2 * x);
    printf("Result 1: %f\n", result);
    result = 1.0 / 4 - 1.0 / 4 * sin(5 * M_PI / 2 - 8 * x);
    printf("Result 2: %f", result);
    return 0;
}
