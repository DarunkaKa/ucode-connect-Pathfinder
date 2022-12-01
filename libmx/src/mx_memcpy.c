#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    if (n == 0 || n < 0) {
        return NULL;
    }
    unsigned char *dst1 = (unsigned char *)dst;
    unsigned char *src1 = (unsigned char *)src;
    if (dst1 == NULL || src1 == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        dst1[i] = src1[i];
    }
    return dst;
}

