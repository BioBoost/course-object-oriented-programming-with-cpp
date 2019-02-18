#include "arraylist.h"

// Create ArrayList based on the elements within the array
ArrayList::ArrayList(int numbers[], int size) {
  list = new int[size];
  for (int i = 0; i < size; i++) {
    list[i] = numbers[i];
  }
  this->size = size;
}

// Create empty ArrayList
ArrayList::ArrayList(void) {
  size = 0;

  // Also need to initialize pointer, otherwise
  // delete[] crashes the app if pointer is not initialized
  list = nullptr;
}

// Create an ArrayList of size and initialize the elements to 0.
ArrayList::ArrayList(int size) {
  list = new int[size];
  for (int i = 0; i < size; i++) {
    list[i] = 0;
  }
  this->size = size;
}

// A destructor is called when an object is destroyed by:
// - calling delete on a dynamically create object
// - an object on the stack that goes out of scope
ArrayList::~ArrayList(void) {
  // Since the list was dynamically created on the heap,
  // we also need to free the memory when an ArrayList object
  // goes out of scope. Since list is a pointer to an array,
  // need to use delete[] instead of delete
  delete[] list;
}

// Cannot add to current array, we need to request bigger
// memory block from the system (heap). Then we copy original
// array to new memory and add the new element.
// A real ArrayList will not extend by 1 element. Typically will double
// in capacity, for example: 1, 2, 4, 8, 16, 32, 64
// It will double again if no space is left. Does require you to keep both
// capacity and number of elements
void ArrayList::add(int value) {
  int * newList = new int[size+1];
  for (int i = 0; i < size; i++) {
    newList[i] = list[i];
  }
  newList[size] = value;
  size++;

  delete[] list;
  list = newList;
}

// Replace an element with value @ index
// Check to make sure we don't go out of bound
void ArrayList::replace(int value, int index) {
  if (index >= size) {
    return;
  }
  list[index] = value;
}

// Replaced print() with to_string(). Does not force
// output to terminal. Let the choice for the user.
std::string ArrayList::to_string(void) {
  if (size == 0) {
    return "[]";
  } else {
    std::string output = "[";
    for (int i = 0; i < size; i++) {
      output += std::to_string(list[i]);
      if (i < size-1) {
        output += ", ";
      }
    }
    output += "]";
    return output;
  }
}