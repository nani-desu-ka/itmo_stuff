#include <stdio.h>
#include <time.h>
#include <assert.h>
enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

void check_date(int date[3]) {
    int max_day_amount = 0;
    switch (date[1]) {
        case JANUARY:
            max_day_amount = 31;
            break;
        case FEBRUARY:
            if (date[2] % 4 == 0) max_day_amount = 29;
            else max_day_amount = 28;
            break;
        case MARCH:
            max_day_amount = 31;
            break;
        case APRIL:
            max_day_amount = 30;
            break;
        case MAY:
            max_day_amount = 31;
            break;
        case JUNE:
            max_day_amount = 30;
            break;
        case JULY:
            max_day_amount = 31;
            break;
        case AUGUST:
            max_day_amount = 31;
            break;
        case SEPTEMBER:
            max_day_amount = 30;
            break;
        case OCTOBER:
            max_day_amount = 31;
            break;
        case NOVEMBER:
            max_day_amount = 30;
            break;
        case DECEMBER:
            max_day_amount = 31;
            break;
        default:
            assert("DATE TYPE ERROR");
    }
    if (date[0] > max_day_amount) {
        date[0] = 1;
        date[1]++;
    }
    if (date[1] > 12) {
        date[1] = 1;
        date[2]++;
    }
}

int main() {
    FILE *temp_file = fopen("dates.txt", "w");
    time_t seconds = time(NULL);
    struct tm *timeinfo = localtime(&seconds);
    int temp_date[3] = {timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900};
    for (int i = 0; i < 10; i++) {
        fprintf(temp_file, "%d", temp_date[0]);
        fprintf(temp_file, "%c", '.');
        fprintf(temp_file, "%d", temp_date[1]);
        fprintf(temp_file, "%c", '.');
        fprintf(temp_file, "%d", temp_date[2]);
        fprintf(temp_file, "%c", '\n');
        temp_date[0]++;
        check_date(temp_date);
    }
    fclose(temp_file);
    return 0;
}
