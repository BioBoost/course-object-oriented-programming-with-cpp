#pragma once

#include <string>

// This class represents a dynamic array that can grow
// in size as needed. Very similar to the Arraylist of Java

class ArrayList {
  public:
    // Constructors (overloading)
    ArrayList(int numbers[], int size);
    ArrayList(void);    // Default constructor = no arguments
    ArrayList(int size);
    
    // Destructor
    ~ArrayList(void);

  public:
    void add(int value);
    void replace(int value, int index);
    std::string to_string(void);

  private:
    int size;

    // This is pointer to a memory location that
    // holds a list of integers (size to be exact).
    int * list;
};
