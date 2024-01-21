#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 5
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Process;

extern Process processes[MAX_PROCESSES];
extern int processesCount;

int nextProcessId();
int createNewProcess(const char *processName);
void stopProcess(int processId);

#endif
