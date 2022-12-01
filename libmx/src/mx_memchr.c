#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    if (n == 0 || n < 0) {
        return NULL;
    }
    unsigned char *str = (unsigned char *)s;
    if (str == NULL) {
        return NULL;
    }
    unsigned char temp = (unsigned char)c;
    for (size_t i = 0; i < n; i++) {
        if (str[i] == temp) {
            return &str[i];
        }
    }
    return NULL;
}

