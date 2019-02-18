#include <iostream>

using namespace std;

int main()
{
    try {
        string("abc").substr(10);      // Can throw an std::length_error
    } catch (const exception& e) {
        cout << "Sorry string is too short to index at 10" << endl;
        cout << e.what();
    }

    return 0;
}
