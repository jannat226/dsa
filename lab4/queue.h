// queue.h
#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    char data[50];
    int priority;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct CircularQueue
{
    struct Node *front;
    struct Node *rear;
};

struct PriorityQueue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue();
void enqueue(struct Queue *queue, const char *value);
void dequeue(struct Queue *queue);
void displayQueue(struct Queue *queue);
void freeQueue(struct Queue *queue);

struct CircularQueue *createCircularQueue();
void enqueueCircular(struct CircularQueue *queue, const char *value);
void dequeueCircular(struct CircularQueue *queue);
void displayCircularQueue(struct CircularQueue *queue);
void freeCircularQueue(struct CircularQueue *queue);

struct PriorityQueue *createPriorityQueue();
void enqueuePriority(struct PriorityQueue *queue, const char *value, int priority);
void dequeuePriority(struct PriorityQueue *queue);
void displayPriorityQueue(struct PriorityQueue *queue);
void freePriorityQueue(struct PriorityQueue *queue);

#endif