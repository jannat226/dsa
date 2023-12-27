// main.c
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void cls()
{
    system("cls");
}

// Function to clear the input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void clearScreen()
{
    printf("Press Enter to choose another option...");
    fflush(stdout);

    clearInputBuffer();
    while (getchar() != '\n')
        ;

    system("cls");
}

int main()
{
    int mainChoice, queueChoice;
    char value[50];
    int priority;

    do
    {
        printf("\nMain Menu, Enter your domain name or it's attributes:\n");
        printf("1. Simple Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Priority Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        // scanf("%d", &mainChoice);
        // Check if the input is an integer
        if (scanf("%d", &mainChoice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();

            continue;
        }

        switch (mainChoice)
        {
        case 1:
        {
            cls();
            struct Queue *queue = createQueue();

            do
            {
                printf("\nSimple Queue Menu:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Queue\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                // scanf("%d", &queueChoice);
                if (scanf("%d", &queueChoice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    clearInputBuffer();
                    continue;
                }

                switch (queueChoice)
                {
                case 1:
                    printf("Enter a string to enqueue: ");
                    scanf("%s", value);
                    enqueue(queue, value);
                    printf("Enqueued '%s'\n", value);
                    clearScreen();
                    break;

                case 2:
                    dequeue(queue);
                    clearScreen();
                    break;

                case 3:
                    printf("Current Queue: ");
                    displayQueue(queue);
                    clearScreen();
                    break;

                case 4:
                    freeQueue(queue);
                    printf("Going back to the Main Menu.\n");
                    cls();
                    break;

                default:
                    printf("Invalid choice. Please enter a valid option.\n");
                    clearScreen();
                }

            } while (queueChoice != 4);

            break;
        }

        case 2:
        {
            cls();
            struct CircularQueue *circularQueue = createCircularQueue();

            do
            {
                printf("\nCircular Queue Menu:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Circular Queue\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                // scanf("%d", &queueChoice);
                if (scanf("%d", &queueChoice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    clearInputBuffer();
                    continue;
                }

                switch (queueChoice)
                {
                case 1:
                    printf("Enter a string to enqueue: ");
                    scanf("%s", value);
                    enqueueCircular(circularQueue, value);
                    printf("Enqueued '%s'\n", value);
                    clearScreen();
                    break;

                case 2:
                    dequeueCircular(circularQueue);
                    clearScreen();
                    break;

                case 3:
                    printf("Current Circular Queue: ");
                    displayCircularQueue(circularQueue);
                    clearScreen();
                    break;

                case 4:
                    freeCircularQueue(circularQueue);
                    printf("Going back to the Main Menu.\n");
                    cls();
                    break;

                default:
                    printf("Invalid choice. Please enter a valid option.\n");
                    clearScreen();
                }

            } while (queueChoice != 4);

            break;
        }

        case 3:
        {
            cls();
            struct PriorityQueue *priorityQueue = createPriorityQueue();

            do
            {
                printf("\nPriority Queue Menu:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Priority Queue\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                // scanf("%d", &queueChoice);
                if (scanf("%d", &queueChoice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    clearInputBuffer();
                    continue;
                }

                switch (queueChoice)
                {
                case 1:
                    printf("Enter a string to enqueue: ");
                    scanf("%s", value);
                    printf("Enter priority: ");
                    scanf("%d", &priority);
                    enqueuePriority(priorityQueue, value, priority);
                    printf("Enqueued '%s' with priority %d\n", value, priority);
                    clearScreen();
                    break;

                case 2:
                    dequeuePriority(priorityQueue);
                    clearScreen();
                    break;

                case 3:
                    printf("Current Priority Queue: ");
                    displayPriorityQueue(priorityQueue);
                    clearScreen();
                    break;

                case 4:
                    freePriorityQueue(priorityQueue);
                    printf("Going back to the Main Menu.\n");
                    cls();
                    break;

                default:
                    printf("Invalid choice. Please enter a valid option.\n");
                    clearScreen();
                }

            } while (queueChoice != 4);

            break;
        }

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            clearScreen();
        }

    } while (mainChoice != 4);

    return 0;
}