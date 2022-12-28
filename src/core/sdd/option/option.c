#include "option.h"

#include <stdlib.h>

bool is_some(option_t option) {
    return option.data != NULL;
}

option_t create_some(void* data) {
    return (option_t) { data };
}
option_t create_none() {
    return (option_t) { NULL };
}