#include "processes.h"
#include <stdio.h>

struct Process processes[5];
int processescount = 0;

int nextprocessid() {
    static int currentid = 1; 
    if (currentid <= 5) {
        return currentid++;
    }
    return 0;
}

int createnewprocess(const char *processname) {
    if (processescount < 5) {
        int id = nextprocessid();
        if (id != 0) {
            processes[processescount].id = id;
            for (int i = 0; i < 30 && processname[i] != '\0'; i++) {
                processes[processescount].name[i] = processname[i];
            }
            processescount++;
        }
        return id;
    }
    return 0;
}

void stopprocess(int processid) {
    for (int i = 0; i < processescount; i++) {
        if (processes[i].id == processid) {
            for (int j = i; j < processescount - 1; j++) {
                processes[j] = processes[j + 1];
            }
            processescount--;
            break;
        }
    }
}
