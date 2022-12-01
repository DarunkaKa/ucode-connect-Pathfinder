#include "../inc/pathfinder.h"

bool mx_alphabet(int c) {
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
		return true;
	}
	else {
		return false;
	}
}

