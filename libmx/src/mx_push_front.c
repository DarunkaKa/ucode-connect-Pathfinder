#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *head_node = mx_create_node(data);
    if (list == NULL || *list == NULL) {
        *list = head_node;
    }
    else {
        head_node->next = *list;
        *list = head_node; 
    }
}

