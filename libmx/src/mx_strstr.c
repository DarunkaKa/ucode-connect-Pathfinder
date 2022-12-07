#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) { 
    char *temp = (char *)haystack;
    while (*temp != '\0') {
        if (*temp == *needle) {
            if (mx_strncmp(temp, (char *)needle, mx_strlen(needle)) == 0) {
                return temp;
            }
        }
        temp++; 
    }    
    return NULL;
}

