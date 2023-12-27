#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *dynamicArray;
    int size;
    printf("enter the size of array");
    scanf("%d", &size);
    int sum = 0;
    int a;
    // Allocate ,e,ory for an integer array of size elements
    dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL)
    {
        // check if memory allocation was successful
        printf("Memory allocstion failed\n");
    }
    else
    {
        // memory allocation was successful
        // you can now use dynamicArray to store integers
        for (int i = 0; i < size; i++)
        {
            printf("enter the element of array");
            scanf("%d", &a);
            dynamicArray[i] = a;
        }
        // don't forget to free the allocated memory when done
        for (int i = 0; i < size; i++)
        {
            sum = sum + dynamicArray[i];
        }
        printf("sum of elements is %d \n", sum);
        free(dynamicArray);
    }
    return 0;
}