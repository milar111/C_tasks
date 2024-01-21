#include "processes.h"
#include <stdio.h>

void printProcesses() {
    printf("Processes:\n");
    for (int i = 0; i < processesCount; ++i) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    int option;
    char processName[MAX_NAME_LENGTH];
    int processId;

    do {
        printf("\nOptions:\n1. Create Process\n2. List Processes\n3. Stop Process\n4. Exit\nChoose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", processName);
                int newProcessId = createNewProcess(processName);
                if (newProcessId != 0) {
                    printf("Process created successfully. ID: %d\n", newProcessId);
                } else {
                    printf("Error: Maximum number of processes reached.\n");
                }
                break;
            case 2:
                printProcesses();
                break;
            case 3:
                printf("Enter process ID to stop: ");
                scanf("%d", &processId);
                stopProcess(processId);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    } while (option != 4);

    return 0;
}
