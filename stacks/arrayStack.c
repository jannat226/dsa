#include <stdio.h>

int main()
{
    int choice;
    printf("\n Stack operations , choose from the following options");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\n3. Exit");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        int value;
        printf("Enter a value to insert :");
        scanf("%d", &value);
        push
    }
}
void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("\\n stack is full !!! Insertion is not possible");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\nInsertion success!!")
    }
}
void pop(int value)
{
    if (top == -1)
    {
        printf("\\n stack is full !!! Deletion  is not possible");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\nStack is empty!!");
    }
}
void display()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
}