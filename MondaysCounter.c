#include <stdio.h>

int is_it_leap_year(int year) {
    char year_str[5];
    sprintf(year_str, "%d", year);

    if (year % 4 == 0 && (year_str[2] != '0' || year_str[3] != '0')) {
        return 1;
    }
    if (year_str[2] == '0' && year_str[3] == '0' && year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int days_between(int start, int end) {
    int days = 0;
    int year = start;
    while (year <= end) {
        if (is_it_leap_year(year)) {
            days += 366;
        } else {
            days += 365;
        }
        year++;
    }
    return days;
}

int common_data(int list1[], int size1, int list2[], int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int number_of_elements(int list1[], int size1, int list2[], int size2) {
    int count = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                count++;
            }
        }
    }
    return count;
}

int howManyDays() {
    int days = days_between(1401, 2007); /* Calculate the difference in days between 01/01/1401 and 18/05/2007 */

    // 227 is the number of days left in 2007 to be 31/12/2007.
    days = days - 227;
    //printf("The difference in days between 01/01/1401 and 18/05/2007 is %d\n", days);
    //printf("%d\n", (days % 7)); // Monday

    int var = days_between(1401, 1800);
    //printf("%d\n", var);        // 01/01/1401 -> 01/01/1801
    //printf("%d\n", var - 1);    // 01/01/1401 -> 31/12/1800

    int mondays[var / 7];
    for (int i = 1; i <= var; i += 7) {
        mondays[(i - 1) / 7] = i;
    }

    int normal_year_day_12[] = {12, 43, 71, 102, 132, 162, 193, 223, 254, 285, 315, 346};
    int res = 0;
    int year = 1401;

    while (year <= 1800) {
        if (common_data(mondays, var / 7, normal_year_day_12, sizeof(normal_year_day_12) / sizeof(normal_year_day_12[0]))) {
            int number = number_of_elements(mondays, var / 7, normal_year_day_12, sizeof(normal_year_day_12) / sizeof(normal_year_day_12[0]));
            res += number;
        }
        if (is_it_leap_year(year)) {
            for (int i = 0; i < sizeof(normal_year_day_12) / sizeof(normal_year_day_12[0]); i++) {
                normal_year_day_12[i] += 366;
            }
        } else {
            for (int i = 0; i < sizeof(normal_year_day_12) / sizeof(normal_year_day_12[0]); i++) {
                normal_year_day_12[i] += 365;
            }
        }
        year++;
    }

    return res;
}