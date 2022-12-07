#include "../inc/pathfinder.h"

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

// перевірка на невірне значення вершин
void mx_check_islands(char *vertix1, char *vertix2, char **array, char **arr_str, int lines, int count_islands, int j, bool end) {
    bool check = false;
    if (end && j < count_islands) check = true;
    if (j > count_islands || check) {
        clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
        islands_error();
    }
}

