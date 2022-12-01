#pragma once

#include "../libmx/inc/libmx.h"

void mx_printerr(const char *s);
int mx_atoi(const char *str);
void mx_print_error(int i);
void error1(int argc);
void error2(char *argv);
void error3(char *str, char *argv);
void error4(void);
char **other_errors(char **arr_str, int count_islands, int lines);
void duplication_error(void);
void lenght_error(void);
void islands_error(void);
int mx_check_item (char **str);
char **arr_islands(char **str_file, int count_islands);

void mx_clean_arr(char **array, int length);
char **mx_get_array_all_islands(char *str);
void mx_printerr(const char *s);
bool mx_alphabet(int c);
void islands_error(void);
void clean_other_errors(char *vertix1, char *vertix2, char **arr_str, char **array, int lines, int count_islands);
void mx_check_vertix(char *vertix, char *vertix1, char **arr_str, char **array, int count_islands, int lines, int line);
void mx_check_islands(char *vertix1, char *vertix2, char **array, char **arr_str, int lines, int count_islands, int j, bool end);
void mx_clean_arr_int(int **array, int length);
char *mx_part1(char *s);
char *mx_part2(char *s);
void matrix_full(char **array_str, char **array, int lines, int count_islands, int **matrix);
int mx_return_index_element(char **array, char *element, int count_islands);
int **matrix_empty(int count_islands);
void mx_algoritm_floyds(int **matrix_copy, int numberOfVert);
void mx_output(char **array, int **matrix, int **matrix_of_paths, int count_islands, int *distance, int steps);
