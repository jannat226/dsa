
#include <stdio.h>
#include <stdlib.h>

// Node structure for priority queue
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

// Function prototypes
void enqueue(int item);
void dequeue();
void display();
void enqueuePriority(int item, int priority);

// Global variables
typedef struct
{
    int choice;
    Node *front;
    Node *rear;
} Queue;

Queue *queue;

// Function to create a new node for priority queue
Node *createNode(int item, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Memory allocation error.\n");
        return EXIT_FAILURE;
    }
    queue->front = NULL;
    queue->rear = NULL;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Regular Queue\n");
        printf("2. Priority Queue\n");
        printf("3. Exit\n");

        printf("Enter your choice (1/2/3): ");
        scanf("%d", &queue->choice);

        // Consume the newline character from the input buffer
        getchar();

        switch (queue->choice)
        {
        case 1:
            printf("Regular Queue selected.\n");
            break;
        case 2:
            printf("Priority Queue selected.\n");
            break;
        case 3:
            printf("Exiting program.\n");
            free(queue);
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }

        while (1)
        {
            printf("\nQueue Operations:\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Back to Main Menu\n");

            printf("Enter operation (1/2/3/4): ");
            int operation;
            scanf("%d", &operation);

            // Consume the newline character from the input buffer
            getchar();

            switch (operation)
            {
            case 1:
                if (queue->choice == 1)
                {
                    int item;
                    printf("Enter element to enqueue: ");
                    scanf("%d", &item);
                    enqueue(item);
                }
                else if (queue->choice == 2)
                {
                    int item, priority;
                    printf("Enter element to enqueue: ");
                    scanf("%d", &item);
                    printf("Enter priority: ");
                    scanf("%d", &priority);
                    enqueuePriority(item, priority);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Returning to Main Menu.\n");
                break;
            default:
                printf("Invalid operation. Please enter a valid option.\n");
            }

            if (operation == 4)
            {
                break;
            }
        }
    }

    free(queue);

    return 0;
}

// Function to enqueue an element in a regular queue
void enqueue(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued successfully.\n", item);
}

// Function to enqueue an element with priority in a priority queue
void enqueuePriority(int item, int priority)
{
    Node *newNode = createNode(item, priority);

    if (queue->front == NULL || priority < queue->front->priority)
    {
        newNode->next = queue->front;
        queue->front = newNode;
    }
    else
    {
        Node *current = queue->front;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("%d enqueued successfully with priority %d.\n", item, priority);
}

// Function to dequeue an element from the queue
void dequeue()
{
    if (queue->front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    Node *temp = queue->front;
    int item = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    printf("%d dequeued successfully.\n", item);
}

// Function to display the elements of the queue
void display()
{
    if (queue->front == NULL)
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }

    printf("Queue elements:\n");
    Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
