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

bool isDuplicateID(struct Podcast *head, int podcastId)
{
    struct Podcast *current = head;

    while (current != NULL)
    {
        if (current->podcastId == podcastId)
        {
            return true; // ID already exists
        }

        current = current->next;
    }

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

    struct Podcast *newPodcast = createPodcast(podcastId, podcastTitle, releaseDate, duration);

    if (*head == NULL || (*head)->podcastId >= podcastId)
    {
        // Insert at the beginning or before the head
        newPodcast->next = *head;
        *head = newPodcast;
    }
    else
    {
        struct Podcast *prev = NULL;
        struct Podcast *current = *head;

        while (current != NULL && current->podcastId < podcastId)
        {
            prev = current;
            current = current->next;
        }

        newPodcast->next = prev->next;
        prev->next = newPodcast;
    }

    printf("Podcast with ID %d inserted successfully.\n", podcastId);
}

void deletePodcastFromMiddle(struct Podcast **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Podcast *middlePrev = NULL; // Pointer to the node before the middle
    struct Podcast *middle = *head;    // Pointer to the middle node
    struct Podcast *nextNode = *head;  // Pointer for faster traversal

    while (nextNode != NULL && nextNode->next != NULL)
    {
        middlePrev = middle;
        middle = middle->next;
        nextNode = nextNode->next->next;
    }

    if (middlePrev == NULL)
    {
        // Deleting the first node (middle in this case)
        *head = middle->next;
    }
    else
    {
        middlePrev->next = middle->next;
    }

    printf("Podcast with ID %d deleted successfully from the middle.\n", middle->podcastId);
    free(middle);
}

struct Podcast *searchPodcast(struct Podcast *head, int podcastId)
{
    struct Podcast *current = head;

    while (current != NULL)
    {
        if (current->podcastId == podcastId)
        {
            return current; // Podcast found
        }

        current = current->next;
    }

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

    while (current != NULL)
    {
        printf("Podcast ID: %d, Title: %s, Release Date: %s, Duration: %d minutes\n", current->podcastId, current->podcastTitle, current->releaseDate, current->duration);
        current = current->next;
    }
}

void freePodcastList(struct Podcast **head)
{
    struct Podcast *current = *head;
    struct Podcast *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

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
            printf("Enter Duration (minutes): ");
            scanf("%d", &duration);
            insertPodcast(&podcastList, podcastId, podcastTitle, releaseDate, duration);
            break;

        case 2:
            deletePodcastFromMiddle(&podcastList);
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
