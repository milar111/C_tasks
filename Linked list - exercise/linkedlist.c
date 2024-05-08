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
    Task* new_task = newTask(name, priority);
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
            new_task -> next = list -> head;
            list -> head = newTask; 
        }else{
            previous -> next = newTask;
            new_task -> next = current;
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
    Task *current = list->head;
    while(current != NULL){
        if(current -> priority == priority){
            current->condition = condition;
        }
    current = current -> next;
    }
    printf("error\n");
}

void deleteTask(taskList* list, int priority){
    Task* current = list -> head;
    Task* previous = NULL;
    while (current != NULL)     
    {
        if(current -> priority == priority){
            if(previous == NULL) {
                list -> head = current -> next;
            } else {
                previous -> next = current -> next;
            }
            free(current);
        }
        previous = current;
        current = current -> next;
        }
    printf("error\n");

    }


void printList(taskList* list){

}