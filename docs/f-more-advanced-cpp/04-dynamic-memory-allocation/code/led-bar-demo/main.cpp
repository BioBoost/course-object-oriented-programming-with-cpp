#include <iostream>
#include <vector>
#include "lib/rgb_led_bar.h"

using namespace std;

int main() {
  cout << "Welcome to LED Bar Demo ..." << endl;

  unsigned int numberOfLeds = 0;
  cout << "How many leds would you like to add to the ledbar? ";
  cin >> numberOfLeds;

  cout << endl << "Creating a ledbar with " << numberOfLeds << " leds" << endl;
  Hardware::RgbLedBar bar(numberOfLeds);
  cout << bar.to_string() << endl;

  cout << endl << "Let us set some random colors:" << endl;

  srand(time(0));
  for (unsigned int i = 0; i < bar.get_length(); i++) {
    bar.get_led(i)->set_color(Visual::Color(rand()%255, rand()%255, rand()%255));
  }
  cout << bar.to_string() << endl;

  return 0;
}