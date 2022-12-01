#include "../inc/pathfinder.h"

// друк помилок для ліній
void mx_print_error(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i + 1));
    mx_printerr(" is not valid\n");
    exit(0);
}

// друк помилок при невірній кількості вершин
void islands_error(void) {
    mx_printerr("error: invalid number of islands\n");
    exit(0);
}

// друк помилок при наявності однакових мостів
void duplication_error(void) {
   mx_printerr("error: duplicate bridges\n");
   exit(0);
}

// занадто велика довжина усіх шляхів
void lenght_error(void) {
    mx_printerr("error: sum of bridges lengths is too big\n");
    exit(0);
}
