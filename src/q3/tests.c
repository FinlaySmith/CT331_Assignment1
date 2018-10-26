#include <stdio.h>
#include "genericLinkedList.h"

int printInt(void* data) 
{ 
  printf("%d\n", *(int*)data);

  return 0;
}

void runTests(){
  printf("** Adding ints to generic linked list\n");
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
  genericListElement* head = createEl(&arr[0], sizeof(int), printInt);

  genericListElement* insertionPoint = head;
  for (int i=1; i<=4; i++)
  {
    genericListElement* newItem = insertAfter(insertionPoint, &arr[i], sizeof(int), printInt); 
    insertionPoint = newItem;
  }
  traverse(head);

  deleteAfter(head);
  
  printf("\n** Delete After head\n");
  traverse(head);

  push(&head, &arr[5], sizeof(int), printInt);
  push(&head, &arr[6], sizeof(int), printInt);
  pop(&head);

  printf("\n** After sequence of push, push, pop\n");
  traverse(head);

  printf("\n** Dequeue tail and print\n");
  genericListElement* tail = dequeue(head);
  tail->printFunction(tail->data);

  printf("\nTests complete.\n");
}
