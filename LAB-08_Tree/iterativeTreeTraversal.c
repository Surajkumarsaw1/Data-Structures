// Iterative BST traversal (Pre, In, Post) using array stack implementation

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *stack[MAX_SIZE];
int top = -1;

void push(Node *value);
Node *pop();
Node *peek();
int isEmpty();
void traverseStack();

Node *createNode(int value);
Node *insert(Node *root, int value);
void preOrderTraversal(Node *root);
void inOrderTraversal(Node *root);
void postOrderTraversal(Node *root);

int main()
{
    int n, value;
    Node *root;
    // printf("Enter the number of nodes: ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter node value: ");
    //     scanf("%d", &value);
    //     root = insert(root, value);
    // }
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 150);
    root = insert(root, 400);

    printf("\n\n\t----------Pre Order Traversal----------\n");
    preOrderTraversal(root);
    printf("\n\n\t----------In Order Traversal----------\n");
    inOrderTraversal(root);
    printf("\n\n\t----------Post Order Traversal----------\n");
    postOrderTraversal(root);
    return 0;
}

void push(Node *value)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        exit(0);
        return;
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\n\tPushed: %d\n", value->data);
    }
}

Node *pop()
{
    if (top <= -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    else
    {
        return stack[top--];
    }
}

Node *peek()
{
    if (top <= -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    else
    {
        return stack[top];
    }
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    // printf("Enter node value: ");
    // scanf("%d",&(newNode->data));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isEmpty()
{
    if (top <= -1)
    {
        return 1;
    }
    return 0;
}

void traveseStack()
{
    printf("\t-: Top : ");
    if (top < 0)
    {
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]->data);
    }
    printf(":- \n");
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;
    push(curr);
    while (!isEmpty())
    {

        traveseStack();

        curr = pop();
        printf("Popped: %d\n", curr->data);
        if (curr->right != NULL)
        {
            push(curr->right);
        }
        if (curr->left != NULL)
        {
            // curr = curr->left;
            push(curr->left);
        }

        // traveseStack();
        printf("\n");
    }
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;

    while (!isEmpty() || curr != NULL)
    {
        traveseStack();
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("Popped: %d\n", curr->data);

        curr = curr->right;

    }
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;
    Node *lastVisited = NULL;

    while (curr != NULL || !isEmpty())
    {
        traveseStack();
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }

        curr = peek(); // Peek the top of the stack without popping

        // If the right child exists and hasn't been visited yet
        if (curr->right != NULL && curr->right != lastVisited)
        {
            curr = curr->right; // Move to the right subtree
        }
        else
        {
            // Visit the node since both left and right subtrees have been visited or empty
            curr = pop();
            printf("Popped: %d\n", curr->data);
            lastVisited = curr; // Mark the node as visited
            curr = NULL;        // Reset curr to NULL to avoid pushing it back
        }
    }
}
