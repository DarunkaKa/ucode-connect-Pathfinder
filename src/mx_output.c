#include "../inc/pathfinder.h"

static void mx_part_of_path(char **islands, int *distance, int steps) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[distance[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands[distance[0]]);
    mx_printstr("\nRoute: ");
    mx_printstr(islands[distance[1]]);
    mx_printstr(" -> ");

    for (int i = 2; i < steps; i++) {
        mx_printstr(islands[distance[i]]);
        mx_printstr(i < steps ? " -> " : "");
    }

    mx_printstr(islands[distance[0]]);    
    mx_printstr("\nDistance: ");
}

void mx_output(char **islands, int **matrix, int **matrix_of_paths, int nbr_of_islands, int *distance, int steps) {
    int start = distance[0];
    int end = distance[steps];
    int temp = 0;

    while (temp < nbr_of_islands) {
        if((temp != distance[steps] && matrix[end][temp] == matrix_of_paths[end][start] - matrix_of_paths[temp][start])) {
            distance[++steps] = temp;
            mx_output(islands, matrix, matrix_of_paths, nbr_of_islands, distance, steps--);
        }
        temp++;
    }

    if (distance[steps] == start) {
        mx_part_of_path(islands, distance, steps);
        
        if (steps >= 3) {
            for (int i = 1; i < steps; i++) {
                mx_printstr(mx_itoa(matrix[distance[i]][distance[i + 1]]));
                mx_printstr(i < steps - 1 ? " + " : "");
            }
            mx_printstr(" = ");
        }
        
        mx_printstr(mx_itoa(matrix_of_paths[distance[0]][distance[1]]));
        mx_printstr("\n========================================\n");
    }
}
