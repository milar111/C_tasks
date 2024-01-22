#include "processes.h"
#include <stdio.h>

int main() {
    int choice, processid;
    char processname[30];

    while (1) {
        printf("1. Create new process\n2. List all processes\n3. Stop process\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter process name: ");
            scanf("%s", processname);
            int id = createnewprocess(processname);
            if (id != 0) {
                printf("Created process with ID %d\n", id);
            } else {
                printf("Error: Maximum number of processes reached.\n");
            }
        } else if (choice == 2) {
            printf("Processes:\n");
            for (int i = 0; i < processescount; ++i) {
                printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
            }
        } else if (choice == 3) {
            printf("Enter process ID to stop: ");
            scanf("%d", &processid);
            stopprocess(processid);
        } else{
            printf("Exiting taskmanager.\n");
            return 0;
        }
    }

    return 0;
}
