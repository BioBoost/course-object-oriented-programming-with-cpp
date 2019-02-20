#include <iostream>
#include "arraylist.h"

using namespace std;

int main(void) {

    ArrayList emptyList;
    cout << "Empty list: " << emptyList.to_string() << endl;

    ArrayList zeroedList(25);
    cout << "Zeroed list: " << zeroedList.to_string() << endl;

    ArrayList startingFromScratch;
    startingFromScratch.add(15);
    startingFromScratch.add(128);
    startingFromScratch.add(-815);
    startingFromScratch.add(123);
    cout << "Adding elements to empty list: " << startingFromScratch.to_string() << endl;

    startingFromScratch.replace(666, 0);
    startingFromScratch.replace(999, 1);
    startingFromScratch.replace(999, 80);    // Out of bound should not crash!!!!!!!
    cout << "Replaced first and second element: " << startingFromScratch.to_string() << endl;

    int someArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArrayList copiedArray(someArray, sizeof(someArray)/sizeof(int));
    cout << "Copied array of ints: " << copiedArray.to_string() << endl;

    // Remark:
    // sizeof returns the number of bytes for an array of type.
    // sizeof can only be used on an array on the stack within the scope of that array.
    // You cannot use it on a pointer to an array.

    return 0;
}