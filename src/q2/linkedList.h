#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, char* data, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);

// Additional Assignment Methods

// length of the linked list
int length(listElement* list);

// stack methods

void push(listElement** list, char* data, size_t size);

listElement* pop(listElement** list);

// queue methods

void enqueue(listElement** list, char* data, size_t size);

listElement* dequeue(listElement* list);

// testing 
// needed to add this to check the state of list elements in calling/test code
char* elementData(listElement* current);

#endif
