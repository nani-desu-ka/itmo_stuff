#include <stdio.h>

int main() {
    int first_matrix[7] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < 7; i++) {
        printf("%d\n", first_matrix[i]);
    }
    printf("----\n");
    int second_matrix_1[2][2] = {{1, 2}, {3, 4}};
    int second_matrix_2[2][2] = {{1, 0}, {0, 1}};
    int second_matrix_result[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                second_matrix_result[i][j] += second_matrix_1[i][k] * second_matrix_2[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", second_matrix_result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
