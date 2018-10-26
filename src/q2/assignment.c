#include <stdio.h>

#include "linkedList.h"
#include "tests.h"

int main(int arg, char* argc[]){
  // add additional tests that need output here in these tests
  runTests();

  // print header 
  printf("\n\n[Unit Tests]\n");

  // no out put inside unit tests!!

  // length
  printf("1. length tests:\n");
  q1_length_null_listElement_should_return_length_of_0();
  q1_length_single_listElement_should_return_length_of_1();
  q1_length_test();

  printf("\n2. Stack tests:\n");
  q1_stack_push_should_add_to_top_of_list();
  q1_stack_pop_should_remove_from_top_of_list();

  printf("\n3. Queue tests:\n");
  q1_queue_enqueue_should_add_to_top_of_list();
  q1_queue_dequeue_should_remove_from_tail_of_list();

  return 0;
}
