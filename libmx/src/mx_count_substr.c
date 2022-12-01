#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	if (str == NULL || sub == NULL) {
		return -1;
	}
	if (sub[0] == '\0') {
		return 0;
	}
    int len = mx_strlen(sub);
    int count = 0;
    for (const char *temp = str; mx_strstr(temp, sub) != NULL; temp += len) {
        count++;
        temp = mx_strstr(temp, sub);
    }
	return count;
}


