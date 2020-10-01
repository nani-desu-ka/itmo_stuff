#include <stdio.h>

int main() {
    char first_matrix[4];
    for (int i = 0; i < 4; i++) {
        scanf("%c", &first_matrix[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%c", *(first_matrix + i));
    }
    return 0;
}
