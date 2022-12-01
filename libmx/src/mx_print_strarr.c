#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || ! delim) {
        return;
    }
    for (int i = 0; arr[i] != NULL; i++) {
        if (i == (mx_strlen_arr(arr) - 1)) {
            mx_printstr(arr[i]);
        }
        else { 
            mx_printstr(arr[i]);
            mx_printstr(delim);
        }
    }
    mx_printchar('\n');
}

