#include <stdio.h>

enum Weekday {
  MONDAY = 1,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
};

void printWeekdayLegend() {
  printf("1 - Monday\n");
  printf("2 - Tuesday\n");
  printf("3 - Wednesday\n");
  printf("4 - Thursday\n");
  printf("5 - Friday\n");
  printf("6 - Saturday\n");
  printf("7 - Sunday\n");
};

int main(void) {

  printWeekdayLegend();
  int dayInput = 0;
  printf("Please enter a weekday:");
  scanf("%d", &dayInput);

  switch(dayInput) {
    case MONDAY:
        printf("Monday");
        break;
    case TUESDAY:
        printf("Tuesday");
        break;
    case WEDNESDAY:
        printf("Wednesday");
        break;
    case THURSDAY: 
        printf("Thursday");
        break;
    case FRIDAY:
        printf("Friday");
        break;
    case SATURDAY:
        printf("Saturday");
        break;
    case SUNDAY:
        printf("Sunday");
        break;
    default:
        printf("Invalid Day!");
  }

}