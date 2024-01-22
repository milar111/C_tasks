#ifndef PROCESSES_H
#define PROCESSES_H

struct Process {
    int id;
    char name[30];
};

extern struct Process processes[5];
extern int processescount;

int nextprocessid();
int createnewprocess(const char *processname);
void stopprocess(int processid);

#endif
