#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Employee {
    char name[100];
    int num_subordinates;
    struct Employee **subordinates; 
} Employee;


void serialize_employee(FILE *file, Employee *employee) {
    fwrite(employee->name, sizeof(char), 100, file);
    fwrite(&employee->num_subordinates, sizeof(int), 1, file);

    for (int i = 0; i < employee->num_subordinates; i++) {
        serialize_employee(file, employee->subordinates[i]);
    }
}

Employee* create_employee(char *name, int num_subordinates) {
    Employee *employee = (Employee*)malloc(sizeof(Employee));
    strcpy(employee->name, name);
    employee->num_subordinates = num_subordinates;
    if (num_subordinates > 0) {
        employee->subordinates = (Employee**)malloc(num_subordinates * sizeof(Employee*));
    } else {
        employee->subordinates = NULL;
    }
    return employee;
}

void create_test_hierarchy(Employee **director) {
    *director = create_employee("Director", 2);

    Employee *manager1 = create_employee("Manager 1", 3);
    manager1->subordinates[0] = create_employee("Worker 1", 0);
    manager1->subordinates[1] = create_employee("Worker 2", 0);
    manager1->subordinates[2] = create_employee("Worker 3", 0);

    Employee *manager2 = create_employee("Manager 2", 3);
    manager2->subordinates[0] = create_employee("Worker 4", 0);
    manager2->subordinates[1] = create_employee("Worker 5", 0);
    manager2->subordinates[2] = create_employee("Worker 6", 0);

    (*director)->subordinates[0] = manager1;
    (*director)->subordinates[1] = manager2;
}

void free_employee(Employee *employee) {
    for (int i = 0; i < employee->num_subordinates; i++) {
        free_employee(employee->subordinates[i]);
    }
    free(employee->subordinates);
    free(employee);
}

int main(void) {
    Employee *director = NULL;
    create_test_hierarchy(&director);

    FILE *file = fopen("employees.bin", "wb");
    if (file == NULL) {
        printf("erroro\n");
        exit(1);
    }
    serialize_employee(file, director);
    fclose(file);

    free_employee(director);

    fclose(file);

    return 0;
}