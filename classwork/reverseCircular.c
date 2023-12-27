#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a new node at the end of the doubly linked list
void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
    }
    else
    {
        struct Node *last = *head_ref;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to reverse a doubly linked list
void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head_ref = temp->prev;
    }
}

// Function to print the doubly linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;

    // Insert elements at the end of the list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Original doubly linked list: ");
    printList(head);

    // Reverse the doubly linked list
    reverse(&head);

    printf("\nReversed doubly linked list: ");
    printList(head);

    return 0;
}
