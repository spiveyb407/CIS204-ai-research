#ifndef HELPERS_H
#define HELPERS_H

// Define the Task struct for the linked list
typedef struct Task {
    char description[100];  // Stores the task description (up to 99 characters + null terminator)
    struct Task* next;      // Pointer to the next task in the list
} Task;

// Function prototypes
void addTask(Task** head, char* description);  // Adds a new task to the list (takes pointer to head pointer)
void printTasks(Task* head);                   // Prints all tasks in the list
void deleteTask(Task** head, int index);       // Deletes a task by its position (takes pointer to head pointer, returns void)
Task* createTask(char* description);           // Creates a new task node (returns a pointer to the new Task)
void freeList(Task* head);                     // Frees all memory used by the list
int getMenuChoice();                           // Gets the user's menu choice (returns an integer)

#endif