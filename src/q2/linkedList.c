#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}

//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

// length of the linked list
int length(listElement* list) {
  listElement* element = list;
  int len = 0;
  while(element != NULL){
    element = element->next;
    len++;
  }
  return len;
}

// stack methods
void push(listElement** list, char* data, size_t size) {
  listElement* head = *list;
  listElement* newHead = createEl(data, size);
  newHead->next = *list;
  *list = newHead;
}

listElement* pop(listElement** list) {
  listElement* popped = *list;
  *list = popped->next;  
  popped->next = NULL;
  return popped;
}

// queue methods
void enqueue(listElement** list, char* data, size_t size) {
  push(list, data, size);
}

// as this is not listElement** we cannot dequeue the 
// last item from he queue
listElement* dequeue(listElement* list) {

  // find tail
  listElement* previous = NULL; 
  listElement* tail = list;
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

// testing 
// needed to add this to check the state of list elements in calling/test code
char* elementData(listElement* current){
  if(current == NULL){
    return "";
  }

  return current->data;
}
