#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {   
    unsigned char *temp = malloc(len * sizeof(unsigned char));
    for (size_t i = 0; i < len; i++) {
        temp[i] = ((unsigned char *)src)[i];
    }
    for (size_t j = 0; j < len; j++) {
        ((unsigned char *)dst)[j] = temp[j];
    }
    free(temp);
    return dst;
}

