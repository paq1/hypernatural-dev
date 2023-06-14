#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

typedef struct list_t {
    void* data;
    struct list_t* next;
} list_t;

list_t* list_create(void* data);
list_t* list_add_sorted(list_t* old, void* data);
list_t* list_prepend(list_t* old, void* data);
unsigned int list_length(list_t* list);
void* get_data_list_at_index(list_t* list, unsigned int index);
void free_list(list_t** list);
bool exist_list_int(list_t* list, int data);
void printf_list_int(list_t* list);

#endif // __LIST_H__
