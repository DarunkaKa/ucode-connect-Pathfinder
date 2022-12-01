#include "../inc/pathfinder.h"

static void mx_replace_twoarray_int(int **matrix_copy, int islands, int big_value, int other_value) {
    for (int i = 0; i < mx_pow(islands, 2); i++) {
        int i1 = i / islands;
        int i2 = i % islands;
        if (matrix_copy[i1][i2] != big_value) continue;
        matrix_copy[i1][i2] = other_value;
    }
}

void mx_algoritm_floyds(int **matrix_copy, int islands) {
    int big_value = 99999999;

    for (int k = 0 ; k < islands; k++) {
        for (int i = 0; i < mx_pow(islands, 2); i++) {
            int i1 = i / islands;
            int i2 = i % islands;
            if (i1 == i2 || matrix_copy[i1][k] == big_value || matrix_copy[k][i2] == big_value) continue;
            int temp = matrix_copy[i1][k] + matrix_copy[k][i2];
            matrix_copy[i1][i2] = matrix_copy[i1][i2] == big_value ? temp : (temp <= matrix_copy[i1][i2] ? temp : matrix_copy[i1][i2]);
        }
    }
    
    mx_replace_twoarray_int(matrix_copy, islands, big_value, 0);
}
