
# Evolved C++

This is an early stage draft of a C++ course.

## Style

A definition of a concept can be placed in a definition container. Code is allowed inside of these containers.

::: definition Definition - Variable
A **variable** is a symbolic name for a memory location that can store data.

```cpp
  int x;
  int y;
  double x;
```

:::

Code is always placed between code fences. Lines can be highlighted by using curly braces after language.

```cpp{1,3-5}
#include <iostream>

int main() {
  return 0;
}
```

Code should most of the time be followed by an `output` container wrapped around `<pre>` tags. No other way to reserve white space and line breaks.

::: output
<pre>
Hello World.
Welcome to the exciting world of C++ programming.
</pre>
:::

There are also `warning` containers:

::: warning Warning - Do try this at home
Lorep Ipsum
:::

`danger` containers:

::: danger Danger - Do try this at home
Lorep Ipsum
:::

`tip` containers:

::: tip Tip - Make sure to practice
lorem ipsum
:::

Really small inline exercises should be placed throughout the chapters (kinda like a code kata).

A code kata is an exercise in programming which helps programmers hone their skills through practice and repetition. This can actually easily be accomplished using the `details` container, allowing the solution to be hidden.

:::::: kata Code Kata - Hello World

Create a small C++ application that outputs `Hello World from C++` to the terminal.

::: details Solution

```cpp
#include <iostream>

using namespace std;

int main() {
  cout << "Hello World from C++" << endl;
  return 0;
}
```

:::
::::::

::: insight Key Insight - How code is executed
Code is processed/executed the same way it is written, from top to bottom.
:::

:::::: question Question - Hello World

What are the main purposes of a Hello World application?

::: details Solution

* Compiler test
* Arbitrary code execution
* Basic demo for new language

:::
::::::

## Ideas

- Compiler optimizations?
- Debugging using VSCode
- Would love to have a hero image with nice description for each chapter. Maybe we can fix this using Vue-component.

## Problems that many students have

- Don't see how data flows via arguments to attributes or to other methods
- Don't always understand what keep as a local var and what to make an attribute
- Single Responsibility