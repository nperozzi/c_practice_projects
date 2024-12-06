#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdlib.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} DynamicString;

DynamicString *create_string(size_t initial_capacity);
void append_string(DynamicString *str, const char *suffix);
void free_string(DynamicString *str);
// void insert_string(DynamicString *str, const char *substring, size_t position);
// void remove_substring(DynamicString *str, size_t start, size_t length);

#endif //DYNAMIC_STRING_H
