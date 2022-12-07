#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	char *new_str = NULL;
	if (str == NULL) {
		return NULL;
	}
	else { 
		char *temp = mx_strnew(mx_strlen(str));
		int spaces = 0;
		int letters = 0;
		for (int i = 0; i < mx_strlen(str); i++) {
			if (mx_isspace(str[i])) {
				spaces++;
			}
			letters++;
		}
	
		if (spaces == letters || spaces == mx_strlen(str)) {
			return temp;
		}
		
		else {	
			int j = 0;
			for (int i = 0; i < mx_strlen(str); i++) {
				if (!mx_isspace(str[i])) {
					temp[j] = str[i];
					j++;
				}
				if (!mx_isspace(str[i]) 
					&& mx_isspace(str[i + 1])) {
					temp[j] = ' ';
					j++;
				}
			}
			new_str = mx_strtrim(temp);
			mx_strdel(&temp); 
		}
	}
	return new_str;
}
	
