#include <stdio.h>
#include <string.h>
#include "../src/dynamic_string.h"

DynamicString *create_string(size_t initial_capacity)
{
    DynamicString *str = (DynamicString *) malloc(sizeof(DynamicString)); //the memory for the char data is not alloacted with this, only the memory for the *data (which is an address).
    if (str == NULL)
    {
        perror("Fail to allocate memory for DynamicString");
        exit(EXIT_FAILURE);
    }

    str -> data = (char *)malloc(initial_capacity * sizeof(char));
    if (str -> data == NULL)
    {
        perror("Fail to alloacate memory for the data string");
        free(str);
        exit(EXIT_FAILURE);
    }

    *(str -> data) = '\0';
    str -> length = 0;
    str -> capacity = initial_capacity;

    return str;
}

void append_string(DynamicString *str, const char *suffix)
{
    size_t new_length = str -> length + strlen(suffix);


    // Resize
    if(new_length > str -> capacity)
    {
        str -> capacity = new_length + 1;
        str -> data = (char *)realloc(str -> data, str -> capacity);
        if(str -> data == NULL)
        {
            perror("Fail to realloacte memory for string size.");
            exit(EXIT_FAILURE);
        }
    }

    strcat(str->data, suffix);

    str -> length = new_length;
}

void free_string(DynamicString *str)
{
    free(str->data);
    free(str);
}
