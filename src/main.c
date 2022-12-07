#include "../inc/pathfinder.h"

static int mx_count_str(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') count++;
    }
    return count;
}

static char *mx_write_str(char *str, int index) {
    char *element = mx_strnew(index);
    for (int i = 0; i < index; i++) {
        element[i] = str[i];
    }
    return element;
}

static char **mx_twoarray_str(char *str, int lines) {
    char **s1 = malloc(lines * sizeof(char *));  
    for (int i = 0; i < lines; i++) {           
        int index = mx_get_char_index(str, '\n');
        s1[i] = mx_write_str(str, index);
        str += index + 1;
    }
    return s1;
}

static void mx_clean_all(char **array, int count_islands, int **matrix, int **temp_matrix, int *distance){
    mx_clean_arr(array, count_islands);
    mx_clean_arr_int(matrix, count_islands);
    mx_clean_arr_int(temp_matrix, count_islands);
    free(distance);
}

int main(int argc, char *argv[]) {
    error1(argc);
    error2(argv[1]);
    
    char *str = mx_file_to_str(argv[1]);
    error3(str, argv[1]);

    int lines = mx_count_str(str);
    char **arr_str = mx_twoarray_str(str, lines);
    free(str);
    int count_islands = mx_atoi(arr_str[0]);
    
    char **array = other_errors(arr_str, count_islands, lines);
    int **matrix = matrix_empty(count_islands);
    matrix_full(arr_str, array, lines, count_islands, matrix);
    
    int **temp_matrix = matrix_empty(count_islands);
    matrix_full(arr_str, array, lines, count_islands, temp_matrix);
    mx_clean_arr(arr_str, lines);
    mx_algoritm_floyds(temp_matrix, count_islands);
    int *distance = malloc((count_islands + 1) * sizeof(int));
    
    for (int i = 0; i < count_islands; i++) {
        for (int j = i + 1; j < count_islands; j++) {
            distance[1] = i;
            distance[0] = j;
            mx_output(array, matrix, temp_matrix, count_islands, distance, 1);
        }
    }
    mx_clean_all(array, count_islands, matrix, temp_matrix, distance);
}
