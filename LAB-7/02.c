#include <stdio.h>
#include <stdlib.h>

// #define QUEUE_SIZE 10

// int queue[QUEUE_SIZE];
// int front = -1, rear = -1;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *create(node *start);
node *insertRear(node *start);

node *insertFront(node *start);

node *deleteFront(node *start);

node *deleteRear(node *start);

void traverse(node *start);

int lenSLL(node *start);

int main()
{
    node *d_queue = NULL;
    int choice;
    do
    {
        printf("\n\n1.INSERT AT REAR END\n");
        printf("2.INSERT AT FRONT END\n");

        printf("3.DELETE AT FRONT END\n");
        printf("4.DELETE AT REAR END\n");

        printf("5.TRAVERSE\n");
        printf("6.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            d_queue = insertRear(d_queue);
            break;
        case 2:
            d_queue = insertFront(d_queue);
            break;
        case 3:
            d_queue = deleteFront(d_queue);
            break;
        case 4:
            d_queue = deleteRear(d_queue);
            break;
        case 5:
            traverse(d_queue);
            break;
        case 6:
            return 0;
            break;
        default:
            printf("[WARNING] Invalid Option.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}

node *create(node *start)
{
    node *newnode, *last;
    char ch;
    if (start == NULL)
    {
        // start node Single Linked List creation.
        do
        {
            newnode = (node *)malloc(sizeof(node));
            printf("Enter data for new node : ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;

            if (start == NULL)
            {
                start = newnode;
                last = newnode;
            }
            else
            {
                last->next = newnode;
                last = newnode;
            }

            // printf("do you want to continue (y/n) : ");
            // scanf(" %c", &ch);
            ch = 'n';
        } while (ch == 'y' || ch == 'Y');
        return (start);
    }
    else
    {
        printf("Linked list already created.\n");
        return start;
    }
}

node *insertRear(node *start)
{
    if (start == NULL)
    {
        printf("Empty Linked List\n");
        start = create(start);
        return start;
    }
    else
    {
        node *newnode, *last;
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.");
            return start;
        }
        printf("Enter data of new node : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        last = start;

        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
    }
    return start;
}

node *insertFront(node *start)
{
    if (start == NULL)
    {
        printf("Empty List\n");
        start = create(start);
        return start;
    }
    else
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.");
            return start;
        }
        printf("Enter data of new node : ");
        scanf("%d", &newnode->data);
        newnode->next = start;
        start = newnode;
        return start;
    }
}

void traverse(node *start)
{
    node *temp;
    if (start == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        printf("\nQUEUE : \n");
        temp = start;
        printf("Front -> ");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
            // if (temp != NULL)
            // {
            //     printf(" -> ");
            // }
        } while (temp != NULL);
        printf("Rear\n");
    }
}

node *deleteFront(node *start)
{
    if (start == NULL)
    {
        printf("Empty Linked list.\n");
        return start;
    }
    else
    {
        node *prev = start;
        printf("Deleted : %d",prev->data);
        start = start->next;
        free(prev);
        return start;
    }
}

node *deleteRear(node *start)
{
    node *temp = start, *newlast = NULL;
    if (start == NULL)
    {
        printf("Empty Linked list.\n");
        return start;
    }
    else
    {
        while (temp->next != NULL)
        {
            newlast = temp;
            temp = temp->next;
        }
    }
    printf("Deleted : %d",temp->data);
    free(temp);

    // if newlast == NULL means first node is last node.
    if (newlast == NULL)
    {
        return NULL;
    }
    else
    {
        newlast->next = NULL;
        return start;
    }

    return start;
}

int lenSLL(node *start)
{
    int c = 0;
    node *temp = start;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}