#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct genericlistElementStruct{
  void* data;
  size_t size;
  struct genericlistElementStruct* next;
  int (*printFunction)(void* data);
} genericListElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, int (*functionPointer)(void* data));

//Prints out each element in the list
void traverse(genericListElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* after, void* data, size_t size, int (*functionPointer)(void* data));

//Delete the element after the given el
void deleteAfter(genericListElement* after);

// Additional Assignment Methods

// length of the linked list
int length(genericListElement* list);

// stack methods

void push(genericListElement** list, void* data, size_t size, int (*functionPointer)(void* data));

genericListElement* pop(genericListElement** list);

// queue methods

void enqueue(genericListElement** list, void* data, size_t size, int (*functionPointer)(void* data));

genericListElement* dequeue(genericListElement* list);

#endif
