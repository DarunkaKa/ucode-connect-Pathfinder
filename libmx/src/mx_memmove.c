#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    if (len == 0 || len < 0) {
        return NULL;
    }    
    unsigned char *dst1 = (unsigned char *)dst;
    unsigned char *src1 = (unsigned char *)src;
    if (dst1 == NULL || src1 == NULL) {
        return NULL;
    }
    unsigned char *temp = malloc(len * sizeof(unsigned char));
    for (size_t i = 0; i < len; i++) {
        temp[i] = src1[i];
    }
    for (size_t j = 0; j < len; j++) {
        dst1[j] = temp[j];
    }
    free(temp);
    return dst;
}


