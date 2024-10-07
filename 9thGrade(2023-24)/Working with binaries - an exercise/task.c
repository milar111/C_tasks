#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGTH 255
#define FILE_NAME "test.bin"

typedef struct {
    int EGN;  
    char name[NAME_MAX_LENGTH + 1];
    int age;
    unsigned char education;
    unsigned char employment_status;
    unsigned char marital_status;
} Citizen;

void print_menu() {
    printf("Menu:\n");
    printf("1. Add new record\n");
    printf("2. Delete record by EGN\n");
    printf("3. Print all records\n");
    printf("4. Exit\n");
}

void add_record(FILE *file) {
    Citizen citizen;
    
    printf("Enter EGN: ");
    scanf("%d", &citizen.EGN);
    
    printf("Enter full name: ");
    scanf(" %[^\n]s", citizen.name);  
    
    printf("Enter age: ");
    scanf("%d", &citizen.age);
    
    printf("Enter education (0-None, 1-Primary, 2-Secondary, 3-Higher): ");
    scanf("%hhu", &citizen.education);
    
    printf("Enter employment status (0-Unemployed, 1-Employed): ");
    scanf("%hhu", &citizen.employment_status);
    
    printf("Enter marital status (0-Single, 1-Married): ");
    scanf("%hhu", &citizen.marital_status);
    
    fseek(file, 0, SEEK_END);
    fwrite(&citizen, sizeof(Citizen), 1, file);
}

void delete_record(FILE *file, const char *filename) {
    int EGN;
    printf("Enter EGN: ");
    scanf("%d", &EGN);

    FILE *temp_file = fopen("temp.bin", "wb");
    if (temp_file == NULL) {
        printf("Error\n");
        return;
    }

    Citizen citizen;
    rewind(file);
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        if (citizen.EGN != EGN) {
            fwrite(&citizen, sizeof(Citizen), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename("temp.bin", filename);

    file = fopen(filename, "rb+");  
    if (file == NULL) {
        printf("Failed to reopen file\n");
    }
}

void print_records(FILE *file) {
    Citizen citizen;
    rewind(file); 
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        printf("-------------------------------\n");
        printf("EGN: %d\n", citizen.EGN);
        printf("Name: %s\n", citizen.name);
        printf("Age: %d\n", citizen.age);
        printf("Education: %hhu\n", citizen.education);
        printf("Employment status: %hhu\n", citizen.employment_status);
        printf("Marital status: %hhu\n", citizen.marital_status);
        printf("-------------------------------\n");
    }
}

int main() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        file = fopen(FILE_NAME, "wb+");
        if (file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }
    }

    int choice;
    do {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(file);
                break;
            case 2:
                delete_record(file, FILE_NAME);
                break;
            case 3:
                print_records(file);
                break;
            case 4:
                fclose(file);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
