// #include <stdio.h>

// #define MAX 20

// char domain_name[MAX];

// int front = -1, rear = -1;

// void enqueue(char element)
// {
//     if (front == -1 && rear == -1)
//     {
//         front = 0;
//         rear = 0;
//         domain_name[rear] = element;
//         printf("\nThe inserted character is: %c", element);
//     }
//     else if ((rear + 1) % MAX == front)
//     {
//         printf("\nQueue is full");
//     }
//     else
//     {
//         rear = (rear + 1) % MAX;
//         domain_name[rear] = element;
//         printf("\nThe inserted element is: %c", element);
//     }
// }

// void dequeue()
// {
//     if (front == -1 && rear == -1)
//     {
//         printf("\nQueue is empty");
//     }
//     else if (front == rear)
//     {
//         printf("\nThe dequeued element is: %c", domain_name[front]);
//         front = -1;
//         rear = -1;
//     }
//     else
//     {
//         printf("The dequeued element is %c", domain_name[front]);
//         front = (front + 1) % MAX;
//     }
// }

// void display()
// {
//     int temp_front = front;
//     printf("\n Queue is: ");
//     while (temp_front != rear)
//     {
//         printf("%c", domain_name[temp_front]);
//         temp_front = (temp_front + 1) % MAX;
//     }
//     printf("\n");
// }

// void main()
// {
//     char buffer[MAX];
//     printf("===Program Start===\n");
//     printf("Enter the Domain Name: ");
//     fflush(stdin);
//     fgets(buffer, MAX - 1, stdin);
//     char *temp = buffer;
//     while (*temp != '\0')
//     {
//         enqueue(*temp);
//         temp++;
//     }
//     display();
//     dequeue();
//     display();
//     printf("===Program END===");
// }