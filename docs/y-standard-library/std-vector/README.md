---
description: needs to be done
---

# Vector class

Vectors are sequence containers representing arrays that can change in size.

| Class | Header |
| --- | --- |
| `std::vector` | `#include <vector>` |

## Common Methods

| Common Methods | Description |
| --- | --- |
| `.size()` | returns the number of elements |
| `.push_back()` | add element to the end |
| `.clear()` | remove all elements |
| `operator[]` | access specified element |

## Usage Example

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Construction requires type to be specified between <> (templated)
  std::vector<std::string> words;

  words.push_back("Hello");
  words.push_back("World");
  words.push_back("from");
  words.push_back("C++");

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }

  return 0;
}
```

::: output
<pre>
Hello
World
from
C++
</pre>
:::

## Sorting

The elements of a vector can be easily sorted using the `sort()` method found in `<algorithm>`. While it can sort values that implement the `<` operator by default, a custom comparator function can be supplied.

Example of sorting `std::string` elements by their length:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include "string_comparator.h"
#include <algorithm>    // std::sort

using namespace std;

int main() {

  cout << "Demo custom sorting of std::vector" << endl;

  std::vector<std::string> wordList;

  wordList.push_back("Hello World");
  wordList.push_back("Bye");
  wordList.push_back("Nice");
  wordList.push_back("Very Nice");
  wordList.push_back("Short");
  wordList.push_back("A");
  wordList.push_back("This is really long text");

  cout << "Unsorted:" << endl;
  for (auto word : wordList) {
    cout << "\t" << word << endl;
  }

  // Sort method requires begin and end iterator for the section to sort
  // As a third argument it can take a static comparator method
  sort(
      wordList.begin(), wordList.end(),
      CustomSorting::StringComparator::by_length
  );

  cout << endl << "Nicely sorted:" << endl;
  for (auto word : wordList) {
    cout << "\t" << word << endl;
  }

  return 0;
}
```

With the comparator being:

```cpp
#pragma once

#include <string>

namespace CustomSorting {

  class StringComparator {

    public:
      // Method is made static and so is called on class not on object
      static bool by_length(std::string first, std::string second);

  };

};
```

and

```cpp
#include "string_comparator.h"

namespace CustomSorting {

  // All a comparator needs to do is return a bool value
  // indicating if the first should be placed before second
  bool StringComparator::by_length(std::string first, std::string second) {
    return first.length() < second.length();
  }

};
```

::: output
<pre>
Demo custom sorting of std::vector
Unsorted:
    Hello World
    Bye
    Nice
    Very Nice
    Short
    A
    This is really long text

Nicely sorted:
    A
    Bye
    Nice
    Short
    Very Nice
    Hello World
    This is really long text
</pre>
:::

More info at [https://en.cppreference.com/w/cpp/algorithm/sort](https://en.cppreference.com/w/cpp/algorithm/sort).