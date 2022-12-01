#include "../inc/pathfinder.h"

// перша вершина у рядку
char *mx_part1(char *s) {
    int temp = mx_get_char_index(s, '-');
    return mx_strndup(s, temp);
}

// друга вершина у рядку
char *mx_part2(char *s) {
    char **temp = mx_strsplit(s, '-');
    char **str = mx_strsplit(temp[1], ',');
    char *result = mx_strdup(str[0]);
    mx_clean_arr(temp, 2);
    mx_clean_arr(str, 2);
    return result;
}

// рядок до коми
static char *mx_part3(char *s) {
    char **str = mx_strsplit(s, ',');
    char *result = mx_strdup(str[0]);
    mx_clean_arr(str, 2);
    return result;
}

// перевіряє на наявність елементу в масиві
static bool mx_present(char *sub, char **array, int length) {
    for (int i = 0; i < length; i++) {
        if (mx_strcmp(sub, array[i]) == 0) {
            return true;
        }
    }
    return false;
}

// повертає унікальні вершини & робить останні перевірки
char **other_errors(char **arr_str, int count_islands, int lines) {
    if (count_islands <= 0) {
        mx_clean_arr(arr_str, lines);
        error4();
    }

    long sum = 0;
    char **array = malloc(sizeof(char *) * count_islands);
    char *vertix1 = NULL;
    char *vertix2 = NULL;
    int j = 0;

    for (int i = 1; i < lines; i++) {
        if (mx_count_substr(arr_str[i], "-") != 1
        || mx_count_substr(arr_str[i], ",") != 1
        || mx_count_words(arr_str[i], '-') != 2
        || mx_count_words(arr_str[i], ',') != 2) {
            clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
            mx_print_error(i);
        }

        vertix1 = mx_part1(arr_str[i]);
        vertix2 = mx_part2(arr_str[i]);
        
        mx_check_vertix(vertix1, vertix2, arr_str, array, count_islands, lines, i);
        mx_check_vertix(vertix2, vertix1, arr_str, array, count_islands, lines, i);
        if (!mx_present(vertix1, array, j)) array[j++] = mx_strdup(vertix1);
        mx_check_islands(vertix1, vertix2, array, arr_str, lines, count_islands, j, false);
        if (!mx_present(vertix2, array, j)) array[j++] = mx_strdup(vertix2);
        mx_check_islands(vertix1, vertix2, array, arr_str, lines, count_islands, j, false);
        
        if (!mx_strcmp(vertix1, vertix2)) {
            clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
            mx_print_error(i);
        }

        int index_coma = mx_get_char_index(arr_str[i], ',');
        char *after_coma = mx_strdup(arr_str[i] + index_coma + 1);

        int temp_length = mx_atoi(after_coma);
        sum += temp_length;

        if (temp_length == 0) {
            clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
            free(after_coma);
            mx_print_error(i);
        }
        free(after_coma);
    }
    mx_check_islands(vertix1, vertix2, array, arr_str, lines, count_islands, j, true);
    
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            if (i == j) continue;
            char *temp01 = mx_part3(arr_str[i]);
            char *temp02 = mx_part3(arr_str[j]);
            if (mx_strcmp(temp01, temp02) == 0) {
                clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
                mx_strdel(&temp01);
                mx_strdel(&temp02);
                duplication_error();
            }
            mx_strdel(&temp01);
            mx_strdel(&temp02);
        }
    }
    if (sum > __INT_MAX__) {
        clean_other_errors(vertix1, vertix2, arr_str, array, lines, count_islands);
        lenght_error();
    }
    return array;
}
