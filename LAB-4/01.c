#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *create(node *start);
void traverseSLL(node *start);
node *addNodeFirst(node *start);
node *addNodeLast(node *start);
node *insertNode(node *start);
node *delFirst(node *start);
node *delLast(node *start);
node *delete_specific(node *start);
int lenSLL(node *start);
int searchNode(node *start, int value);
int searchSLL(node *start);
void deleteSLL(node *start);

int main()
{
    int choice;
    // char exit;

    node *start = NULL;

    while (1)
    {
        printf("1. Create a Single Linked List.\n");
        printf("2. Display the list\n");
        printf("3. Add/Insert a node\n"); // first, last, specified
        printf("4. Delete a node\n");     // first, last, specified
        printf("5. Count the total number of nodes\n");
        printf("6. Search for an element in the linked list\n");
        printf("7. Delete Single Linked List.\n");
        printf("0. Exit\n");

        printf("Enter : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            start = create(start);
            break;
        case 2:
            traverseSLL(start);
            break;
        case 3:
            printf("1. Insert at first\n");
            printf("2. Insert at last\n");
            printf("3. Insert at specific\n");
            printf("Enter : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                start = addNodeFirst(start);
            }
            else if (choice == 2)
            {
                start = addNodeLast(start);
            }
            else if (choice == 3)
            {
                start = insertNode(start);
            }
            else
            {
                printf("Wrong choice.\n");
            }
            break;
        case 4:
            printf("1. Delete at first\n");
            printf("2. Delete at last\n");
            printf("3. Delete at specific\n");
            printf("Enter : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                start = delFirst(start);
            }
            else if (choice == 2)
            {
                start = delLast(start);
            }
            else if (choice == 3)
            {
                start = delete_specific(start);
            }
            else
            {
                printf("Wrong choice.\n");
            }
            break;
        case 5:
            printf("Number of node : %d\n", lenSLL(start));
            break;
        case 6:
            searchSLL(start);
            break;
        default:
            printf("\n\tWrong choice.\n");
            break;
        }

        // printf("Continue to main menu (Y/N) : ");
        // scanf(" %c", &exit);
        // if (exit == 'Y' || exit == 'y')
        // {
        //     continue;
        // }
        // else if (exit == 'N' || exit == 'n')
        // {
        //     break;
        // }
        // else
        // {
        //     printf("Panic exit. :=\\");
        //     break;
        // }
    }

    return 0;
}

// create linklist
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

            printf("do you want to continue (y/n) : ");
            // ch = getch();
            scanf(" %c", &ch);
        } while (ch == 'y' || ch == 'Y');
        return (start);
    }
    else
    {
        printf("Linked list already created.\n");
        return start;
    }
}

void traverseSLL(node *start)
{
    node *temp;
    if (start == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        printf("\nLinklist Elements : \n");
        temp = start;
        printf("Start -> ");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
            // if (temp != NULL)
            // {
            //     printf(" -> ");
            // }
        } while (temp != NULL);
        printf("End\n");
    }
}

node *addNodeFirst(node *start)
{
    if (start == NULL)
    {
        printf("Empty List");
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

node *addNodeLast(node *start)
{
    if (start == NULL)
    {
        printf("Empty List");
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

node *insertNode(node *start)
{
    int len = lenSLL(start);
    if (start == NULL)
    {
        printf("Empty List");
        return start;
    }
    else
    {
        int position_to_insert, count = 0;
        node *newnode, *temp, *last;
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.");
            return start;
        }
        printf("Enter the postion to insert (1-%d): ", len);
        scanf("%d", &position_to_insert);
        if (position_to_insert > len + 1 || position_to_insert < 1)
        {
            printf("[ERROR] Out of index.");
            return start;
        }

        if (position_to_insert == 1)
        {
            addNodeFirst(start);
            return (start);
        }
        // else if (position_to_insert == len + 1)
        // {
        //     addNodeLast(start);
        //     return start;
        // }
        else
        {
            temp = start;

            while (temp->next != NULL && count != position_to_insert - 1)
            {
                count++;
                last = temp;
                temp = temp->next;
            }

            printf("Enter data of new node : ");
            scanf("%d", &newnode->data);
            newnode->next = temp;

            last->next = newnode;
            return start;
        }
    }
}

node *delFirst(node *start)
{
    if (start == NULL)
    {
        printf("Empty list.\n");
        return start;
    }
    else
    {
        node *prev = start;
        start = start->next;
        free(prev);
        return start;
    }
}

node *delLast(node *start)
{
    node *temp = start, *newlast = NULL;
    if (start == NULL)
    {
        printf("Empty list.\n");
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

node *delete_specific(node *start)
{
    node *temp = start, *last = NULL;
    int choice, pos = 0, count = 0, value, len = lenSLL(start);

    if (start == NULL)
    {
        printf("Empty list.\n");
        return start;
    }
    else
    {
        printf("1. Delete by position\n");
        printf("2. Delete by value\n");
        printf(">>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // int max = count(start);
            printf("\nEnter the postion to delete (1-%d): ", len);
            scanf("%d", &pos);
            if (pos > len || pos < 1)
            {
                printf("[ERROR] Out of Index.\n");
                return start;
            }
            while (temp->next != NULL && count + 1 != pos)
            {
                // printf("temp = %p, last = %p\n", temp, last);
                last = temp;
                temp = temp->next;
                count++;
            }

            if (pos == count + 1)
            {
                printf("Position Found.\n");
                if (pos == 1)
                {
                    start = delFirst(start);
                    return start;
                }
                else if (pos == len)
                {
                    start = delLast(start);
                    return start;
                }
                else
                {
                    last->next = temp->next;
                    free(temp);
                    return start;
                }
            }
            break;
        case 2:
            printf("Enter the value to delete : ");
            scanf("%d", &value);

            while (temp->next != NULL && temp->data != value)
            {
                // printf("temp = %p, last = %p\n", temp, last);
                last = temp;
                temp = temp->next;
                count++;
            }
            if (temp->data == value)
            {
                printf("Value Found.\n");
                if (count + 1 == 1)
                {
                    start = delFirst(start);
                    return start;
                }
                else if (count + 1 == len)
                {
                    start = delLast(start);
                    return start;
                }
                else
                {
                    last->next = temp->next;
                    free(temp);
                    return start;
                }
                break;
            }
        }
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

int searchNode(node *start, int value)
{
    int pos = 0;
    if (start != NULL)
    {
        while (start != NULL)
        {
            pos++;
            if (start->data == value)
            {
                return pos;
            }
            start = start->next;
        }
    }
    return 0;
}

int searchSLL(node *start)
{
    int value, pos;
    printf("Enter the value to search : ");
    scanf("%d", &value);
    pos = searchNode(start, value);
    if (pos)
    {
        printf("Value %d found at postion : %d.\n", value, pos);
    }
    else
    {
        printf("Value not found.\n");
    }
    return pos;
}

void deleteSLL(node *start)
{
    node *next;
    while (start != NULL)
    {
        next = start->next;
        free(start);
        start = next;
    }
}