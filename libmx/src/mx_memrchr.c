#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    if (n == 0 || n < 0) {
        return NULL;
    }
    unsigned char *str = (unsigned char *)s;
    if (str == NULL) {
        return NULL;
    }
    unsigned char temp = (unsigned char)c;
    for (size_t i = n; i >= 0; i--) {
        if (str[i] == temp) {
            return &str[i];
        }
    }
    return NULL;
}

