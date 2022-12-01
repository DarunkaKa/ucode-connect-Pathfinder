#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    if (len == 0 || len < 0) {
        return NULL;
    }
    unsigned char *a = (unsigned char *)b;
    if (a == NULL) {
        return NULL;
    }
    unsigned char temp = (unsigned char)c;
    for (size_t i = 0; i < len; i++) {
        a[i] = temp;
    }
    return b;
}

