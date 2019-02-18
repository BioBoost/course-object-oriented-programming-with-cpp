#include "animal.h"

Animal::Animal(std::string gender, std::string favoriteFood) {
    this->gender = gender;
    this->favoriteFood = favoriteFood;
}

std::string Animal::get_gender(void) {
    return gender;
}

std::string Animal::get_favorite_food(void) {
    return favoriteFood;
}
