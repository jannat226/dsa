#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Define the PCB structure
typedef struct PCB
{
    int processID;
    char processState[20];
    int priority;
    struct PCB *next;
} PCB;

// Function to create a new PCB node
PCB *createNode(int processID, char processState[], int priority)
{
    PCB *newNode = (PCB *)malloc(sizeof(PCB));
    newNode->processID = processID;
    strcpy(newNode->processState, processState);
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new PCB node into the linked list based on priority
void insertNode(PCB **head, int processID, char processState[], int priority)
{
    PCB *newNode = createNode(processID, processState, priority);
    if (*head == NULL || priority < (*head)->priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        PCB *current = *head;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display all processes with ID, state, and priority
void displayProcesses(PCB *head)
{
    PCB *current = head;
    while (current != NULL)
    {
        printf("Process ID: %d, State: %s, Priority: %d\n", current->processID, current->processState, current->priority);
        current = current->next;
    }
}

// Function to display the process with the highest priority
void displayHighestPriority(PCB *head)
{
    PCB *current = head;
    int highestPriority = 9999;
    while (current != NULL)
    {
        if (current->priority < highestPriority)
        {
            highestPriority = current->priority;
        }
        current = current->next;
    }
    current = head;
    while (current != NULL)
    {
        if (current->priority == highestPriority)
        {
            printf("Process with the highest priority: ID-%d, State-%s, Priority-%d\n", current->processID, current->processState, current->priority);
        }
        current = current->next;
    }
}

// Function to remove processes with state "dead" from the list
void removeDeadProcesses(PCB **head)
{
    while (*head != NULL && strcmp((*head)->processState, "dead") == 0)
    {
        PCB *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    PCB *current = *head;
    while (current != NULL && current->next != NULL)
    {
        if (strcmp(current->next->processState, "dead") == 0)
        {
            PCB *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    PCB *head = NULL;

    // Read details for processes and create the linked structure
    insertNode(&head, 1, "running", 5);
    insertNode(&head, 2, "waiting", 3);
    insertNode(&head, 3, "dead", 7);
    insertNode(&head, 4, "ready", 2);
    insertNode(&head, 5, "running", 1);

    // Display all processes with ID, state, and priority
    printf("All processes:\n");
    displayProcesses(head);

    // Display the process with the highest priority
    displayHighestPriority(head);

    // Remove processes with state "dead" from the list and display the updated list
    removeDeadProcesses(&head);
    printf("Processes after removing 'dead' processes:\n");
    displayProcesses(head);

    return 0;
}