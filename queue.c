
#include <stdio.h>

void enqueue(int element)
{
    int front, rear, max;
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is overflow");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}
int main()
{
    int choice;
    printf("Circular Queue Program \n");
    printf("1. Insert in Circular Queue \n");
    printf("2. Delete an element from Circular Queue \n");
    printf("Enter an option: \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        int ele;
        printf("Enter an element value");
        scanf("%d", &ele);
        break;
    case 2:
    default:
        break;
    }
    return 0;
}