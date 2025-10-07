#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Assignment {
    int studentID;
    char title[50];
    char date[15];
    char status[15];
    struct Assignment *next;
};

struct Assignment *head = NULL;

void addSubmission(int id, char title[], char date[], char status[]) {
    struct Assignment *newnode = (struct Assignment*)malloc(sizeof(struct Assignment));
    newnode->studentID = id;
    strcpy(newnode->title, title);
    strcpy(newnode->date, date);
    strcpy(newnode->status, status);
    newnode->next = head;
    head = newnode;
    printf("\nSubmission added!\n");
}

void updateStatus(int id, char title[], char status[]) {
    struct Assignment *temp = head;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->title, title) == 0) {
            strcpy(temp->status, status);
            printf("\nStatus updated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("\nSubmission not found!\n");
}

void searchByStudent(int id) {
    struct Assignment *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->studentID == id) {
            printf("Student %d | %s | %s | %s\n",
                   temp->studentID, temp->title, temp->date, temp->status);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("\nNo submissions found.\n");
}

void displayAll() {
    struct Assignment *temp = head;
    if (temp == NULL) {
        printf("\nNo records.\n");
        return;
    }
    printf("\nAssignment Submissions:\n");
    while (temp != NULL) {
        printf("Student %d | %s | %s | %s\n",
               temp->studentID, temp->title, temp->date, temp->status);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char title[50], date[15], status[15];

    do {
        printf("\n--- Assignment Submission Tracker ---\n");
        printf("1. Add Submission\n");
        printf("2. Update Status\n");
        printf("3. Search by Student ID\n");
        printf("4. Display All\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline buffer

        switch(choice) {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Assignment Title: ");
            scanf(" %s[^\n]", title);   // multiple words allowed
            printf("Enter Submission Date: ");
            scanf("%s", date);
            printf("Enter Status (Submitted/Pending): ");
            scanf(" %s[^\n]", status);
            addSubmission(id, title, date, status);
            break;

        case 2:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Assignment Title: ");
            scanf(" %s[^\n]", title);
            printf("Enter New Status: ");
            scanf(" %s[^\n]", status);
            updateStatus(id, title, status);
            break;

        case 3:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            searchByStudent(id);
            break;

        case 4:
            displayAll();
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
