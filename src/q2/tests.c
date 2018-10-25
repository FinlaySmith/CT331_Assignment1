#include <stdio.h>
#include <string.h>

#include "tests.h"
#include "linkedList.h"

// TEST CODE
void runTests() {
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  listElement* l3 = insertAfter(l2, "a string...  (3)", 30);
  listElement* l4 = insertAfter(l3, "another string.. (4)", 22);
  listElement* l5 = insertAfter(l4, "a final string (5)", 30);

  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  // Test length 
  int len = length(l);    // should be 4
  printf("Length: %d\n", len);

  printf("\nTests complete.\n");
}

// UNIT TEST CODE
int q1_length_null_listElement_should_return_length_of_0 ( ) {
  printf("    1.1  NULL listElement should return length of 0\n");
  int listLength = length(NULL);
  Assert(listLength == 0, "NULL listElement, length should return 0");

  return 0;
}

int q1_length_single_listElement_should_return_length_of_1 ( ) {
  printf("    1.2  Single listElement should return length of 1\n");
  int listLength = length(NULL);
  Assert(listLength == 1, "NULL listElement, length should return 0");

  return 0;
}

int q1_length_test(){
  printf("    1.3  basic listElement test, 5 elements\n");
  listElement* head = createEl("Head", 5);
  listElement* item1 = insertAfter(head, "Item1", 6);
  listElement* item2 = insertAfter(item1, "Item2", 6);
  listElement* item3 = insertAfter(item2, "Item3", 6);
  listElement* tail = insertAfter(item3, "Tail", 5);
  
  int listLength = length(tail);
  Assert(listLength == 10, "Invalid list length");

  return 0;
}

int q1_stack_push_should_add_to_top_of_list ( ) {
  printf("    2.1 Stack push should add to top of list\n");

  listElement* head = createEl("Head", 5);
  push(&head, "Item1", 6);

  char* data = elementData(head);

  Assert(strcmp(data, "Item1")==1, "Invalid node in head");

  return 0;
}

int q1_stack_pop_should_remove_from_top_of_list ( ) {
  printf("    2.2 Stack pop should remove from top of list\n");
  
  listElement* head = createEl("Head", 5);
  push(&head, "Item1", 6);
  push(&head, "Item2", 6);
  push(&head, "Item3", 6);

  listElement* popped = pop(&head);

  Assert(strcmp(elementData(popped), "Item3")==1, "Invalid node Popped from stack");
  Assert(strcmp(elementData(head), "Item2")==1, "Invalid head node after popping from stack");
 
  return 0;
}

int q1_queue_enqueue_should_add_to_top_of_list ( ) {
  printf("    3.1 Enqueue should add to the top of the list\n");

  listElement* head = createEl("Head", 5);
  enqueue(&head, "Item1", 6);

  Assert(strcmp(elementData(head), "Item1")==1, "Invalid head node after enqueue");
 
  return 0;
}

int q1_queue_dequeue_should_remove_from_tail_of_list ( ) {
  printf("    3.2 Dequeue should remove from the top of the list\n");
  
  listElement* head = createEl("Head", 5);

  enqueue(&head, "Item1", 6);
  enqueue(&head, "Item2", 6);
  enqueue(&head, "Item3", 6);
  enqueue(&head, "Tail", 5);

  listElement* queueItem = dequeue(head);

  Assert(strcmp(elementData(head), "Tail")==1, "Dequeued incorrect node");
 
  return 0;
}

int Assert(int condition, char* message) {
  if(!condition) {
    printf("FAIL * %s\n", message);
    return 1;
  }

  return 0;
}