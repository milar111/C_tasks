#include<stdio.h>

#define MAX 30

typedef unsigned long long ull;

typedef struct DateTime {
    int date;
    int month;
    int year;
    struct {
        int hour;
        int minute; 
    } time1;
} DateTime;

typedef struct StudentData {
    char f_name[MAX + 1];
    char l_name[MAX + 1];
    char email[MAX + (2 * MAX)];
    char phone_number[20];
} StudentData;

typedef struct{
    
}Choice;

typedef struct Task {
    char title[MAX];
    char description[10 * MAX];
    DateTime event_date; 
    StudentData participants[100];
    int num_participants;
} Task;

int printParticipant(StudentData participant) {
    printf("FirstName: %s\nLastName: %s\nEmail: %s\nPhoneNumber: %s\n", participant.f_name, participant.l_name, participant.email, participant.phone_number); // Changed '%llu' to '%s' to print phone number as string
    return 0;
}

void printCause(Task cause) {
    printf("Title: %s\n", cause.title);
    printf("Description: %s\n", cause.description);
    printf("Year: %d\n", cause.event_date.year); 
    printf("Month: %d\n", cause.event_date.month); 
    printf("Date: %d\n", cause.event_date.date);
    printf("Time: %d : %d\n", cause.event_date.time1.hour, cause.event_date.time1.minute); 
    for(int i = 0; i < cause.num_participants; i++) {
        printParticipant(cause.participants[i]);
    }
}

int main(void){
    Task cause1 = {
        .title = "Cleaning the local park",
        .description = "Join us in cleaning up the park and making it a better place for everyone!",
        .event_date = { .date = 15, .month = 4, .year = 2024, .time1 = { .hour = 10, .minute = 0 }},
        .participants = {
            {.f_name = "John", .l_name = "Doe", .email = "john@example.com", .phone_number = "123456789"},
            {.f_name = "Jane", .l_name = "Smith", .email = "jane@example.com", .phone_number = "987654321"}, 
        },
        .num_participants = 2
    };

    Task cause2 = {
        .title = "Fundraising for homeless shelter",
        .description = "Help us raise funds for the local homeless shelter to provide food and shelter for those in need.",
        .event_date = { .date = 20, .month = 4, .year = 2024, .time1 = { .hour = 14, .minute = 30 }},
        .participants = {
            {.f_name = "Alice", .l_name = "Johnson", .email = "alice@example.com", .phone_number = "555123456"}, 
            {.f_name = "Bob", .l_name = "Williams", .email = "bob@example.com", .phone_number = "555987654"},
        },
        .num_participants = 2 
    };

    printf("Cause 1:\n");
    printCause(cause1);
    printf("\n");
    printf("Cause 2:\n");
    printCause(cause2);

}
