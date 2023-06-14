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

list_t* list_add_sorted(list_t* old, void* data) {
    list_t* node = create_list(data);

    if (old == NULL) {
        return node;
    } else {
        list_t* current = old;
        while (current->next != NULL && (*(int*)(current->next->data)) < *((int*)data)) {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }
    return old;
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

bool exist_list_int(list_t* list, int data) {
    while (list) {
        if (*((int*) list->data) == data) { return true; }
        list = list->next;
    }

    return false;
}

void printf_list_int(list_t* list) {
    printf("evenements : {");
    while (list) {
        int current = *((int*) list->data);
        printf("|%d|", current);
        list = list->next;
    }
    printf("}\n");
}