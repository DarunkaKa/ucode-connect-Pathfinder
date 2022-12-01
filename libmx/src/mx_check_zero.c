#include "../inc/libmx.h"

char *check_zero(int number) {
    if (number == 0) {
        return "0";
    }
    if (number == -2147483648) {
        return "-2147483648";
    }
    return NULL;
}

