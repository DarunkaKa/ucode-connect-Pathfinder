#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if ((*head)->next == NULL) {
        mx_free(head);
    }
    t_list *new_head = NULL;
    new_head = (*head)->next;
    free(*head);
    *head = new_head;
}


