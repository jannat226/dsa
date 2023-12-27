
/*
    In the construction business, it is common for a certain business to have multiple locations.
    This program models that possibility where multiple locations can have multiple workers
*/

#include <stdio.h>
#include <string.h>

#define LOCATIONS 5
#define WORKERS_PER_LOCATION 4

typedef struct worker
{
    int id;
    char name[30];
    int salary;
} worker;

void display_menu()
{
    printf("\n== Menu ==");
    printf("\nPress 1 to add new Worker");
    printf("\nPress 2 to remove an Worker");
    printf("\nPress 3 to display statistics of All Workers sector wise");
    printf("\nPress 4 to display statistics of All Worker of the company");
    printf("\nPress 5 to exit\n");
    printf(">> ");
}

void display_statistics(worker workers_list[LOCATIONS][WORKERS_PER_LOCATION], int locations_data[LOCATIONS])
{
    int overall_salary = 0;
    int total_workers = 0;
    for (int i = 0; i < LOCATIONS; i++)
    {
        int total_salary = 0;
        total_workers += locations_data[i];
        if (locations_data[i] == 0)
            continue;
        printf("\nLocation: %d\n| id | Employee Name | Total Salary |\n", i + 1);
        for (int j = 0; j < locations_data[i]; j++)
        {
            if (workers_list[i][j].id != -1)
            {
                printf("| %d | %s | %d |\n", workers_list[i][j].id, workers_list[i][j].name, workers_list[i][j].salary);
                total_salary += workers_list[i][j].salary;
            }
        }
        printf("\nTotal Wages for location %d: %d", i + 1, total_salary);
        printf("\nAverage Wage for location %d: %.2f\n", i + 1, ((float)total_salary) / locations_data[i]);
        overall_salary += total_salary;
    }
    printf("\n\nTotal Wages Due: %d", overall_salary);
    printf("\nAverage Salary Overall: %.2f", ((float)overall_salary) / (total_workers));
    printf("\nTotal Workers: %d\n", total_workers);
    return;
}

void display_statistics_overall(worker workers_sector_1[LOCATIONS][WORKERS_PER_LOCATION], worker workers_sector_2[LOCATIONS][WORKERS_PER_LOCATION], int locations_data_1[LOCATIONS], int locations_data_2[LOCATIONS])
{
    int total[LOCATIONS][WORKERS_PER_LOCATION];
    int difference[LOCATIONS][WORKERS_PER_LOCATION];
    printf("\nOverall Statistics\n| Location | Total Salary to be Paid here |\n");
    for (int i = 0; i < LOCATIONS; i++)
    {
        for (int j = 0; j < WORKERS_PER_LOCATION; j++)
        {
            total[i][j] = 0;
            if (j < locations_data_1[i])
            {
                total[i][j] = workers_sector_1[i][j].salary;
            }
            if (j < locations_data_2[i])
            {
                total[i][j] += workers_sector_2[i][j].salary;
            }
            printf("| location %d, worker %d | %d |\n", i + 1, j + 1, total[i][j]);
        }
    }

    printf("\n\n| Location | Difference between Salary of Sectors 1 and 2 |\n");
    for (int i = 0; i < LOCATIONS; i++)
    {
        for (int j = 0; j < WORKERS_PER_LOCATION; j++)
        {
            difference[i][j] = 0;
            if (j < locations_data_1[i])
            {
                difference[i][j] = workers_sector_1[i][j].salary;
            }
            if (j < locations_data_2[i])
            {
                difference[i][j] -= workers_sector_2[i][j].salary;
            }
            printf("| location %d, worker %d | %d |\n", i + 1, j + 1, difference[i][j]);
        }
    }
}

// Setup function to initialize the values for all the workers_list
void setup(worker workers_list[LOCATIONS][WORKERS_PER_LOCATION], int location_data[LOCATIONS])
{
    for (int i = 0; i < LOCATIONS; i++)
    {
        for (int j = 0; j < WORKERS_PER_LOCATION; j++)
        {
            workers_list[i][j].id = -1;
            workers_list[i][j].salary = 0;
            workers_list[i][j].name[0] = '\0';
        }
        location_data[i] = 0;
    }
}

