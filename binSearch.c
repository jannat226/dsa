#include <stdio.h>

int recursion(int e, int l, int h, int *arr)
{
    if (l > h)
    {
        printf("Element not found");
        return -1;
    }

    int mid = (l + h) / 2;

    if (arr[mid] == e)
    {
        return mid;
    }
    else if (arr[mid] > e)
    {
        h = mid - 1;
        return recursion(e, l, h, arr);
    }
    else
    {
        l = mid + 1;
        return recursion(e, l, h, arr);
    }
}

int main()
{
    int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int e;

    printf("Enter the element you want to search in the array: ");
    scanf("%d", &e);

    int result = recursion(e, 0, length - 1, arr);

    if (result != -1)
    {
        printf("The index at which the element is present: %d", result);
    }

    return 0;
}
