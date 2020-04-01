#include <iostream>
#include "lib/node.h"

using namespace std;

int main() {
  cout << "Welcome to Linked List with chars ..." << endl;

  LinkedListWithChars::Node head('a');

  cout << "Node: " << head.to_string() << endl;

  return 0;
}