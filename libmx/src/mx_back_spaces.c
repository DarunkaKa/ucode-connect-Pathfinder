#include "../inc/libmx.h"

int mx_back_spaces(const char *str) {
	int count_spaces = 0;
	for (int i = mx_strlen(str) - 1; i >= 0 && mx_isspace(str[i]); i--) {
		count_spaces++;
	}
	return count_spaces;
}
