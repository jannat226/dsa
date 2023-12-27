#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

char check(struct Stack *stack)
{
    return stack->array[stack->top];
}