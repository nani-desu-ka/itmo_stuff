#include <stdio.h>
#include <malloc.h>

int main() {
    char first_matrix[4];
    for (int i = 0; i < 4; i++) {
        scanf(" %c", &first_matrix[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%c ", *(first_matrix + i));
    }
    printf("\n----\n");
    char *second_matrix = (char *)malloc(4);
    for (int i = 0; i < 4; i++) {
        scanf(" %c", &second_matrix[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%c ", second_matrix[i]);
    }
    free(second_matrix);
    return 0;
}
