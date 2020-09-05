#include <stdio.h>
#include <malloc.h>

int main() {
    int active = 1;
    while (active) {
        int command;
        printf("Available commands:\n1 - String input\n2 - Integer input\n");
        scanf("%d", &command);
        switch (command) {
            case 1:
                int array_size;
                printf("Enter string length: ");
                scanf("%d", &array_size);
                char *string = malloc(array_size + 1);
                printf("Enter string: ");
                scanf("%s", string);
                printf("Your string: ");
                puts(string);
                printf("\n");
                free(string);
                continue;
            case 2:
                int temp_int;
                printf("Enter integer: ");
                scanf("%d", &temp_int);
                printf("Your integer: %d\n", temp_int);
                continue;
            case 0:
                active = 0;
                continue;
            default:
                printf("Incorrect command\n");
                continue;
        }
    }
    return 0;
}
