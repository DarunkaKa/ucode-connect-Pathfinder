#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	
	int new_count = 0;
	int front = mx_front_spaces(str);
	int back = 0;//mx_back_spaces(str);

	if (front + back < mx_strlen(str)) {
		new_count = mx_strlen(str) - (front + back);
	} 
	else {
		return NULL; //mx_strnew(0)
	}
	
	str += front;
	char *new = mx_strnew(new_count);

	for (int i = 0; i < new_count; i++) {
		new[i] = *str;
		str++;
	}
	return new;
}

