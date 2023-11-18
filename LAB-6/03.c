#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    char items[MAX_SIZE];
    int top;
};

typedef struct Stack Stack;

void initialize(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
int isOperator(char ch);
int getPrecedence(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Equivalent Postfix Expression is: %s\n", postfix);

    return 0;
}

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix[j++] = infix[i++];
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(infix[i]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(')
            {
                pop(&stack);
            }
            i++;
        }
        else
        {
            // Ignore other characters
            i++;
        }
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}