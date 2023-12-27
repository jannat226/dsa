#include <stdio.h>
// #include <stdlib.h>
#include "stack.h"
#include <string.h>

// Function to check if a character is an operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z' || (ch >= '0' && ch <= '9'));
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix)
{
    struct Stack *stack = createStack(strlen(infix));
    int i, j;

    for (i = 0, j = -1; infix[i]; ++i)
    {
        if (isOperand(infix[i]))
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && check(stack) != '(')
            {
                printf("%c", pop(stack));
            }
            pop(stack); // Pop '('
        }
        else
        { // Operator
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(check(stack)))
            {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        }
    }

    // Pop the remaining operators from the stack
    while (!isEmpty(stack))
    {
        printf("%c", pop(stack));
    }
}

int main()
{
    char infix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix and print the result
    printf("Postfix expression: ");
    infixToPostfix(infix);

    return 0;
}