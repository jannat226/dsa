// queue.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Simple queue functions
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, const char *value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

void dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    printf("Dequeued '%s'\n", temp->data);

    free(temp);
}

void displayQueue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct Queue *queue)
{
    struct Node *current = queue->front;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}

// Circular queue functions
struct CircularQueue *createCircularQueue()
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueueCircular(struct CircularQueue *queue, const char *value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

void dequeueCircular(struct CircularQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    printf("Dequeued '%s'\n", temp->data);
    free(temp);
}

void displayCircularQueue(struct CircularQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Circular Queue is empty.\n");
        return;
    }

    struct Node *current = queue->front;
    do
    {
        printf("%s ", current->data);
        current = current->next;
    } while (current != NULL && current != queue->front);

    printf("\n");
}

void freeCircularQueue(struct CircularQueue *queue)
{
    struct Node *current = queue->front;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}

// Priority queue functions
struct PriorityQueue *createPriorityQueue()
{
    struct PriorityQueue *queue = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueuePriority(struct PriorityQueue *queue, const char *value, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->front == NULL || priority > queue->front->priority)
    {
        newNode->next = queue->front;
        queue->front = newNode;
    }
    else
    {
        struct Node *current = queue->front;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeuePriority(struct PriorityQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    printf("Dequeued '%s'\n", temp->data);
    free(temp);
}

void displayPriorityQueue(struct PriorityQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%s(%d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

void freePriorityQueue(struct PriorityQueue *queue)
{
    struct Node *current = queue->front;
    while (current != NULL)

    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}