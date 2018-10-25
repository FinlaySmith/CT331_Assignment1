#ifndef CT331_ASSIGNMENT_TESTS
#define CT331_ASSIGNMENT_TESTS

void runTests();

int q1_length_null_listElement_should_return_length_of_0();
int q1_length_single_listElement_should_return_length_of_1();
int q1_length_test();

int q1_stack_push_should_add_to_top_of_list();
int q1_stack_pop_should_remove_from_top_of_list();

int q1_queue_enqueue_should_add_to_top_of_list();
int q1_queue_dequeue_should_remove_from_tail_of_list();

// test framework code
int Assert(int condition, char* message);

#endif
