#include "../inc/libmx.h" 

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char temp = (unsigned char)c;
    size_t i = 0;
    while (i < n) {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        if (((unsigned char *)src)[i] == temp) {
            return(void *restrict)((unsigned char *)dst + i + 1);
        }        
        i++;
    }
    return NULL;
}

