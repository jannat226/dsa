// podcast.c
#include "podcast.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Episode mergedArray[100][50];
int mat_rows, mat_cols;

int insertEpisode(struct Episode episodes[], int *outRows, int *outCols)
{
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    struct Episode array1[50][50];
    struct Episode array2[50][50];

    printf("\nEnter Episode information for Array 1:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            struct Episode *episodePtr = &array1[i][j];

            printf("\nEnter Episode Id for element at Array 1 [%d][%d]: ", i, j);
            scanf("%d", &episodePtr->episodeID);

            printf("Enter Episode name for element at Array 1 [%d][%d]: ", i, j);
            scanf("%49s", episodePtr->name);

            printf("Enter Host name for element at Array 1 [%d][%d]: ", i, j);
            scanf("%49s", episodePtr->host);

            printf("Enter Status for element at Array 1 [%d][%d]: ", i, j);
            scanf("%19s", episodePtr->status);

            printf("Enter Total Contribution for element at Array 1 [%d][%d]: ", i, j);
            scanf("%d", &episodePtr->totalContribution);
        }
    }

    printf("\nEnter Episode information for Array 2:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            struct Episode *episodePtr = &array2[i][j];

            printf("\nEnter Episode Id for element at Array 2 [%d][%d]: ", i, j);
            scanf("%d", &episodePtr->episodeID);

            printf("Enter Episode name for element at Array 2 [%d][%d]: ", i, j);
            scanf("%49s", episodePtr->name);

            printf("Enter Host name for element at Array 2 [%d][%d]: ", i, j);
            scanf("%49s", episodePtr->host);

            printf("Enter Status for element at Array 2 [%d][%d]: ", i, j);
            scanf("%19s", episodePtr->status);

            printf("Enter Total Contribution for element at Array 2 [%d][%d]: ", i, j);
            scanf("%d", &episodePtr->totalContribution);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mergedArray[i][j] = array1[i][j];
            mergedArray[i + rows][j] = array2[i][j];
        }
    }

    printf("\nMerged Array (Vertical):\n\n");
    for (int i = 0; i < 2 * rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            struct Episode *episodePtr = &mergedArray[i][j];
            printf("Element at [%d][%d]: Episode Id: %d, Name: %s, Host: %s, Status: %s, Total Contribution: $%d\n", i, j, episodePtr->episodeID, episodePtr->name, episodePtr->host, episodePtr->status, episodePtr->totalContribution);
        }
    }

    for (int i = 0; i < 2 * rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            episodes[i * cols + j] = mergedArray[i][j];
        }
    }

    mat_rows = rows;
    mat_cols = cols;

    *outRows = 2 * rows;
    *outCols = cols;

    int count = 2 * rows * cols;

    return count;
}

void deleteEpisode(struct Episode episodes[], int *count)
{
    int episodeID;
    printf("Enter the Episode ID to delete: ");
    scanf("%d", &episodeID);

    int found = 0;
    for (int i = 0; i < *count; i++)
    {
        if (episodes[i].episodeID == episodeID)
        {
            found = 1;
            for (int j = i; j < *count - 1; j++)
            {
                episodes[j] = episodes[j + 1];
            }
            (*count)--;
            printf("Episode with Episode ID %d has been deleted.\n", episodeID);
            break;
        }
    }

    if (!found)
    {
        printf("Episode with Episode ID %d was not found.\n", episodeID);
    }

    printf("Updated Episodes Array:\n");
    for (int i = 0; i < *count; i++)
    {
        printf("Episode ID: %d\n", episodes[i].episodeID);
    }
}

void displayEpisodes(const struct Episode episodes[], int count)
{
    if (count == 0)
    {
        printf("No episodes to display. The list is empty.\n");
        return;
    }

    printf("Displaying Episode Data:\n");
    for (int i = 0; i < count; i++)
    {
        const struct Episode *episodePtr = &episodes[i];
        printf("Episode ID: %d, Name: %s, Host: %s, Status: %s, Total Contribution: $%d\n",
               episodePtr->episodeID, episodePtr->name, episodePtr->host, episodePtr->status, episodePtr->totalContribution);
    }
}

int linearSearch(const struct Episode episodes[], int count, const char *targetName)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(episodes[i].name, targetName) == 0)
        {
            return i;
        }
    }
    return -1;
}

void totalContribution()
{
    int total = 0;

    for (int i = 0; i < mat_rows; i++)
    {
        for (int j = 0; j < mat_cols; j++)
        {
            total += mergedArray[i][j].totalContribution;
        }
    }

    printf("\nTotal Contribution: $%d\n", total);
}

void averageContribution()
{
    int total = 0;

    for (int i = 0; i < mat_rows; i++)
    {
        for (int j = 0; j < mat_cols; j++)
        {
            total += mergedArray[i][j].totalContribution;
        }
    }

    float average = (float)total / (mat_rows * mat_cols);

    printf("\nAverage Contribution: $%.2f\n", average);
}
