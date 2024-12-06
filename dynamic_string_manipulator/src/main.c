#include <stdio.h>
#include "../src/dynamic_string.h"

int main()
{
    DynamicString* ptr_str = create_string(10);

    printf("Initial String: %s\n", ptr_str->data);

    append_string(ptr_str, "Hello");

    printf("After append: %s\n", ptr_str->data);

    append_string(ptr_str, " World!");

    printf("After second append: %s\n", ptr_str->data);

    return 0;
}
