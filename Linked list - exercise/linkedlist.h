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
    int prioritet;
    struct Task* sledvasht;
} Task;

typedef struct {
    Task* head;
} taskList;

Task* newTask(const char* name, int prioritet);

void addTask(taskList* spisuk, const char* name, int prioritet);

void changeCondition(taskList* spisuk, int prioritet, Condition Condition);

void deleteTask(taskList* spisuk, int prioritet);

void printList(taskList* spisuk);

#endif 
