#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first;
void create(int a[], int n)
{
    struct node *last, *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
};
void Rdisplay(struct node *p)
{
    if (p != 0)
    {
        printf("%d\n", p->data);
        Rdisplay(p->next);
    }
}
void count(struct node *p)
{
    int count = 0;
    while (p != 0)
    {
        count += 1;
        p = p->next;
    }
    printf("number  of the nodes are %d\n", count);
}
void sum(struct node *p)
{
    int data, sum;
    while (p != NULL)
    {
        data = p->data;
        sum += data;
        p = p->next;
    }
    printf("sum  of the values in node is %d\n", sum);
}
void max(struct node *p)
{
    int max = first->data;
    while (p != NULL)
    {
        if (max < p->data)
        {
            max = p->data;
        }

        p = p->next;
    }
    printf("max value inside the node is %d", max);
}
void search(struct node *p, int key)
{
    struct node *q = NULL;
    while (p != 0)
    {
        if (key == p->data)
        {

            q = p;
            // p->next = first;
            // first = p;
            printf("Key found");
        }
        p = p->next;
    }
}
void insert(struct node *p, int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->next = first;
    t->data = n;
    first = t;
    printf("The number is in the linked list \n");
}
int insertPos(struct node *p, int index, int x, int n)
{
    struct node *t;
    if (index < 0 || index > n)
    {
        return;
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}
int main()
{
    int A[] = {1, 2, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    Rdisplay(first);
    count(first);
    sum(first);
    max(first);
    search(first, 2);
    insert(first, 8);
    Rdisplay(first);
    return 0;
}