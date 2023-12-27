#include <stdio.h>

int minRotationsToSequence(int arr[], int n)
{
    int ascendingRotations = 0, descendingRotations = 0;

    // Find the number of rotations for ascending order
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ascendingRotations = i;
            break;
        }
    }

    // Find the number of rotations for descending order
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            descendingRotations = i;
            break;
        }
    }

    // Choose the minimum of ascending and descending rotations
    return (ascendingRotations < descendingRotations) ? ascendingRotations : descendingRotations;
}

int main()
{
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Find the minimum number of rotations to make it a sequence
    int minRotations = minRotationsToSequence(arr, n);

    printf("Minimum number of rotations to make it a sequence: %d\n", minRotations);

    return 0;
}
