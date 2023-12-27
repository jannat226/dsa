#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first;
void create(int arr[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    struct node *last, *t;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    display(first);
    return 0;
}