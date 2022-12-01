#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *cur01 = lst;
    while(cur01->next != NULL) {
        t_list *cur02 = cur01;
        
        while (cur02->next != NULL) {
            if (cmp(cur01->data, cur02->next->data)) {
                void *temp_data = cur01->data;
                cur01->data = cur02->next->data;
                cur02->next->data = temp_data;
            }
            cur02 = cur02->next;
        }

        cur01 = cur01->next;
    }
    return lst;
}

