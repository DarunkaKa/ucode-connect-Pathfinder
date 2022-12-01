#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) { 
        return -1;
    }
	int count_words = 0;   
    int i = 0;    	
    bool temp = false;
	if (mx_strlen(str) == 0) {
		return count_words;
	}
	const char *s = str;
	int count_c = 0;
	for (int j = 0; j < mx_strlen(s); j++) { 
		if (s[j] == c) {
			count_c++;
		}
	}
	if (mx_strlen(s) == count_c) {
		return 0;
	}

    if (str[i++] == c) {
        temp = true;
    } 
    else {
        count_words++;
    }

    while (str[i] != '\0') {
        if (str[i] == c && str[i + 1] != c) {
        	temp = true;
        }
        else if (temp) {
			count_words++;
           	temp = false;		
        }
        i++;
    }    
	
    return count_words;
}

