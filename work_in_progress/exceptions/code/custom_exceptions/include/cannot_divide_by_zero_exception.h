#pragma once

namespace CustomExceptions {

    class CannotDivideByZeroException: public std::exception {

        public:
            virtual const char * what() const throw() {
                return "You cannot divide by zero";
            }

    };

};

