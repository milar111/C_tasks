#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


typedef enum{
    new = 1,
    inProcess,
    finished
}Condition;

typedef struct{
        char name[100];
        Condition condition;
        int priority;
        struct Task *next;
}Task;


typedef struct{
    Task *head;
}TaskList;

Task* newTask(char * name, int priority){
    Task* task = (Task*)malloc(sizeof(Task));
    task->priority = priority;
    task->condition = new;
    task->next = NULL;
    return task;
}

void addTask(taskList* list, const char* name, int priority){

}

void changeCondition(taskList* list, int priority, Condition condition){

}

void deleteTask(taskList* list, int priority){

}

void printList(taskList* list){

}