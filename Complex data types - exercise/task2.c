// Направете програма, която да приема от конзолата номер на ден от седмицата (започвайки от 1 до 7) и да принтира на екрана името на този ден. За целта използвайте изброен тип за дните от седмицата.



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
  enum Weekday currentDay = dayInput;

  switch(currentDay) {
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