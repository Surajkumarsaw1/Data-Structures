#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE], front = -1, rear = -1;

int append(int *);

int pop(int *);

void traverse(int *);

int isEmpty();

int main()
{
    int choice;
    do
    {
        printf("\n1.APPEND\n");
        printf("2.POP\n");
        printf("3.TRAVERSE\n");
        printf("4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            append(queue);
            break;
        case 2:
            pop(queue);
            break;
        case 3:
            printf("QUEUE : ");
            traverse(queue);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("[WARNING] Invalid Option.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

int append(int *queue)
{
    if (rear != QUEUE_SIZE - 1)
    {
        // assign value to first
        if (front == -1)
        {
            front = 0;
        }
        ++rear;
        printf("Enter the queue data:");
        scanf("%d", &(queue[rear]));
        // queue[rear] = 5;
        return queue[rear];
    }
    else
    {
        printf("QUEUE OVERFLOW\n");
    }
}

int pop(int *queue)
{
    if (isEmpty())
    {
        printf("QUEUE UNDERFLOW");
        return 0;
    }
    else
    {
        if (front > rear)
        {
            printf("QUEUE UNDERFLOW");
            return 0;
        }

        printf("Popped element : %d", front);

        if (front == rear)
        {
            front = rear = -1;
            return queue[front + 1];
        }
        return queue[front++];
    }
}

void traverse(int *queue)
{
    if ((front == -1) || (rear == -1))
    {
        printf("\nEmpty queue.\n\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int isEmpty()
{
    if (rear == -1 && front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}