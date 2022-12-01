#include "../inc/libmx.h"

int mx_memncmp(const void *s1, const void *s2, size_t n) {
    size_t j = 0;
     unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;
    while (n > j) {
        if (str1[j] != str2[j]) {
            return str1[j] - str2[j];
        }
        j++;
    }
    return 0;
}

