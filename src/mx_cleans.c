#include "../inc/pathfinder.h"

// чищення двовимірного масиву
void mx_clean_arr(char **array, int length) {
    for (int i = 0; i < length; i++) {
        mx_strdel(&array[i]);
    }
    mx_strdel(array);
}

// чищення двовимірного масиву
void mx_clean_arr_int(int **array, int length) {
    for (int i = 0; i < length; i++) {
        free(array[i]);
        array[i] = NULL; 
    }
    free(array);
    array = NULL;
}

// спеціальне очещення для інших помилок
void clean_other_errors(char *vertix1, char *vertix2, char **arr_str, char **array, int lines, int count_islands) {
    free(vertix1);
    free(vertix2);
    mx_clean_arr(arr_str, lines);
    mx_clean_arr(array, count_islands);
}

