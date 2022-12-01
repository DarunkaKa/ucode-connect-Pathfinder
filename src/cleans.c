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

// перевіряє вершину
void mx_check_vertix(char *vertix, char *vertix1, char **arr_str, char **array, int count_islands, int lines, int line) {
    if (!mx_strlen(vertix)) {
        clean_other_errors(vertix, vertix1, arr_str, array, lines, count_islands);
        mx_print_error(line);
    }
    
    for (int k = 0; k < mx_strlen(vertix); k++) { 
        if (!mx_alphabet(vertix[k])) {        
            clean_other_errors(vertix, vertix1, arr_str, array, lines, count_islands);
            mx_print_error(line);
        }
    }
}

// спеціальне очещення для інших помилок
void clean_other_errors(char *vertix1, char *vertix2, char **arr_str, char **array, int lines, int count_islands) {
    free(vertix1);
    free(vertix2);
    mx_clean_arr(arr_str, lines);
    mx_clean_arr(array, count_islands);
}

// перевірка на невірне значення вершин
void mx_check_islands(char *vertix1, char *vertix2, char **array, char **arr_str, int lines, int count_islands, int j, bool end) {
    bool check = false;
    if (end && j < count_islands) check = true;
    if (j > count_islands || check) {
        clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
        islands_error();
    }
}
