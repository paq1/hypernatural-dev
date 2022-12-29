#ifndef __OPTION_H__
#define __OPTION_H__

#include <stdbool.h>

typedef struct {
    void* data;
} option_t;

option_t create_some(void* data);
option_t create_none();

bool is_some(option_t option);

#endif // __OPTION_H__