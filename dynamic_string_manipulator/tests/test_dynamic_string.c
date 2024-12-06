#include <unity.h>
#include "../src/dynamic_string.h"

//Test setup and taredown functions
void setUp(void)
{
}

void tearDown(void)
{
}


void test_create_string(void)
{
    DynamicString *str = create_string(10);

    TEST_ASSERT_NOT_NULL(str);
    TEST_ASSERT_EQUAL(0, str->length);
    TEST_ASSERT_EQUAL(10, str->capacity);
    free_string(str);
}

void test_append_string(void)
{
    DynamicString *str = create_string(10);
    append_string(str, "Hello");
    TEST_ASSERT_EQUAL_STRING("Hello", str->data);
    
    append_string(str, " World!");
    TEST_ASSERT_EQUAL_STRING("Hello World!", str->data);
    
    free_string(str);
}

// Example test suite
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_create_string);
    RUN_TEST(test_append_string);
    
    UNITY_END();

    return 0;
}
