// main.c
#include "podcast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void waitForEnter()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;
    getchar();
}

void clearScreen()
{
    system("cls");
}

int main()
{
    int choice;
    struct Episode episodes[100];
    int rows, cols, count;
    int dataInserted = 0;
    while (1)
    {
        clearScreen();
        printf("Podcast Management System\n");
        printf("1. Add Episodes\n");
        printf("2. Delete Episode\n");
        printf("3. Search an Episode\n");
        printf("4. Display Episode List\n");
        printf("5. Total Contribution\n");
        printf("6. Average Contribution\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
                // Clear the input buffer.
            }
            printf("Invalid choice. Please try again.\n");
            waitForEnter();
            continue;
        }

        switch (choice)
        {
        case 1:
            count = insertEpisode(episodes, &rows, &cols);
            dataInserted = 1;
            waitForEnter();
            break;
        case 2:
            deleteEpisode(episodes, &count);
            waitForEnter();
            break;
        case 3:
            if (dataInserted)
            {
                char targetName[50];
                printf("Enter the name of the episode to search: ");
                scanf("%49s", targetName);
                int searchResult = linearSearch(episodes, count, targetName);
                if (searchResult != -1)
                {
                    printf("Episode found at index %d.\n", searchResult);
                }
                else
                {
                    printf("Episode not found.\n");
                }
            }
            else
            {
                printf("Please insert data before performing linear search.\n");
            }
            waitForEnter();
            break;
        case 4:
            displayEpisodes(episodes, count);
            waitForEnter();
            break;
        case 5:
            if (dataInserted)
            {
                totalContribution();
            }
            else
            {
                printf("Please insert data before performing total contribution calculation.\n");
            }
            waitForEnter();
            break;
        case 6:
            if (dataInserted)
            {
                averageContribution();
            }
            else
            {
                printf("Please insert data before performing average contribution calculation.\n");
            }
            waitForEnter();
            break;
        case 7:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            waitForEnter();
        }
    }

    return 0;
}
