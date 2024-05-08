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
    strcpy(task->name, name);
    task->priority = priority;
    task->condition = new;
    task->next = NULL;
    return task;
}

void addTask(taskList* list, const char* name, int priority){
    Task* newTask = newTask(name, priority);
    if(list->head == NULL){
        list->head = newTask;
    } else{
        Task* current = list->head;
        Task* previous = NULL;

        while(current != NULL && current -> priority <= priority){
            previous = current;
            current = current->next;
        }
        if(previous==NULL) {
            newTask -> next = list -> head;
            list -> head = newTask; 
        }else{
            previous -> next = newTask;
            newTask -> next = current;
        }
    }
    Task* current = list -> head;
    int count = 1;
    while (current != NULL)
    {
        current -> priority = count++;
        current = current -> next;
    }
    
}

void changeCondition(taskList* list, int priority, Condition condition){

}

void deleteTask(taskList* list, int priority){

}

void printList(taskList* list){

}