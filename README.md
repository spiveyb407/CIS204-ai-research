# CIS204-ai-research

## Program Purpose

What will a user use your program to do?
The user will use the program to create, view, and delete tasks in a personal to-do list.

What problem does your program solve?
It helps users keep track of tasks in a simple, text-based list, rather than trying to remember them.

What does the program do?
The program allows the user to add a new task, list all tasks, and remove a task by number. Tasks are stored in a linked list, allowing the list to grow or shrink as needed.

## Input, Output, and Memory Management

User input:

Task descriptions (short strings)

Menu choices (add, view, delete, quit)

Task number to delete

Program output:

List of all tasks

Confirmation messages (“Task added”, “Task deleted”)

Menu options

Variables needed:

A Task struct pointer for the head of the linked list

Temporary strings for user input

Integer variables for menu selection and task numbering

Memory requirements:
Each task dynamically allocates memory for a struct and a string.
Memory usage is small and depends only on the number of tasks.

## Functions Needed
void addTask(Task** head, char* description);
void printTasks(Task* head);
void deleteTask(Task** head, int index);
Task* createTask(char* description);
void freeList(Task* head);
int getMenuChoice();

## Data Structure
typedef struct Task {
    char description[100];
    struct Task* next;
} Task;

## File Responsibilities

main.c

Contains main()

Handles the user menu loop

Calls helper functions (add, delete, print)

Manages program flow

helpers.h

Contains function prototypes

Contains the Task struct definition

Makes functions accessible to main.c and helpers.c

helpers.c

Contains the logic for adding tasks, deleting tasks, printing tasks, and freeing memory

Implements all functions declared in helpers.h

## Research Plan
To complete this project, I will utilize AI as a tool for clarification, debugging assistance, and code generation, while still ensuring that I understand and write the final code myself. My strategy is to use AI to guide me through problems I encounter while implementing the multi-file structure and linked list operations. First, I will ask AI to help me outline the file structure and function prototypes so I can start with a clean, consistent design. Then, as I implement each function, I will utilize AI to explain memory management steps, such as when to allocate memory using malloc and when to free it, to prevent memory leaks. I will also utilize AI to verify that my functions adhere to best practices for handling pointers and dynamic data structures. If I encounter compilation errors, I can paste them into the AI and request help interpreting them. Finally, I will ask the AI to review my completed code and suggest improvements for readability or safety. Throughout the process, I will compare AI-generated examples with my own work to ensure that I understand how everything fits together and can modify the code independently. Prompts I will use include:

1. “Write a C function that adds a node to a linked list.”

2. “Explain how to safely free all nodes in a linked list.”

3. “Show me an example of a simple multi-file C project using .c and .h files.”

4. “Help me debug this C error message:” followed by my compiler output.

5. “Review my code and suggest improvements.”
