#include "../inc/libmx.h"

void mx_free(t_list **list) {
    free(*list);
    *list = NULL;
}
