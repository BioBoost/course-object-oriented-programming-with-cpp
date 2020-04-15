// node.h
#pragma once
#include <string>

namespace LinkedListWithChars {
  class Node {

    // Constructors
    public:
      Node(char data);

    // Methods
    public:
      void set_next(Node * next);

    public:
      char get_data(void);
      Node * get_next(void);

    public:
      std::string to_string(void);

    // Attributes
    private:
      char data;
      Node * next = nullptr;
  };
};