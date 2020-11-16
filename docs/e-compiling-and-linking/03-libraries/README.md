---
description: needs to be done
---

# Libraries

*TODO: Just some example. Still needs work*

## Static Linking

Create subdir `lib`:

```cpp
// robot.h
#pragma once

#include <string>

class Robot {
  public:
    Robot(std::string name);

  public:
    std::string to_string(void);

  private:
    std::string name;
};
```

```cpp
// robot.cpp
#include "robot.h"

Robot::Robot(std::string name) {
  this->name = name;
}

std::string Robot::to_string(void) {
  return "Robot is called " + name;
}

```

Now example main one dir up for example:

```cpp
#include <iostream>

// Notice that we include external header file !
#include <robot.h>

using namespace std;

int main() {
  Robot robot("Markus");

  cout << robot.to_string() << endl;

  return 0;
}
```

1. Compile and archive the library. `-c` tells compiler to only compile and not link. This will produce `robot.o`.Next archive the library using `ar`. This will produce `libRobot.a`:

  ```bash
  g++ -c robot.cpp
  ar crf libRobot.a robot.o
  ```

2. Compile your main application without linking (so only object file). `-I` flag tells the compiler to add the `lib` directory to its path when looking for header files. This will produce `main.o`:

  ```bash
  g++ -c main.cpp -Ilib
  ```

3. Last link all object files together into an executable. The `-L` flag will get `g++` to add the `lib` directory to the path.

  ```bash
  g++ main.o -L./lib -lRobot -o helloRobot
  ```
  