#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if (len <= 0 || dst == NULL) {
        return NULL;
    }
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}



