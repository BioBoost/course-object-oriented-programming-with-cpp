#include <iostream>
#include "animal.h"
#include "dog.h"

using namespace std;

void let_animal_speak(Animal * animal) {
    cout << animal->make_noise() << endl;
}

void let_animal_speak_ref(Animal & animal) {
    cout << animal.make_noise() << endl;
}

int main()
{
    //Animal whale("Female", "Plankton");        // cannot declare variable 'whale' to be of abstract type 'Animal'|

    Dog sparky("Male", "Ferrero Rocher");

    let_animal_speak(&sparky);
    let_animal_speak_ref(sparky);

    return 0;
}
