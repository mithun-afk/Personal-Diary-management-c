#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_TEXT 1000

typedef struct {
    char date[11];
    char text[MAX_TEXT];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[entryCount].date);

    printf("Write your diary entry:\n");
    getchar(); // consume newline
    fgets(diary[entryCount].text, MAX_TEXT, stdin);
    diary[entryCount].text[strcspn(diary[entryCount].text, "\n")] = 0;

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].text);
        printf("-------------------------\n");
    }
}

void searchEntry() {
    char date[11];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", date);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].text);
            return;
        }
    }
    printf("No entry found for the given date.\n");
}

void editEntry() {
    char date[11];
    printf("Enter the date of the entry to edit (YYYY-MM-DD): ");
    scanf("%s", date);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Current Entry: %s\n", diary[i].text);
            printf("Enter new entry:\n");
            getchar();
            fgets(diary[i].text, MAX_TEXT, stdin);
            diary[i].text[strcspn(diary[i].text, "\n")] = 0;
            printf("Entry updated successfully!\n");
            return;
        }
    }
    printf("No entry found for the given date.\n");
}

void deleteEntry() {
    char date[11];
    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    scanf("%s", date);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                diary[j] = diary[j + 1];
            }
            entryCount--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("No entry found for the given date.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nDiary Management System\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Edit Entry\n");
        printf("5. Delete Entry\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                editEntry();
                break;
            case 5:
                deleteEntry();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}