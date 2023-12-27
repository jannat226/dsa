#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
            return true; // ID already exists
        }

        current = current->next;

    } while (current != NULL && current != head);

    return false; // ID not found
}

void insertPodcast(struct Podcast **head, int podcastId, const char *podcastTitle, const char *releaseDate, int duration)
{
    // Check for duplicate ID
    while (isDuplicateID(*head, podcastId))
    {
        printf("Podcast with ID %d already exists. Please enter a different ID: ", podcastId);
        scanf("%d", &podcastId);
    }

    // If the ID is not a duplicate, proceed with inserting the podcast
    struct Podcast *newPodcast = createPodcast(podcastId, podcastTitle, releaseDate, duration);

    if (*head == NULL)
    {
        *head = newPodcast;
    }
    else
    {
        newPodcast->next = *head;
        (*head)->prev = newPodcast;
        *head = newPodcast;
    }

    printf("Podcast with ID %d inserted successfully.\n", podcastId);
}

void deletePodcast(struct Podcast **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Podcast *temp = *head;

    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        printf("Only node of the list is deleted.\n");
    }
    else
    {
        *head = temp->next;
        (*head)->prev = NULL;

        free(temp);
        printf("Deleted node from the beginning.\n");
    }
}

struct Podcast *searchPodcast(struct Podcast *head, int podcastId)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Podcast *current = head;

    do
    {
        if (current->podcastId == podcastId)
        {
            return current; // Podcast found
        }

        current = current->next;

    } while (current != NULL && current != head);

    return NULL; // Podcast not found
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
        if (current == NULL)
        {
            printf("Error: Found a NULL node in the list.\n");
            break;
        }

        printf("Podcast ID: %d, Podcast Title: %s, Release Date: %s, Duration: %d minutes\n", current->podcastId, current->podcastTitle, current->releaseDate, current->duration);

        current = current->next;

    } while (current != head && current != NULL);
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
    } while (current != NULL && current != *head);

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
            deletePodcast(&podcastList);
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
