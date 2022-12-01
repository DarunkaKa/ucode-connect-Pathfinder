#include "../inc/libmx.h"

int mx_strlen_arr(char **arr) {
    int i;
	for (i = 0; arr[i] != NULL; i++);
	return i;
}

