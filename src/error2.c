#include "../inc/pathfinder.h"

//немає файлу
void error2(char *argv) {
    int fd = open(argv, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(0);
    }
}
