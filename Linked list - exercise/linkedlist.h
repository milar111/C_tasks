#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

typedef enum {
    new = 1,
    inProcess,
    finished
} Condition;


typedef struct Task {
    char name[100];
    Condition Condition;
    int priority;
    struct Task* sledvasht;
} Task;

typedef struct {
    Task* head;
} taskList;

Task* newTask(const char* name, int priority);

void addTask(taskList* list, const char* name, int priority);

void changeCondition(taskList* list, int priority, Condition condition);

void deleteTask(taskList* list, int priority);

void printList(taskList* list);

#endif 
