#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	if (s1 == NULL && s2 == NULL) {
		return NULL;
	}
	if (s1 != NULL && s2 != NULL) {
		int len_new = mx_strlen(s1) + mx_strlen(s2);
		char *temp = mx_strnew(len_new);
		temp = mx_strcat(temp, s1);
		return mx_strcat(temp, s2);
	}
	if (s1 == NULL && s2 != NULL) {
		char *temp_s2 = mx_strdup(s2);
		return temp_s2;
	}
	if (s1 != NULL && s2 == NULL) {
		char *temp_s1 = mx_strdup(s1);
		return temp_s1;
	}
	return NULL;
}

