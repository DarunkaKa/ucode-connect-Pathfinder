#include "../inc/pathfinder.h"

//відсутній аргумент
void error1(int argc) {
     if (argc < 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
}
