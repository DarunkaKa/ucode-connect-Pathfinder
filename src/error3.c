#include "../inc/pathfinder.h"

//пустий файл
void error3(char *str, char *argv) {
    if (str == NULL) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" is empty\n");
        free(str);
        exit(0);
    }
}
