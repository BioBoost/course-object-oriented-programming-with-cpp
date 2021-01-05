#include "string_comparator.h"

namespace CustomSorting {

  // All a comparator needs to do is return a bool value
  // indicating if the first should be placed before second
  bool StringComparator::by_length(std::string first, std::string second) {
    return first.length() < second.length();
  }

};
