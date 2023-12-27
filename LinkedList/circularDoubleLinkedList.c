#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../../../../Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/stdbool.h"

struct Podcast
{
    int podcastId;
    char podcastTitle[50];
    char releaseDate[20];
    int duration;
    struct Podcast *next;
    struct Podcast *prev;
};

struct Podcast *createPodcast(int podcastId, const char *podcastTitle, const char *releaseDate, int duration)
{
    struct Podcast *newPodcast = (struct Podcast *)malloc(sizeof(struct Podcast));
    if (newPodcast == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newPodcast->podcastId = podcastId;
    strncpy(newPodcast->podcastTitle, podcastTitle, sizeof(newPodcast->podcastTitle));
    strncpy(newPodcast->releaseDate, releaseDate, sizeof(newPodcast->releaseDate));
    newPodcast->duration = duration;
    newPodcast->next = NULL;
    newPodcast->prev = NULL;

    return newPodcast;
}

bool isDuplicateID(struct Podcast *head, int podcastId)
{
    if (head == NULL)
    {
        return false;
    }

    struct Podcast *current = head;

    do
    {
        if (current->podcastId == podcastId)
        {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}

void insertPodcast(struct Podcast **head, int podcastId, const char *podcastTitle, const char *releaseDate, int duration)
{
    while (isDuplicateID(*head, podcastId))
    {
        printf("Podcast with ID %d already exists. Please enter a different ID: ", podcastId);
        scanf("%d", &podcastId);
    }

    struct Podcast *newPodcast = createPodcast(podcastId, podcastTitle, releaseDate, duration);

    if (*head == NULL)
    {
        *head = newPodcast;
        newPodcast->next = *head;
        newPodcast->prev = *head;
    }
    else
    {
        struct Podcast *current = (*head)->prev;

        current->next = newPodcast;
        newPodcast->prev = current;
        newPodcast->next = *head;
        (*head)->prev = newPodcast;
    }

    printf("Podcast with ID %d inserted successfully.\n", podcastId);
}

void deleteLastPodcast(struct Podcast **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Podcast *last = (*head)->prev;

    if (*head == last)
    {
        free(last);
        *head = NULL;
        printf("Only node of the list is deleted.\n");
    }
    else
    {
        struct Podcast *prev = last->prev;

        prev->next = *head;
        (*head)->prev = prev;

        free(last);
        printf("Deleted node from the last.\n");
    }
}

struct Podcast *searchPodcast(struct Podcast *head, int podcastId)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Podcast *current = head;
    int found = 0;

    do
    {
        if (current->podcastId == podcastId)
        {
            found = 1;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

void displayPodcasts(struct Podcast *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Podcast *current = head;

    do
    {
        printf("Podcast ID: %d, Title: %s, Release Date: %s, Duration: %d minutes\n", current->podcastId, current->podcastTitle, current->releaseDate, current->duration);
        current = current->next;
    } while (current != head);
}

void freePodcastList(struct Podcast **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Podcast *current = *head;
    struct Podcast *temp;

    do
    {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *head);

    *head = NULL;
}
int main()
{
    struct Podcast *podcastList = NULL;
    int choice, podcastId;
    char podcastTitle[50];
    char releaseDate[20];
    int duration;

    do
    {
        printf("\nPodcast Management System\n");
        printf("\n1. Insert Podcast\n2. Delete Podcast\n3. Search Podcast\n4. Display Podcasts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Podcast ID: ");
            scanf("%d", &podcastId);
            printf("Enter Podcast Title: ");
            scanf("%s", podcastTitle);
            printf("Enter Release Date: ");
            scanf("%s", releaseDate);
            printf("Enter Duration (in minutes): ");
            scanf("%d", &duration);
            insertPodcast(&podcastList, podcastId, podcastTitle, releaseDate, duration);
            break;

        case 2:
            deleteLastPodcast(&podcastList);
            break;

        case 3:
            printf("Enter Podcast ID to search: ");
            scanf("%d", &podcastId);
            struct Podcast *foundPodcast = searchPodcast(podcastList, podcastId);
            if (foundPodcast != NULL)
            {
                printf("Podcast with ID %d found: %s, Release Date: %s, Duration: %d minutes\n", podcastId, foundPodcast->podcastTitle, foundPodcast->releaseDate, foundPodcast->duration);
            }
            else
            {
                printf("Podcast with ID %d not found.\n", podcastId);
            }
            break;

        case 4:
            displayPodcasts(podcastList);
            break;

        case 5:
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free memory
    freePodcastList(&podcastList);

    return 0;
}
