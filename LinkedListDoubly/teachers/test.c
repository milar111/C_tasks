#include <stdio.h>
#include "linkedlist.h"

void printElement(uint index, ListType value) {
  printf("[%u]=>%lf ", index, value);
}

void printLinkedList(LinkedList * list) {
  forEach(list, printElement);
  printf("\n");
}

int main(void) {

  printf("Executing tests \n");
  LinkedList list = init();
  printf("Is head NULL: %d\n", list.head == NULL);
  printf("List size: %u\n", list.size);

  pushFront(&list, 10);
  pushFront(&list, 15);
  pushFront(&list, 20);
  printLinkedList(&list);

  struct ListNode * secondElement = getElement(&list, 1);
  printf("Second element: %lf \n", secondElement->value);

  push(&list, 1, 99);
  printLinkedList(&list);

  pushBack(&list, 105);
  printLinkedList(&list);

  setElement(&list, 2, 999);
  printLinkedList(&list);

  ListType firstValue = popFront(&list);
  printf("First value: %lf \n", firstValue);
  printLinkedList(&list);

  ListType thirdElement = pop(&list, 2);
  printf("Third value: %lf \n", thirdElement);
  printLinkedList(&list);

  ListType lastValue = popBack(&list);
  printf("Last value: %lf \n", lastValue);
  printLinkedList(&list);

  release(&list);
  printf("Is head NULL: %d\n", list.head == NULL);
  printf("List size: %u\n", list.size);

  return 0;
}