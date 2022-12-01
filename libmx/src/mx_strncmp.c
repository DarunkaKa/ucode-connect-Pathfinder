#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int j = 0;
    while (n > j) {
        if (s1[j] != s2[j]) {
            return s1[j] - s2[j];
        }
        j++;
    }
    return 0;
}

