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

