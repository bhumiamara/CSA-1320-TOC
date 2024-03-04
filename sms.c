#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10
#define MAX_LENGTH 100

// Structure to hold messages
typedef struct {
    char message[MAX_LENGTH];
} Message;

// Function prototypes
void displayMenu();
void addMessage(Message messages[], int *messageCount);
void displayMessages(Message messages[], int messageCount);

int main() {
    Message messages[MAX_MESSAGES];
    int messageCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addMessage(messages, &messageCount);
                break;
            case 2:
                displayMessages(messages, messageCount);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\nSMS Based Notice Board\n");
    printf("1. Add Message\n");
    printf("2. Display Messages\n");
    printf("3. Exit\n");
}

// Function to add a message
void addMessage(Message messages[], int *messageCount) {
    if (*messageCount < MAX_MESSAGES) {
        printf("Enter message: ");
        fgets(messages[*messageCount].message, MAX_LENGTH, stdin);
        (*messageCount)++;
        printf("Message added successfully.\n");
    } else {
        printf("Notice board is full. Cannot add more messages.\n");
    }
}

// Function to display messages
void displayMessages(Message messages[], int messageCount) {
    int i; // Variable declaration moved outside the loop
    if (messageCount == 0) {
        printf("No messages to display.\n");
    } else {
        printf("Messages on the Notice Board:\n");
        for (i = 0; i < messageCount; i++) {
            printf("%d. %s", i + 1, messages[i].message);
        }
    }  
}


