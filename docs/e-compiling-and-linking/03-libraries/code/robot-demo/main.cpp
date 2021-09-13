#include <iostream>

// Notice that we include external header file !
#include <robot.h>

using namespace std;

int main() {
  Robot robot("Markus");

  cout << robot.to_string() << endl;

  return 0;
}