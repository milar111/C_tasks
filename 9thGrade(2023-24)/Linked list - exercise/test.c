#include<stdio.h>
#include "linkedlist.h"

void tests(){
    taskList list;
    list.head == NULL;

    addTask(&list, "Wash the dishes", 1);
    addTask(&list, "Clean your room", 2);
    addTask(&list, "Take out the trash", 1);

    printf("List:\n");
    printList(&list);

    changeCondition(&list, 2, finished);
    printf("Condition changed");
    printList(&list);

    deleteTask(&list, 2);
    printf("Task deleted");
    printList(&list);
    

}
