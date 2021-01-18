#include <stdio.h>

void task_1() {
    char input[50];
    scanf("%s", input);
    unsigned int digits_counter = 0;
    unsigned int letters_counter = 0;
    unsigned int LETTERS_counter = 0;
    for (int i = 0; i < 50; i++) {
        if (input[i] == '\0') break;
        if (input[i] >= 'a' && input[i] <= 'z') letters_counter++;
        if (input[i] >= 'A' && input[i] <= 'Z') LETTERS_counter++;
        if (input[i] >= '0' && input[i] <= '9') digits_counter++;
    }
    printf("Digits amount: %u\n", digits_counter);
    printf("Letters amount: %u\n", letters_counter);
    printf("Upper letters amount: %u\n", LETTERS_counter);
}

void task_2() {
    unsigned int talk_length = 0;
    unsigned int month_cost = 0;
    unsigned int extra_minutes_cost = 0;
    printf("Enter how much you talked\n");
    scanf("%u", &talk_length);
    printf("Enter month cost\n");
    scanf("%u", &month_cost);
    printf("Enter extra minutes cost\n");
    scanf("%u", &extra_minutes_cost);
    if ((float)month_cost / 499.0 >= extra_minutes_cost) {
        printf("Extra minutes cost less than minutes during month");
        return;
    }
    unsigned int total_sum = month_cost;
    if (talk_length > 499) {
        total_sum += extra_minutes_cost * (talk_length - 499);
    }
    printf("Total cost = %u\n", total_sum);
}

int main() {
    task_1();
    task_2();
    return 0;
}
