#include <stdio.h>
#include "genericLinkedList.h"

int printInt(void* data) 
{ 
  printf("%d\n", *(int*)data);

  return 0;
}

void runTests(){
  printf("Adding ints...\n");
  int arr[] = {10, 20, 30, 40, 50}; 
  genericListElement* item = createEl(&arr[0], sizeof(int), printInt);

  genericListElement* insertionPoint = item;
  for (int i=1; i<=4; i++)
  {
    genericListElement* newItem = insertAfter(insertionPoint, &arr[i], sizeof(int), printInt); 
    insertionPoint = newItem;
  }

  traverse(item);

  printf("\nTests complete.\n");
}
