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

    return newPodcast;
}

// Function to check if a podcast with the given ID already exists
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
    } while (current != head);

    return false; // ID not found
}

// insertPodcast function to insert at the end of the list
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
        newPodcast->next = *head;
    }
    else
    {
        struct Podcast *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newPodcast;
        newPodcast->next = *head;
    }

    printf("Podcast with ID %d inserted successfully.\n", podcastId);
}

// deletePodcast function to delete from the end of the list
void deleteLastPodcast(struct Podcast **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Podcast *current = *head;
    struct Podcast *prev = NULL;

    // Find the last node
    while (current->next != *head)
    {
        prev = current;
        current = current->next;
    }

    // If there is only one element in the list
    if (prev == NULL)
    {
        free(current);
        *head = NULL;
        printf("Only node of the list is deleted.\n");
    }
    else
    {
        prev->next = current->next;

        // If the head is the last node, update the head
        if (*head == current)
        {
            *head = prev->next;
        }

        free(current);
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
        printf("Podcast ID: %d, Podcast Title: %s, Release Date: %s, Duration: %d minutes\n", current->podcastId, current->podcastTitle, current->releaseDate, current->duration);
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
