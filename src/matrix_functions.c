#include "../inc/pathfinder.h"

// рядок після коми
char *mx_part4(char *s) {
    int index_coma = mx_get_char_index(s, ',');
    char *result = mx_strdup(s + index_coma + 1);
    return result;
}

int **matrix_empty(int count_islands) {
    int **matrix = malloc(sizeof(int *) * count_islands);
    for (int i = 0; i < count_islands; i++) {
        matrix[i] = malloc(sizeof(int) * count_islands);
        for (int j = 0; j < count_islands; j++) {
            matrix[i][j] = 99999999;
        }
    }
    return matrix;
}

int mx_return_index_element(char **array, char *element, int count_islands) {
    for (int i = 0; i < count_islands; i++) {
        if (mx_strcmp(array[i], element) == 0) {
            return i;
        }
    }
    return -1;
}

void matrix_full(char **array_str, char **array, int lines, int count_islands, int **matrix) {
    for (int i = 1; i < lines; i++) {
        char *first_island = mx_part1(array_str[i]);
        int index_first = mx_return_index_element(array, first_island, count_islands);
        char *second_island = mx_part2(array_str[i]);
        int index_second = mx_return_index_element(array, second_island, count_islands);
        free(first_island);
        free(second_island);
        if (index_first != -1 && index_second != -1) {
            char *digit = mx_part4(array_str[i]);
            int number = mx_atoi(digit);
            matrix[index_first][index_second] = number;
            matrix[index_second][index_first] = number;
            free(digit);
        }
    }
}

