#include <stdio.h>
#define MAX 30
#define MAXCH 100
struct {
    int day;
    int month;
    int year;
    struct {
        int hour;
        int minute;
    } time;
} typedef Date;

typedef struct {
    char first_name[MAX];
    char middle_name[MAX];
    char last_name[MAX];
    char email[MAX + MAX];
    char phone_number[MAX / 2];
} Participant;

typedef struct {
    Participant participant;
    int will_participate; 
} ParticipantResponse;

typedef struct {
    char title[MAXCH];
    char description[MAXCH * 5];
    Date date;
    ParticipantResponse participants[MAXCH];
    int participant_count;
} Cause;

void printDate(Date date) {
    printf("%02d.%02d.%04d %02d:%02d", date.day, date.month, date.year, date.time.hour, date.time.minute);
}

void printParticipant(Participant participant) {
    printf("Name: %s %s %s\nEmail: %s\nPhone: %s\n", participant.first_name, participant.middle_name, participant.last_name, participant.email, participant.phone_number);
}

void printCause(Cause cause) {
    printf("Title: %s\nDescription: %s\nDate: ", cause.title, cause.description);
    printDate(cause.date);
    printf("\nParticipants:\n");
    for (int i = 0; i < cause.participant_count; ++i) {
        printf("Participant %d:\n", i+1);
        printParticipant(cause.participants[i].participant);
        printf("Will participate: %s\n", cause.participants[i].will_participate ? "Yes" : "No");
    }
}

int main() {
    Cause cause1 = {
        .title = "Clean-up Campaign",
        .description = "A campaign to clean up the local park.",
        .date = { .day = 25, .month = 4, .year = 2024, .time = { .hour = 10, .minute = 0 } },
        .participant_count = 2,
        .participants = {
            { .participant = { .first_name = "John", .last_name = "Doe", .email = "john@example.com", .phone_number = "45985049" }, .will_participate = 1 },
            { .participant = { .first_name = "Jane", .last_name = "Smith", .email = "jane@example.com", .phone_number = "493439840" }, .will_participate = 0 }
        }
    };

    Cause cause2 = {
        .title = "Blood Donation Drive",
        .description = "A blood donation drive at the local hospital.",
        .date = { .day = 30, .month = 4, .year = 2024, .time = { .hour = 9, .minute = 0 } },
        .participant_count = 1,
        .participants = {
            { .participant = { .first_name = "Alice", .last_name = "Johnson", .email = "alice@example.com", .phone_number = "95834050" }, .will_participate = 1 }
        }
    };

    printf("Cause 1:\n");
    printCause(cause1);
    printf("\nCause 2:\n");
    printCause(cause2);

    return 0;
}
