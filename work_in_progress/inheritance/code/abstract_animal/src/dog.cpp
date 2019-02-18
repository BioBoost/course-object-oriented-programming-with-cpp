#include "dog.h"

Dog::Dog(std::string gender, std::string favoriteFood)
    : Animal(gender, favoriteFood) {
}

std::string Dog::make_noise(void) {
    return "Wooooffff";
}
