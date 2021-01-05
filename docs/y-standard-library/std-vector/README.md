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
