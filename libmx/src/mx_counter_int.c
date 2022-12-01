#include "../inc/libmx.h"

int mx_counter_int(int number) {
    int counter = 0;
    while (number != 0) {
        number /= 10;
        counter++;
    }
    return counter;
}

