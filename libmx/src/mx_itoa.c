#include "../inc/libmx.h"

char *mx_itoa(int number) {    
    char *str = check_zero(number);
    bool negative_num = false;
    if (number < 0) {
        negative_num = true;
        number *= -1;
    }
    if (number > 0) {
        int counter = mx_counter_int(number);
        int i = 0;
        str = mx_strnew(counter);
        if (negative_num) {
            str[i] = '-';
            i++;
        }        
        for (int j = counter; j > 0; j--) {
            int power = 1;
            for (int k = j; k > 1; k--) {
                power *= 10;
            }
            int digit = number / power;
            number %= power;
            str[i++] = digit + '0';
        }
        str[i] = '\0';
    }
    return str;
}


