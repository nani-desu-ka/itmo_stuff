#include <stdio.h>
#include <string.h>

int main() {
    char first_string[4] = "foo";
    char second_string[4] = "bar";
    strncat(first_string, second_string, 4);
    printf("%s\n", first_string);
    char third_string[7] = "foobar";
    printf("%d\n", strcmp(first_string, third_string));
    char fourth_string[7];
    strcpy(fourth_string, third_string);
    printf("%s\n", fourth_string);
    printf("%d\n", strlen(fourth_string));
    char *last = strrchr(fourth_string, 'o');
    if (last != NULL) printf("%d\n", last - fourth_string + 1);
    else printf("NULL\n");
    return 0;
}
