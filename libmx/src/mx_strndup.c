#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	if (s1 == NULL) {
		return NULL;
	}
	char *temp = mx_strnew(n);
	size_t i = 0;
	while (i < n) {
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return temp;
}

