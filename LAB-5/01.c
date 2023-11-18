// Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};
typedef struct Node node;

node *addNodeLast(node *start, int *coff, int *power);
node *input_polynomial();
void traverseSLL(node *start);
void printPolySLL(node *start);
node *sum_poly(node *poly1, node *poly2);

void freeLinkedList(node *start);

int main()
{
    // node *poly1, *poly2;
    // poly1 = (node *)malloc(sizeof(node));
    // poly2 = (node *)malloc(sizeof(node));
    // input_polynomial(poly1);
    // input_polynomial(poly2);

    node *poly1 = input_polynomial(), *poly2 = input_polynomial(), *sum;

    printPolySLL(poly1);
    printPolySLL(poly2);

    sum = sum_poly(poly1, poly2);
    if (sum != NULL)
    {
        printf("\nSum of polynomials is: ");
        printPolySLL(sum);
    }
    else
    {
        printf("\nError in addition\n");
    }
    freeLinkedList(poly1);
    freeLinkedList(poly2);
    freeLinkedList(sum);

    return 0;
}

node *addNodeLast(node *start, int *coff, int *power)
{
    node *newnode, *last;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.");
        return start;
    }
    if (coff == NULL)
    {
        printf("Enter coefficient of new node : ");
        scanf("%d", &newnode->coefficient);
    }
    else
    {
        newnode->coefficient = *coff;
    }

    if (power == NULL)
    {
        printf("Enter power of new node : ");
        scanf("%d", &newnode->exponent);
    }
    else
    {
        newnode->exponent = *power;
    }

    newnode->next = NULL;

    if (start == NULL)
    {
        // printf("Empty List.\nCreating new SLL.\n");
        start = newnode;
        return start;
    }
    else
    {

        last = start;

        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
    }
    return start;
}

node *input_polynomial()
{
    int degree, temp_coefcnt;
    node *start = NULL;
    printf("Enter the degree of polynomial : ");
    scanf("%d", &degree);
    printf("Enter Polynomial from highest degree to lowest degree : 4 2 3 (Hint: 4x^2+2+3): ");
    for (int n = degree; n >= 0; n--)
    {
        scanf("%d", &temp_coefcnt);
        if (temp_coefcnt != 0)
        {
            start = addNodeLast(start, &temp_coefcnt, &n);
        }
    }
    return start;
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
        printf("\nListing ....\n");
        temp = start;
        printf("Start -> ");
        do
        {
            printf("%dx^%d -> ", temp->coefficient, temp->exponent);
            temp = temp->next;
            // if (temp != NULL)
            // {
            //     printf(" -> ");
            // }
        } while (temp != NULL);
        printf("End\n");
    }
}

void printPolySLL(node *start)
{
    node *temp;
    if (start == NULL)
    {
        printf("\nPolynomial : 0\n");
    }
    else
    {
        // printf("\nListing ....\n");
        temp = start;
        // printf("Start -> ");
        printf("\nPolynomial : ");
        do
        {
            if (temp->exponent > 1)
            {
                printf("%dx^%d", temp->coefficient, temp->exponent);
            }
            else if (temp->exponent == 1)
            {
                printf("%dx", temp->coefficient);
            }
            else if (temp->exponent == 0)
            {
                printf("%d", temp->coefficient);
            }

            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
            }
        } while (temp != NULL);
        // printf("End\n");
        printf("\n");
    }
}

node *sum_poly(node *poly1, node *poly2)
{
    int degree;
    node *start = NULL, *sum = NULL, *prev = NULL;

    if (poly1 == NULL && poly2 == NULL)
    {
        printf("[ERROR] both the polynomials are ZERO.\n");
    }
    else if ((poly1 == NULL || poly2 == NULL))
    {
        printf("[WARNING] only one polynomial.\n");
        printf("[NOTE] Returning the non-zero polynomial.\n");
        if (poly1 == NULL)
        {
            return poly2;
        }
        else
        {
            return poly1;
        }
    }

    // while (poly1 != NULL && poly2 != NULL && poly1->next != NULL && poly2->next != NULL)
    while (poly1 != NULL && poly2 != NULL)
    {
        sum = (node *)malloc(sizeof(node));

        if (sum == NULL)
        {
            printf("Memory allocation failed.");
            return start;
        }

        if (start == NULL)
        {
            start = sum;
        }

        if (poly1->exponent == poly2->exponent)
        {
            sum->exponent = poly1->exponent;
            sum->coefficient = poly1->coefficient + poly2->coefficient;
            // sum->next = NULL;
            // prev = sum;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exponent > poly2->exponent)
        {
            sum->exponent = poly1->exponent;
            sum->coefficient = poly1->coefficient;
            // sum->next = NULL;
            // prev = sum;
            poly1 = poly1->next;
            // poly2 = poly2->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {

            sum->exponent = poly2->exponent;
            sum->coefficient = poly2->coefficient;
            // sum->next = NULL;
            // prev = sum;
            // poly1 = poly1->next;
            poly2 = poly2->next;
        }
        sum->next = NULL;
        if (prev != NULL)
        {
            prev->next = sum;
        }
        prev = sum;
    }
    return start;
}

void freeLinkedList(node *start)
{
    node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}
