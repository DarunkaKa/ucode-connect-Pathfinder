#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if ((*head)->next == NULL) {
        mx_free(head);
    }
    t_list *temp;
    temp = *head;
    t_list *new_end = NULL;
    while (temp->next != NULL) {
        new_end = temp;
        temp = temp->next;
    }
    new_end->next = NULL;
    free(temp);
}


