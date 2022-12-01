#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	if (s1 == NULL) {
		return NULL;
	}
	char *temp = mx_strnew(n);
	return mx_strncpy(temp, s1, n);
}


