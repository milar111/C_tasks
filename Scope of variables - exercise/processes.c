#include "processes.h"
#include <stdio.h>

int nextProcessId() {
    static int currentId = 1; 
    if (currentId <= MAX_PROCESSES) {
        return currentId++;
    }
    return 0;
}

int createNewProcess(const char *processName) {
    if (processesCount < MAX_PROCESSES) {
        int id = nextProcessId();
        if (id != 0) {
            processes[processesCount].id = id;
            snprintf(processes[processesCount].name, MAX_NAME_LENGTH, "%s", processName);
            processesCount++;
        }
        return id;
    }
    return 0; // Unable to create a new process
}

void stopProcess(int processId) {
    for (int i = 0; i < processesCount; ++i) {
        if (processes[i].id == processId) {
            for (int j = i; j < processesCount - 1; ++j) {
                processes[j] = processes[j + 1];
            }
            processesCount--;
            break;
        }
    }
}
