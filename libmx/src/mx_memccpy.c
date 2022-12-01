#include "../inc/libmx.h" 

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    if (n == 0 || n < 0) {
        return NULL;
    }
    unsigned char *dst1 = (unsigned char *)dst;
    unsigned char *src1 = (unsigned char *)src;
    if (dst1 == NULL || src1 == NULL) {
        return NULL;
    }
    unsigned char temp = (unsigned char)c;
    size_t i = 0;
    while (n != 0) {
        if (src1[i] == temp) {
            dst1[i] = src1[i];
            break;
        }
        dst1[i] = src1[i];
        i++;
        n--;
    }
    return (void *restrict)dst;
}


