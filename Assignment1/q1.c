#include <stdio.h>

void inputArray(int *newArr, int n)
{
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &newArr[i]);
    }
}

void displayIntArray(int *newArr, int n)
{
    printf("Numbers in the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", newArr[i]);
    }
    printf("\n");
}

void displayOddPositionedElements(int *newArr, int n)
{
    printf("Odd positioned elements: ");
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            printf("%d ", newArr[i]);
        }
    }
    printf("\n");
}

void displayEvenNumbersFromArray(int *newArr, int n)
{
    printf("Even numbers: ");
    for (int i = 0; i < n; i++)
    {
        if (newArr[i] % 2 == 0)
        {
            printf("%d ", newArr[i]);
        }
    }
    printf("\n");
}

int findMaximum(int *newArr, int n)
{
    int maxVal = newArr[0];
    for (int i = 1; i < n; i++)
    {
        if (newArr[i] > maxVal)
        {
            maxVal = newArr[i];
        }
    }
    return maxVal;
}

void calculateSumAndAverageForArray(int *newArr, int n)
{
    int sumValues = 0;
    for (int i = 0; i < n; i++)
    {
        sumValues += newArr[i];
    }
    float avg = (float)sumValues / n;
    printf("Sum of numbers: %d\n", sumValues);
    printf("Average of numbers: %.2f\n", avg);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int newArr[n];

    inputArray(newArr, n);
    displayIntArray(newArr, n);
    displayOddPositionedElements(newArr, n);
    displayEvenNumbersFromArray(newArr, n);
    int maxVal = findMaximum(newArr, n);
    printf("Maximum number: %d\n", maxVal);
    calculateSumAndAverageForArray(newArr, n);

    return 0;
}
