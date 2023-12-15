// Write a menu driven program to perform the following operations in a binary search tree:
//         a. Insert in node in BST
//         b. Search a node in BST
//         c. Display (preorder) in BST
//         d. Display (inorder) in BST
//         e. Display (postorder) in BST
//         f. Find largest element
//         g. Find smallest element
//         h. Delete the element
//         i. Quit

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *insert(Node *root, int value);
Node *search(Node *root, int value);
void displayPreorder(Node *root);
void displayInorder(Node *root);
void displayPostorder(Node *root);
Node *findLargest(Node *root);
Node *findSmallest(Node *root);
Node *deleteNode(Node *root, int value);
void destroyTree(Node *root);

int main()
{
    Node *root = NULL;
    int choice, value;
    Node *result;

    printf("\n1. Insert a node\n");
    printf("2. Search a node\n");
    printf("3. Display (Preorder)\n");
    printf("4. Display (Inorder)\n");
    printf("5. Display (Postorder)\n");
    printf("6. Find largest element\n");
    printf("7. Find smallest element\n");
    printf("8. Delete a node\n");
    printf("9. Quit\n");
    
    while (1)
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            result = search(root, value);
            if (result != NULL)
            {
                printf("Node with value %d found in the BST.\n", value);
            }
            else
            {
                printf("Node with value %d not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("Preorder Traversal: ");
            displayPreorder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder Traversal: ");
            displayInorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            displayPostorder(root);
            printf("\n");
            break;
        case 6:
            result = findLargest(root);
            if (result != NULL)
            {
                printf("Largest element in the BST: %d\n", result->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        case 7:
            result = findSmallest(root);
            if (result != NULL)
            {
                printf("Smallest element in the BST: %d\n", result->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        case 8:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 9:
            destroyTree(root);
            printf("BST is destroyed. Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid option. Please enter a valid choice.\n");
        }
    }

    return 0;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *search(Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void displayPreorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayInorder(Node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

void displayPostorder(Node *root)
{
    if (root != NULL)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

Node *findLargest(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

Node *findSmallest(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node *temp = findSmallest(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void destroyTree(Node *root)
{
    if (root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
