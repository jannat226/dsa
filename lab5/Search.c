#include <stdio.h>

long linearSearchInt(long array[], long n, long search, long *element_comparisons, long *index_comparisons)
{
    *element_comparisons = 0;
    *index_comparisons = 0;

    for (long c = 0; c < n; c++)
    {
        (*element_comparisons)++;
        if (array[c] == search)
        {
            (*index_comparisons)++;
            return c;
        }
        (*index_comparisons)++;
    }
    (*index_comparisons)++;

    return -1;
}

long linearSearchChar(char array[], long n, char search, long *element_comparisons, long *index_comparisons)
{
    *element_comparisons = 0;
    *index_comparisons = 0;

    for (long c = 0; c < n; c++)
    {
        (*element_comparisons)++;
        if (array[c] == search)
        {
            (*index_comparisons)++;
            return c;
        }
        (*index_comparisons)++;
    }
    (*index_comparisons)++;
    return -1;
}

int binarySearchInt(int array[], int x, int low, int high, int *element_comparisons, int *index_comparisons)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        (*index_comparisons)++;

        if (array[mid] == x)
        {
            (*element_comparisons)++;
            return mid;
        }

        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;

        (*element_comparisons)++;
    }

    return -1;
}

int binarySearchChar(char array[], char x, int low, int high, int *element_comparisons, int *index_comparisons)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        (*index_comparisons)++;

        if (array[mid] == x)
        {
            (*element_comparisons)++;
            return mid;
        }

        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;

        (*element_comparisons)++;
    }

    return -1;
}

// Function to perform sentinel search for integers
int sentinelSearchInt(int arr[], int n, int key, int *element_comparisons, int *index_comparisons)
{
    // Store the last element of the array
    int last = arr[n - 1];
    // Set the last element as the sentinel
    arr[n - 1] = key;

    int i = 0;
    *element_comparisons = 0;
    *index_comparisons = 0;

    while (arr[i] != key)
    {
        (*element_comparisons)++;
        i++;
    }

    (*index_comparisons)++;

    // Restore the original last element
    arr[n - 1] = last;
    // If the index is less than n-1, the key is found
    if (i < n - 1)
    {
        return i;
    }

    // If the index is equal to n-1, the key is not found
    if (arr[n - 1] == key)
    {
        return n - 1;
    }
    // If the index is greater than n-1, the key is not in the array
    return -1;
}

// Function to perform sentinel search for characters
int sentinelSearchChar(char arr[], int n, char key, int *element_comparisons, int *index_comparisons)
{
    // Store the last element of the array
    char last = arr[n - 1];
    // Set the last element as the sentinel
    arr[n - 1] = key;

    int i = 0;
    *element_comparisons = 0;
    *index_comparisons = 0;

    while (arr[i] != key)
    {
        (*element_comparisons)++;
        i++;
    }

    (*index_comparisons)++;
    // Restore the original last element
    arr[n - 1] = last;
    // If the index is less than n-1, the key is found
    if (i < n - 1)
    {
        return i;
    }
    // If the index is equal to n-1, the key is not found
    if (arr[n - 1] == key)
    {
        return n - 1;
    }
    // If the index is greater than n-1, the key is not in the array
    return -1;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int *comparisons, int *data_transfers)
{
    *comparisons = 0;
    *data_transfers = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            (*comparisons)++;
            if (arr[j] > arr[j + 1])
            {
                // Swap if the current element is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*data_transfers) += 3; // Increment data transfers for the swap
            }
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n, int *comparisons, int *data_transfers)
{
    *comparisons = 0;
    *data_transfers = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            (*data_transfers)++; // Increment data transfers for shifting
            j--;
        }

        arr[j + 1] = key;
        (*data_transfers)++; // Increment data transfers for the insertion
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSortChar(char arr[], int n, int *comparisons, int *data_transfers)
{
    *comparisons = 0;
    *data_transfers = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            (*comparisons)++;
            if (arr[j] > arr[j + 1])
            {
                // Swap if the current element is greater than the next element
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*data_transfers) += 3; // Increment data transfers for the swap
            }
        }
    }
}

void insertionSortChar(char arr[], int n, int *comparisons, int *data_transfers)
{
    *comparisons = 0;
    *data_transfers = 0;

    for (int i = 1; i < n; i++)
    {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            (*data_transfers)++; // Increment data transfers for shifting
            j--;
        }

        arr[j + 1] = key;
        (*data_transfers)++; // Increment data transfers for the insertion
    }
}

