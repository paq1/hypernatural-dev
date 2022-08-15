#include "list.h"

#include <stdio.h>
#include <stdlib.h>

list_t* create_list(void* data) {
    list_t* list = (list_t*) malloc(sizeof(list_t));
    list->data = data;
    list->next = NULL;
    return list;
}

list_t* list_prepend(list_t* old, void* data) {
    list_t* list = create_list(data);
    if (list) {
        list->next = old;
    }
    return list;
}

unsigned int list_length(list_t* list) {
    unsigned int length = 0;
    while (list) {
        length++;
        list = list->next;
    }
    return length;
}

void* get_data_list_at_index(list_t* list, unsigned int index) {
    unsigned int i = 0;
    while (list && i < index) {
        list = list->next;
        i++;
    }
    return list->data;
}

void free_list(list_t** list) {
    list_t* current = *list;
    while (current) {
        list_t* next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}
