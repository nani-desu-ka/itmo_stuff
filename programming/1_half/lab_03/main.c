#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() {
    int octal;
    printf("TASK 1\n");
    printf("Enter integer in octal system:");
    scanf("%d", &octal);
    int length = snprintf(NULL, 0, "%d", octal);
    char* str_octal = malloc(length + 1);
    snprintf(str_octal, length + 1, "%d", octal);
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        int temp_number = str_octal[i] - '0';
        decimal += temp_number * pow(8, length - i - 1);
    }
    printf("TASK 2\n");
    printf("Your input in decimal system:%d\n", decimal);
    printf("TASK 3\n");
    printf("Your input in octal system:%d\n", octal);
    printf("Your input with bit shift (left 1):%d\n", octal << 1);
    printf("TASK 4\n");
    printf("Your input in octal system:%d\n", octal);
    printf("Your input with negation operator:%d\n", ~octal);
    printf("TASK 5\n");
    int octal_2;
    printf("Enter integer in octal system:");
    scanf("%d", &octal_2);
    printf("Your input with & operator:%d\n", octal & octal_2);
    return 0;
}
