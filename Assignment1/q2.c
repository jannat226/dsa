#include <stdio.h>

// Function to read and display an n x n matrix
void readAndDisplayNewMatrix(int *newMatrix, int n)
{
    printf("Enter the %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (newMatrix + i * n + j));
        }
    }

    printf("New Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(newMatrix + i * n + j));
        }
        printf("\n");
    }
}

// Function to calculate the row total of a given matrix
void calculateRowSum(int *newMatrix, int n)
{
    printf("Sum of rows:\n");
    for (int i = 0; i < n; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
        {
            rowSum += *(newMatrix + i * n + j);
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }
}

// Function to check if the given matrix is an identity matrix
int isNewIdentityMatrix(int *newMatrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && *(newMatrix + i * n + j) != 1)
            {
                return 0;
            }
            else if (i != j && *(newMatrix + i * n + j) != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int newMatrix[n][n];

    readAndDisplayNewMatrix((int *)newMatrix, n);
    calculateRowSum((int *)newMatrix, n);

    if (isNewIdentityMatrix((int *)newMatrix, n))
    {
        printf("The new matrix is an identity matrix.\n");
    }
    else
    {
        printf("The new matrix is not an identity matrix.\n");
    }

    return 0;
}
