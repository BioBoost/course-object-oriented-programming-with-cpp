#pragma once

#include <string>

namespace CustomSorting {

  class StringComparator {

    public:
      // Method is made static and so is called on class not on object
      static bool by_length(std::string first, std::string second);

  };

};
