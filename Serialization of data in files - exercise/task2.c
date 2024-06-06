#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int num_subordinates;
    struct Employee **subordinates;
} Employee;

Employee* deserialize_employee(FILE *file) {
    Employee *employee = (Employee*)malloc(sizeof(Employee));
    fread(employee->name, sizeof(char), 100, file);
    fread(&employee->num_subordinates, sizeof(int), 1, file);

    if (employee->num_subordinates > 0) {
        employee->subordinates = (Employee**)malloc(employee->num_subordinates * sizeof(Employee*));
        for (int i = 0; i < employee->num_subordinates; i++) {
            employee->subordinates[i] = deserialize_employee(file);
        }
    } else {
        employee->subordinates = NULL;
    }

    return employee;
}

void print_employee(Employee *employee, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }
    printf("%s\n", employee->name);

    for (int i = 0; i < employee->num_subordinates; i++) {
        print_employee(employee->subordinates[i], indent + 1);
    }
}

void free_employee(Employee *employee) {
    for (int i = 0; i < employee->num_subordinates; i++) {
        free_employee(employee->subordinates[i]);
    }
    free(employee->subordinates);
    free(employee);
}

int main(void) {
    FILE *file = fopen("employees.bin", "rb");
    if (file == NULL) {
        printf("error\n");
        exit(1);
    }
    Employee *deserialized_director = deserialize_employee(file);
    fclose(file);

    print_employee(deserialized_director, 0);
    free_employee(deserialized_director);

    return 0;
}
