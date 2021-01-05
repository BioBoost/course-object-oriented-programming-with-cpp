// Compile using:
// make
// or
// g++ main.cpp string_comparator.cpp -o sort

#include <iostream>
#include <vector>
#include <string>
#include "string_comparator.h"
#include <algorithm>    // std::sort

using namespace std;

int main() {

  cout << "Demo custom sorting of std::vector" << endl;

  std::vector<std::string> wordList;

  wordList.push_back("Hello World");
  wordList.push_back("Bye");
  wordList.push_back("Nice");
  wordList.push_back("Very Nice");
  wordList.push_back("Short");
  wordList.push_back("A");
  wordList.push_back("This is really long text");

  cout << "Unsorted:" << endl;
  for (auto word : wordList) {
    cout << "\t" << word << endl;
  }

  // Sort method requires begin and end iterator for the section to sort
  // As a third argument it can take a static comparator method
  sort(wordList.begin(), wordList.end(), CustomSorting::StringComparator::by_length);

  cout << endl << "Nicely sorted:" << endl;
  for (auto word : wordList) {
    cout << "\t" << word << endl;
  }

  return 0;
}