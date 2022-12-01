#include "../inc/libmx.h"

int mx_front_spaces(const char *str) {
	int count_spaces = 0;
	for (int i = 0; i < mx_strlen(str) - 1 && mx_isspace(str[i]); i++) {
		count_spaces++;
	}
	return count_spaces;
}

