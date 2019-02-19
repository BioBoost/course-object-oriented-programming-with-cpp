#include "animal.h"

#pragma once

class Dog : public Animal
{
    public:
        Dog(std::string gender, std::string favoriteFood);

    public:
        virtual std::string make_noise(void);

};
