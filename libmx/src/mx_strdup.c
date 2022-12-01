#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
	int len = mx_strlen(s1);
	char *temp = mx_strnew(len);
	return mx_strcpy(temp, s1);
}

