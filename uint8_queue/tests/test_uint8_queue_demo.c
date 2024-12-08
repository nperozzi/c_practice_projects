#include <unity.h>
#include "uint8-queue.h"

#define QUEUE_BUFFER_SIZE 5

//Needed variables
uint8_t queue_buffer[QUEUE_BUFFER_SIZE];
uint8_queue_t test_queue;

void setUp(void)
{
    init_queue(&test_queue, queue_buffer, sizeof(queue_buffer));
}

void tearDown(void)
{
}

void test_init_queue(void)
{
    TEST_ASSERT_EQUAL(0, test_queue.front);
    TEST_ASSERT_EQUAL(0, test_queue.rear);
    TEST_ASSERT_TRUE(queue_is_empty(&test_queue));
    TEST_ASSERT_FALSE(queue_is_full(&test_queue));
    TEST_ASSERT_FALSE(has_queue_overflowed(&test_queue));
    TEST_ASSERT_EQUAL(5, test_queue.size);
    //Assert function for comparing pointers
}

void test_add_to_queue(void)
{
    add_to_queue(&test_queue, 42);
    TEST_ASSERT_FALSE(queue_is_empty(&test_queue));
    TEST_ASSERT_EQUAL_UINT8(42, test_queue.data[test_queue.front]);
}

void test_queue_overflow(void)
{
    TEST_ASSERT_FALSE(has_queue_overflowed(&test_queue));
    for(int i = 0; i < QUEUE_BUFFER_SIZE; i++)
    {
        add_to_queue(&test_queue, i);
    }
    TEST_ASSERT_TRUE(queue_is_full(&test_queue));
    add_to_queue(&test_queue, 99); //this should ovdrflow the queue
    TEST_ASSERT_TRUE(has_queue_overflowed(&test_queue));
}

void test_dequeue(void)
{
    add_to_queue(&test_queue, 11);
    add_to_queue(&test_queue, 22);

    dequeue_return_t result = dequeue(&test_queue);
    TEST_ASSERT_TRUE(result.is_valid);
    TEST_ASSERT_EQUAL_UINT8(11, result.value);

    result = dequeue(&test_queue);
    TEST_ASSERT_TRUE(result.is_valid);
    TEST_ASSERT_EQUAL_UINT8(22, result.value);

    TEST_ASSERT_TRUE(queue_is_empty(&test_queue));
}

void test_dequeue_empty_queue(void) {
    dequeue_return_t result = dequeue(&test_queue);
    TEST_ASSERT_FALSE(result.is_valid);
}
