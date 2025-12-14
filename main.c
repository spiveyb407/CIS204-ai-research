#include "helpers.h"
#include <stdio.h>  // For input/output functions like printf and scanf

int main() {
    // Declare a pointer to the head of the linked list, initialized to NULL (empty list)
    Task* head = NULL;

    // Declare variables for user input: menu choice, task description, task index to delete
    int choice;
    char description[100];
    int index;

    // Main menu loop: continue until user chooses to quit
    while (1) {
        // Display the menu options to the user
        printf("\nTo-Do List Menu:\n");
        printf("1. Add a task\n");
        printf("2. View all tasks\n");
        printf("3. Delete a task\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        // Get the user's menu choice using getMenuChoice
        choice = getMenuChoice();

        // Use a switch statement based on the choice
        switch (choice) {
            case 1:  // Add a task
                // Prompt the user to enter a task description
                printf("Enter task description: ");
                scanf(" %99[^\n]", description);  // Read up to 99 characters, allowing spaces
                // Call addTask to add the new task to the list
                addTask(&head, description);
                // Print a confirmation message
                printf("Task added.\n");
                break;
            case 2:  // View all tasks
                // Call printTasks to display the list
                printTasks(head);
                break;
            case 3:  // Delete a task
                // Prompt the user to enter the task number to delete
                printf("Enter task number to delete: ");
                scanf("%d", &index);
                // Call deleteTask to remove the task
                deleteTask(&head, index);
                // Print a confirmation message
                printf("Task deleted.\n");
                break;
            case 4:  // Quit the program
                // Call freeList to free all memory
                freeList(head);
                // Exit the loop
                return 0;
            default:  // Invalid choice
                // Print an error message for invalid input
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // Return 0 to indicate successful program execution
    return 0;
}