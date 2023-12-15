// 6.4. Write a Program to convert an infix expression into its equivalent prefix expression using suitable user defined function.
// Input : a+b
// Output: 
// Enter the infix expression 
// a+b
// Equivalent Postfix Expression is:
// +ab

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
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
void strrev(char str[]);
void infixToPrefix(char infix[], char prefix[]);

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Equivalent Prefix Expression is: %s\n", prefix);

    return 0;
}

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch) {
    switch (ch) {
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

void strrev(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end positions
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    // Reverse the infix expression
    strrev(infix);

    while (infix[i] != '\0') {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix[j++] = infix[i++];
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) > getPrecedence(infix[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            push(&stack, infix[i++]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&stack) && stack.items[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == ')') {
                pop(&stack);
            }
            i++;
        } else {
            // Ignore other characters
            i++;
        }
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    strrev(prefix);
}
