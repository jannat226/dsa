// #include <stdio.h>

// int minRotationsToSequence(int arr[], int n)
// {
//     int ascendingRotations = 0, descendingRotations = 0;

//     // Find the number of rotations for ascending order
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] < arr[i - 1])
//         {
//             ascendingRotations = i;
//             break;
//         }
//     }

//     // Find the number of rotations for descending order
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > arr[i - 1])
//         {
//             descendingRotations = i;
//             break;
//         }
//     }

//     // Choose the minimum of ascending and descending rotations
//     return (ascendingRotations < descendingRotations) ? ascendingRotations : descendingRotations;
// }
// int mountArray(int arr[], int n)
// {
//     int mid1, mid2;
//     if ((n % 2) + 1 == 0)
//     {
//         mid1 = arr[n / 2];
//         mid2 = arr[(n / 2) - 1];
//     }
//     else
//     {
//         mid1 == arr[(n / 2) + 1];
//         mid2 == arr[(n / 2) + 1];
//     }
//     for (int i = 0; i < n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//         // repeat
//         for (int j = i + 1; j <= n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 printf("Not a mountain array ");
//                 return 0;
//             };
//         }
//         if (mid1 < arr[i] || mid2 < arr[i])
//         {
//             printf("Not a mountain array ");
//             return 0;
//         }
//     }
//     printf("It is a mountain array");

//     return 0;
// }

// int main()
// {
//     int n;

//     // Input the size of the array
//     printf("Enter the size of the array: ");
//     scanf("%d", &n);

//     int arr[n];

//     // Input the elements of the array
//     printf("Enter the elements of the array:\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     mountArray(arr, n);

//     return 0;
// }
#include <stdio.h>

int mountArray(int arr[], int n)
{
    int mid1, mid2;

    if ((n % 2) == 1)
    {
        mid1 = arr[n / 2];
        mid2 = arr[(n / 2) + 1];
    }
    else
    {
        mid1 = arr[n / 2 - 1];
        mid2 = arr[(n / 2)];
    }

    for (int i = 0; i < n - 1; i++)
    {
        // Check for repeated elements
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("Not a mountain array\n");
                return 0;
            }
        }

        // Check for mountain array condition
        if (mid1 < arr[i] && mid2 < arr[i])
        {
            printf("Not a mountain array\n");
            return 0;
        }
    }

    printf("It is a mountain array\n");

    return 0;
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

    mountArray(arr, n);

    return 0;
}
