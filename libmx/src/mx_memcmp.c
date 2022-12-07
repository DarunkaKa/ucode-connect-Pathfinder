#include "../inc/libmx.h" 

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    size_t i = 0;
    while (i < n && ((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s1)[i] != '\0') {
        if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]) {
            return (int)((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
        }
        i++;
    }    
    return 0; 
}

