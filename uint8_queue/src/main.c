#include <stdio.h>
#include "uint8-queue.h"

int main()
{
    uint8_t buffer[5];
    uint8_queue_t queue;

    init_queue(&queue, buffer, sizeof(buffer));

    add_to_queue(&queue, 10);
    add_to_queue(&queue, 20);
    add_to_queue(&queue, 30);

    for (int i = 0; i < 3; i++)
    {
        dequeue_return_t result = dequeue(&queue);
        if(result.is_valid)
        {
            printf("Dequeued value: %d\n", result.value);
        }
        else
        {
            printf("Queue is empty.\n");
        }
    }

    return 0;
}
