#include "helpers.h"
#include <stdlib.h>  // For malloc, free, and NULL
#include <stdio.h>   // For printf and scanf
#include <string.h>  // For string functions like strncpy

// Stub for addTask: Adds a new task to the end of the linked list
void addTask(Task** head, char* description) {
    // 1. Create a new Task node using createTask
    Task* newTask = createTask(description);
    // 2. If the list is empty (*head is NULL), set *head to the new node
    if (*head == NULL) {
        *head = newTask;
    } else {
        // 3. Otherwise, traverse to the end of the list and link the new node there
        Task* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTask;
    }
}

// Stub for printTasks: Prints all tasks in the list with numbers
void printTasks(Task* head) {
    // 1. Start from the head of the list
    Task* current = head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s\n", index, current->description);
        current = current->next;
        index++;
    }
    // 2. If the list is empty, print a message indicating no tasks are available
    if (head == NULL) {
        printf("No tasks available.\n");
    }
    // 1. Set a pointer to the head of the list
    // 2. Initialize a counter for task numbering (starting at 1)
    // 3. While the current node is not NULL, print the task number and description
    // 4. Move to the next node in the list
}

// Stub for deleteTask: Removes a task by its position (1-based index)
void deleteTask(Task** head, int index) {
    // 1. Check if the list is empty or index is invalid (less than 1)
    if (*head == NULL || index < 1) {
        printf("Invalid task number.\n");
        return;
    }   
    // 2. If deleting the first task (index == 1), update *head to the next node and free the old head
    if (index == 1) {
        Task* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        // 3. Otherwise, traverse to the node before the one to delete
        Task* current = *head;
        for (int i = 1; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        // 4. Link the previous node to the node after the one to delete
        if (current != NULL && current->next != NULL) {
            Task* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            printf("Invalid task number.\n");
        }
    }
}

// Stub for createTask: Creates a new Task node with the given description
Task* createTask(char* description) {
    // 1. Allocate memory for a new Task struct using malloc
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newTask->description, description, 99);
    newTask->description[99] = '\0'; // Ensure null-termination
    newTask->next = NULL;
    return newTask;

    // 2. Copy the description string into the new node's description field
    strncpy(newTask->description, description, 99);
    newTask->description[99] = '\0'; // Ensure null-termination
    // 3. Set the next pointer to NULL
    newTask->next = NULL;  
    // 4. Return the pointer to the new node
    return newTask;
}

// Stub for freeList: Frees all memory used by the linked list
void freeList(Task* head) {
    // 1. Start from the head of the list
    Task* current = head;
    Task* nextNode;
    while (current != NULL) {
        nextNode = current->next; // Save the next node
        free(current);           // Free the current node
        current = nextNode;      // Move to the next node
    }   
    // 2. While the current node is not NULL, save the next node, free the current node, and move to the next
}

// Stub for getMenuChoice: Displays the menu and gets the user's choice
int getMenuChoice() {
    // 1. Display the menu options (e.g., 1. Add task, 2. View tasks, 3. Delete task, 4. Quit)
    int choice;
    printf("\nTo-Do List Menu:\n");
    printf("1. Add a task\n");
    printf("2. View all tasks\n");
    printf("3. Delete a task\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
    // 2. Read an integer input from the user
    // 3. Return the choice
}