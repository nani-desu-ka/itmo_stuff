#include <stdio.h>
#include <malloc.h>
#include <math.h>
int NOD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return NOD(b, a % b);
    }
}

int NOK(int a, int b) {
    return a / NOD(a, b) * b;
}

struct Point {
    unsigned int x = 0;
    unsigned int y = 0;
};

void task_2() {
    unsigned int amount = 0;
    scanf("%u", &amount);
    Point *points = (Point *)(malloc(amount));
    for (int i = 0; i < amount; i++) {
        Point temp_point;
        scanf("%d%d", &temp_point.x, &temp_point.y);
        points[i] = temp_point;
    }
    auto **matrix = (double **)malloc(amount);
    for (int i = 0; i < amount; i++) {
        matrix[i] = (double *)malloc(amount - 1);
        for (int j = 0; j < amount - 1; j++) {
            if (i == j) matrix[i][j] = 0;
            matrix[i][j] = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
        }
    }
}

int main() {
    return 0;
}
