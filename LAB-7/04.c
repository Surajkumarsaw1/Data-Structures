#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value);
int dequeue();
void display();
int isEmpty();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            if (!isEmpty())
            {
                printf("Deleted element: %d\n", dequeue());
            }
            else
            {
                printf("Queue is empty. Cannot delete.\n");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            // return 0;
            exit(0);
            break;
        default:
            printf("Invalid option. Please enter a valid choice.\n");
        }
    };

    return 0;
}

void enqueue(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot insert element %d.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    rear->next = front;

    printf("Inserted %d into the queue.\n", value);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    }

    int deletedValue = front->data;
    Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
    return deletedValue;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int isEmpty()
{
    return front == NULL;
}
