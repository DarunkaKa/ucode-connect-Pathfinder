#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    int i = 0;
    int count = 0;
    if (str[0] == '-') {
        count = -1;
        i++;
    }
    if (str[0] == '+') {
    	count = 1;
    	i++;
    }
    int number = 0;
    for (int d = i; str[d] != '\0'; d++) {
        if (mx_isdigit(str[d])) {
            number = number * 10 + str[d] - '0';
        }
        else {
            return 0;
            break;
        }
    }
    return (count == -1) ? number *= -1 : number;
}

