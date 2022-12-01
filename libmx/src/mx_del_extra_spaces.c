#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	char *temp = mx_strnew(mx_strlen(str));
	int j = 0;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (!mx_isspace(str[i])) {
			temp[j] = str[i];
			j++;
		}
		if (mx_isspace(str[i]) 
			&& !mx_isspace(str[i + 1])) {
				temp[j] = ' ';
				j++;
		}
	}
	char *new_str = mx_strtrim(temp);
	mx_strdel(&temp);
	return new_str;
}

	
