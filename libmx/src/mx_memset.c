#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *a = (unsigned char *)b;
    unsigned char temp = (unsigned char)c;
    for (size_t i = 0; i < len; i++) {
        a[i] = temp;
    }
    return b;
}

