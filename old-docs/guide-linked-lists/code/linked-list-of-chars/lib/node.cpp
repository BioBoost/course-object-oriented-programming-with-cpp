// node.cpp
#include "node.h"

namespace LinkedListWithChars {

  Node::Node(char data) {
    this->data = data;
  }

  void Node::set_next(Node * next) {
    this->next = next;
  }

  char Node::get_data(void) {
    return data;
  }

  Node * Node::get_next(void) {
    return next;
  }

  std::string Node::to_string(void) {
    return std::string("[ data: '") + data + "', next: "
      + (next ? "Node" : "null") + "]";
  }

};