#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size < 0) { 
        return -2;
    }
    
    else { 
        (*lineptr) = (char *)mx_realloc(*lineptr, buf_size);
        size_t byt = 0;
        char element;
        int i;
        while ((i = read(fd, &element, 1)) != 0) {
            if (element == delim) {
                break;
            }
            if (element != delim) {
                (*lineptr)[byt] = element;
                byt++;
            }
            if (byt > buf_size) {
                (*lineptr) = (char *)mx_realloc(*lineptr, byt);
            }
            if (i == 0) {
                return -1;
            }		    
	    }        
        return byt;
    }
    return -1;
}

