// Write a menu driven program to implement of Circular queue operations using array. The operation are such as :-
//     1. Insert
//     2. Delete
//     3. Display
//     4. Exit

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 4

int c_queue[QUEUE_SIZE], front = -1, rear = -1;

int append(int *);

int pop(int *);

void traverse(int *);

int isEmpty();

int main()
{
    int choice;
    do
    {
        printf("\n\n1.APPEND\n");
        printf("2.POP\n");
        printf("3.TRAVERSE\n");
        printf("4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            append(c_queue);
            break;
        case 2:
            pop(c_queue);
            break;
        case 3:
            printf("QUEUE : ");
            traverse(c_queue);
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

int append(int *c_queue)
{
    if (((rear + 1) % QUEUE_SIZE) != front)
    {
        // assign value to first
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % QUEUE_SIZE;
        printf("Enter the queue data:");
        scanf("%d", &(c_queue[rear]));
        return c_queue[rear];
    }
    else
    {
        printf("QUEUE OVERFLOW\n");
    }
}

int pop(int *c_queue)
{
    if (isEmpty())
    {
        printf("QUEUE UNDERFLOW");
        return 0;
    }
    else
    {
        printf("Deleted : %d",c_queue[front]);
        
        if (front == rear)
        {
            int temp = c_queue[front];
            front = rear = -1;
            return temp;
        }
        
        return c_queue[front++];
    }
}

void traverse(int *c_queue)
{
    if (isEmpty())
    {
        printf("\nEmpty queue.\n\n");
    }
    else
    {
        int i = front;
        do
        {
            printf("%d ", c_queue[i]);
            i = (i + 1) % QUEUE_SIZE;
        } while (i != (rear + 1) % QUEUE_SIZE);
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