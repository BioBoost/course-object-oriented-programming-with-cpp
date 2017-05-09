#pragma once

#include <string>

class Animal
{
    private:
        std::string gender;
        std::string favoriteFood;

    public:
        Animal(std::string gender, std::string favoriteFood);

    public:
        std::string get_gender(void);
        std::string get_favorite_food(void);

    public:
        virtual std::string make_noise(void) = 0;
};
