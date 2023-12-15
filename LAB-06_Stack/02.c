// Write a menu driven program to demonstrate the operations performed on stack using linked list and suitable user defined functions for each case.
// Operations: PUSH, POP, DISPLAY, EXIT

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *top = NULL;

void push(int value);
void pop();
void display();
void traverseStack();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            // display();
            traverseStack();
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot push element %d.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d onto the stack.\n", value);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
        return;
    }

    Node *temp = top;
    top = top->next;

    printf("Popped element: %d\n", temp->data);
    free(temp);
}

// void display() {
//     if (top == NULL) {
//         printf("Stack is empty.\n");
//         return;
//     }

//     printf("Stack elements: ");
//     Node *temp = top;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

void displayReverse(Node *current)
{
    if (current == NULL)
    {
        return;
    }

    // Recursively call the function for the next node
    displayReverse(current->next);

    // Print the data of the current node
    printf("%d ", current->data);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (in reverse order): ");
    displayReverse(top);
    printf("\n");
}

void traverseStack()
{
    Node *start = top;
    Node *temp;
    if (start == NULL)
    {
        printf("Empty Stack.\n");
    }
    else
    {
        printf("\nStack Elements : \n");
        temp = start;
        printf("Top -> ");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
            // if (temp != NULL)
            // {
            //     printf(" -> ");
            // }
        } while (temp != NULL);
        printf("Bottom\n");
    }
}
