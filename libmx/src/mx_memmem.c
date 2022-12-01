#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *str_big = (unsigned char *)big;
    unsigned char *str_lit = (unsigned char *)little;
    if (str_big == NULL || str_lit == NULL) {
        return NULL;
    }
    if (big_len == 0 
        || little_len == 0 
        || big_len < little_len) {
        return NULL;
    }
    while (big_len > 0 && *str_big != '\0') {
        if (*str_big == *str_lit) {
            if (mx_memncmp(str_big, str_lit, little_len) == 0) {
                return str_big;
            }            
        }
        str_big++;
        big_len--;
    }
    return NULL;
}