void printCharArray(char arr[], int n)
{
    printf("Sorted Character Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nSearch Algorithm Menu:\n");
        printf("1. Binary Search\n");
        printf("2. Linear Search\n");
        printf("3. Sentinel Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n, choice, target_int, element_comparisons_int = 0, index_comparisons_int = 0;
            int comparisons, data_transfers;
            char target_char;
            int array_int[100];
            char array_char[100];

            printf("\nChoose data type:\n");
            printf("1. Integer\n");
            printf("2. Character\n");
            scanf("%d", &choice);

            printf("Input number of elements in array\n");
            scanf("%d", &n);

            if (choice == 1)
            {
                printf("Input %d integers\n", n);
                for (int c = 0; c < n; c++)
                    scanf("%d", &array_int[c]);

                // Submenu for sorting algorithm
                printf("\nChoose sorting algorithm:\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    bubbleSort(array_int, n, &comparisons, &data_transfers);
                    printf("\nBubble Sort:\n");
                    printArray(array_int, n);
                    printf("Total Comparisons: %d\n", comparisons);
                    printf("Total Data Transfers: %d\n", data_transfers);
                    break;
                case 2:
                    insertionSort(array_int, n, &comparisons, &data_transfers);
                    printf("Insertion Sort:\n");
                    printArray(array_int, n);
                    printf("Total Comparisons: %d\n", comparisons);
                    printf("Total Data Transfers: %d\n", data_transfers);
                    break;
                default:
                    printf("Invalid sorting algorithm choice\n");
                    return 1;
                }

                printf("\nInput an integer to search\n");
                scanf("%d", &target_int);

                int result_int = binarySearchInt(array_int, target_int, 0, n - 1, &element_comparisons_int, &index_comparisons_int);

                if (result_int == -1)
                    printf("Integer not found\n");
                else
                    printf("Integer found at index %d\n", result_int + 1);

                printf("Element comparisons: %d\n", element_comparisons_int);
                printf("Index comparisons: %d\n", index_comparisons_int);
            }
            else if (choice == 2)
            {
                printf("Input %d characters\n", n);
                for (int c = 0; c < n; c++)
                    scanf(" %c", &array_char[c]);

                // Submenu for sorting algorithm
                printf("\nChoose sorting algorithm:\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    bubbleSortChar(array_char, n, &comparisons, &data_transfers);
                    printf("\nBubble Sort:\n");
                    printCharArray(array_char, n);
                    printf("Total Comparisons: %d\n", comparisons);
                    printf("Total Data Transfers: %d\n", data_transfers);
                    break;
                case 2:
                    insertionSortChar(array_char, n, &comparisons, &data_transfers);
                    printf("Insertion Sort:\n");
                    printCharArray(array_char, n);
                    printf("Total Comparisons: %d\n", comparisons);
                    printf("Total Data Transfers: %d\n", data_transfers);
                    break;
                default:
                    printf("Invalid sorting algorithm choice\n");
                    return 1;
                }

                printf("Input a character to search\n");
                scanf(" %c", &target_char);

                int result_char = binarySearchChar(array_char, target_char, 0, n - 1, &element_comparisons_int, &index_comparisons_int);

                if (result_char == -1)
                    printf("Character not found\n");
                else
                    printf("Character found at index %d\n", result_char + 1);

                printf("Element comparisons: %d\n", element_comparisons_int);
                printf("Index comparisons: %d\n", index_comparisons_int);
            }
            else
            {
                printf("Invalid choice\n");
                return 1;
            }
            break;
        }
        case 2:
        {
            long n, choice, position, element_comparisons, index_comparisons;
            long array_int[100];
            char array_char[100];
            long search_int;
            char search_char;

            printf("\nChoose data type:\n");
            printf("1. Integer\n");
            printf("2. Character\n");
            scanf("%ld", &choice);

            printf("Input number of elements in array\n");
            scanf("%ld", &n);

            if (choice == 1)
            {
                printf("Input %ld integers\n", n);
                for (long c = 0; c < n; c++)
                    scanf("%ld", &array_int[c]);

                printf("Input an integer to search\n");
                scanf("%ld", &search_int);

                position = linearSearchInt(array_int, n, search_int, &element_comparisons, &index_comparisons);

                if (position == -1)
                    printf("%ld isn't present in the array.\n", search_int);
                else
                    printf("%ld is present at location %ld.\n", search_int, position + 1);
            }
            else if (choice == 2)
            {
                printf("Input %ld characters\n", n);
                for (long c = 0; c < n; c++)
                    scanf(" %c", &array_char[c]);

                printf("Input a character to search\n");
                scanf(" %c", &search_char);

                position = linearSearchChar(array_char, n, search_char, &element_comparisons, &index_comparisons);

                if (position == -1)
                    printf("%c isn't present in the array.\n", search_char);
                else
                    printf("%c is present at location %ld.\n", search_char, position + 1);
            }
            else
            {
                printf("Invalid choice\n");
                return 1;
            }

            printf("Element comparisons: %ld\n", element_comparisons);
            printf("Index comparisons: %ld\n", index_comparisons);
            break;
        }
        case 3:
        {
            int n, choice, element_comparisons, index_comparisons;

            printf("\nChoose data type:\n");
            printf("1. Integer\n");
            printf("2. Character\n");
            scanf("%d", &choice);

            printf("Enter the size of the array: ");
            scanf("%d", &n);

            if (choice == 1)
            {
                int arr[n];

                printf("Enter %d integers for the array:\n", n);
                for (int i = 0; i < n; i++)
                {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }

                int key;

                printf("Enter the key to search for: ");
                scanf("%d", &key);

                int result = sentinelSearchInt(arr, n, key, &element_comparisons, &index_comparisons);

                if (result != -1)
                {
                    printf("Element found at index %d\n", result);
                }
                else
                {
                    printf("Element not found in the array\n");
                }
            }
            else if (choice == 2)
            {
                char arr[n];

                printf("Enter %d characters for the array:\n", n);
                for (int i = 0; i < n; i++)
                {
                    printf("Element %d: ", i + 1);
                    scanf(" %c", &arr[i]);
                }

                char key;

                printf("Enter the key to search for: ");
                scanf(" %c", &key);

                int result = sentinelSearchChar(arr, n, key, &element_comparisons, &index_comparisons);

                if (result != -1)
                {
                    printf("Element found at index %d\n", result);
                }
                else
                {
                    printf("Element not found in the array\n");
                }
            }
            else
            {
                printf("Invalid choice\n");
                return 1;
            }

            printf("Element comparisons: %d\n", element_comparisons + 1);
            printf("Index comparisons: %d\n", index_comparisons);
            break;
        }
        case 4:
        {
            printf("Exiting the program. Goodbye!\n");
            return 0;
        }
        default:
        {
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
        }

    } while (choice != 4);

    return 0;
}