int main(int *argc, char *argv[])
{

    struct worker arr[10];

    worker workers_sector_1[LOCATIONS][WORKERS_PER_LOCATION];
    worker workers_sector_2[LOCATIONS][WORKERS_PER_LOCATION];
    int location_data_sector_1[LOCATIONS];
    int location_data_sector_2[LOCATIONS];

    // setup worker data
    setup(workers_sector_1, location_data_sector_1);
    setup(workers_sector_2, location_data_sector_2);

    while (1)
    {
        int input;
        display_menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            int location, sector;
            printf("Enter the details of the Worker: \n>> Sector (Options: 1,2): ");
            scanf("%d", &sector);
            printf(">> Location (Options: 1,2,3,4): ");
            scanf("%d", &location);
            location--;
            if (sector == 1)
            {
                if (location_data_sector_1[location] == 4)
                {
                    printf("Location is already full.\n");
                    break;
                }
                workers_sector_1[location][location_data_sector_1[location]].id = location * 10 + location_data_sector_1[location];
                fflush(stdin);
                printf(">> Name: ");
                fgets(workers_sector_1[location][location_data_sector_1[location]].name, 30, stdin);
                workers_sector_1[location][location_data_sector_1[location]].name[strcspn(workers_sector_1[location][location_data_sector_1[location]].name, "\n")] = 0;
                printf(">> Salary: ");
                scanf("%d", &workers_sector_1[location][location_data_sector_1[location]].salary);
                location_data_sector_1[location]++;
            }
            else
            {
                if (location_data_sector_2[location] == 4)
                {
                    printf("Location is already full.\n");
                    break;
                }
                workers_sector_2[location][location_data_sector_2[location]].id = location * 10 + location_data_sector_2[location];
                fflush(stdin);
                printf(">> Name: ");
                fgets(workers_sector_2[location][location_data_sector_2[location]].name, 30, stdin);
                workers_sector_2[location][location_data_sector_2[location]].name[strcspn(workers_sector_2[location][location_data_sector_2[location]].name, "\n")] = 0;
                printf(">> Salary: ");
                scanf("%d", &workers_sector_2[location][location_data_sector_2[location]].salary);
                location_data_sector_2[location]++;
            }
            break;
        case 2:
            int id;
            printf("\nEnter the id of the Worker to be deleted: \n>> id: ");
            scanf("%d", &id);
            printf(">>Which Sector: ");
            scanf("%d", &sector);
            if (sector == 1)
                for (int i = 0; i < LOCATIONS; i++)
                    for (int j = 0; j < WORKERS_PER_LOCATION; j++)
                    {
                        if (workers_sector_1[i][j].id == id)
                        {
                            workers_sector_1[i][j].id = workers_sector_1[i, location_data_sector_1[i]]->id;
                            workers_sector_1[i][j].salary = workers_sector_1[i, location_data_sector_1[i]]->salary;
                            strcpy(workers_sector_1[i][j].name, workers_sector_1[i, location_data_sector_1[i]]->name);
                            location_data_sector_1[i]--;
                            printf("Worker Deleted Sucessfully\n");
                            break;
                        }
                    }
            else
            {
                for (int i = 0; i < LOCATIONS; i++)
                    for (int j = 0; j < WORKERS_PER_LOCATION; j++)
                    {
                        if (workers_sector_1[i][j].id == id)
                        {
                            workers_sector_1[i][j].id = workers_sector_1[i, location_data_sector_1[i]]->id;
                            workers_sector_1[i][j].salary = workers_sector_1[i, location_data_sector_1[i]]->salary;
                            strcpy(workers_sector_1[i][j].name, workers_sector_1[i, location_data_sector_1[i]]->name);
                            location_data_sector_1[i]--;
                            printf("Worker Deleted Sucessfully\n");
                            break;
                        }
                    }
            }
            break;

        case 3:
            printf("\nSector 1: \n");
            display_statistics(workers_sector_1, location_data_sector_1);
            printf("\nSector 2: \n");
            display_statistics(workers_sector_2, location_data_sector_2);
            break;

        case 4:
            display_statistics_overall(workers_sector_1, workers_sector_2, location_data_sector_1, location_data_sector_2);
            break;

        case 5:
            return 0;
            break;

        default:
            printf("Invalid Option, Try again\n");
            break;
        }
    }
    return 0;
}