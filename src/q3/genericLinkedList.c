#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, int (*functionPointer)(void* data) ){
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void *dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }

  for (int i=0; i<size; i++)
   *(char *)(dataPointer + i) = *(char *)(data + i);

  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  e->printFunction = functionPointer;
  return e;
}

//Prints out each element in the list
void traverse(genericListElement* start){
  genericListElement* current = start;
  while(current != NULL){
    current->printFunction(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, int (*functionPointer)(void* data)){
  genericListElement* newEl = createEl(data, size, functionPointer);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}

//Delete the element after the given el
void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

// length of the linked list
int length(genericListElement* list) {
  genericListElement* element = list;
  int len = 0;
  while(element != NULL){
    element = element->next;
    len++;
  }
  return len;
}

// stack methods
void push(genericListElement** list, void* data, size_t size, int (*functionPointer)(void* data) ) {
  genericListElement* newHead = createEl(data, size, functionPointer);
  newHead->next = *list;
  *list = newHead;
}

genericListElement* pop(genericListElement** list) {
  genericListElement* popped = *list;
  *list = popped->next;  
  popped->next = NULL;
  return popped;
}

// queue methods
void enqueue(genericListElement** list, void* data, size_t size, int (*functionPointer)(void* data)) {
  push(list, data, size, functionPointer);
}

// as this is not listElement** we cannot dequeue the 
// last item from he queue
genericListElement* dequeue(genericListElement* list) {

  // find tail
  genericListElement* previous = NULL; 
  genericListElement* tail = list;
  while(tail->next != NULL){
    previous = tail;
    tail = tail->next;
  }

  // disconnect from previous node
  if(previous != NULL){
    previous->next = NULL;
  }
  // as we do not have a 

  return tail;
}
