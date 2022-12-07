#include "../inc/libmx.h" 

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (size <= malloc_size(ptr)) { //malloc_usable_size(ptr)
        return ptr;
    }
    if (size > malloc_size(ptr)) {
        void *new_ptr = malloc(size);
        if (new_ptr != NULL) {
            mx_memmove(new_ptr, ptr, size);
            free(ptr);
        }
        return new_ptr;
    }
    return NULL;
}


