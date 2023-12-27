#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 100
#define MAX_PERSON_NAME_LENGTH 50

// Function to read n names into an array
void readPersonNames(char personNames[][MAX_PERSON_NAME_LENGTH], int n)
{
    printf("Enter %d person names:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", personNames[i]);
    }
}

// Function to display n names from an array
void displayPersonNames(char personNames[][MAX_PERSON_NAME_LENGTH], int n)
{
    printf("Names entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", personNames[i]);
    }
}

// Function to perform bubble sort on an array of names
void bubbleSortPersonNames(char personNames[][MAX_PERSON_NAME_LENGTH], int n)
{
    int exchanged;
    char tempName[MAX_PERSON_NAME_LENGTH];

    for (int i = 0; i < n - 1; i++)
    {
        exchanged = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(personNames[j], personNames[j + 1]) > 0)
            {
                strcpy(tempName, personNames[j]);
                strcpy(personNames[j], personNames[j + 1]);
                strcpy(personNames[j + 1], tempName);
                exchanged = 1;
            }
        }

        if (exchanged == 0)
        {
            // If no two elements were swapped in the inner loop, the array is already sorted.
            break;
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PERSONS)
    {
        printf("Invalid number of persons.\n");
        return 1;
    }

    char personNames[MAX_PERSONS][MAX_PERSON_NAME_LENGTH];
    readPersonNames(personNames, n);

    displayPersonNames(personNames, n);

    bubbleSortPersonNames(personNames, n);

    printf("Sorted person names:\n");
    displayPersonNames(personNames, n);

    return 0;
}
