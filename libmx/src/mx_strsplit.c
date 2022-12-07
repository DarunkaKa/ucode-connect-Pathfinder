#include "../inc/libmx.h"

int mx_front_c(const char *str, char c) {
	int count_c = 0;
	for (int i = 0; i < mx_strlen(str) - 1 && str[i] == c; i++) {
		count_c++;
	}
	return count_c;
}

int mx_count_letters(const char *s, char c) {
	int count_letters = 0;
	for (int i = 0; s[i] != c && s[i] != '\0'; i++) {
		count_letters++;
	}
	return count_letters;
}

char **mx_strsplit(char const *s, char c) {
	if (s == NULL) {
		return NULL;
	}

	int new_size = mx_count_words(s, c) + 1;
	char **new_arr = malloc(sizeof(char *) * new_size);
	s += mx_front_c(s, c);
	int j = 0;
	int count_letter = 0;
	for (int i = 0; i < mx_strlen(s); i++) {
		if (s[0] != c) {
			count_letter = mx_count_letters(s, c);
			
			if (count_letter > 0) new_arr[j++] = mx_strndup(s, count_letter);
			
			s += count_letter;
		}
		s++;
	}
	new_arr[j] = NULL;
    return new_arr;
}

		
