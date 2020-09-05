#include <stdio.h>

int main() {
    int value;
    printf("Enter decimal: ");
    scanf("%d", &value);
    printf("%s\n", (value <= 1 && value >= 10) ? "IN" : "OUT");

    printf("Enter decimal: ");
    scanf("%d", &value);
    printf("%d\n", 1 & (value >> 1));
    return 0;
}
