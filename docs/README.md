# Evolved C++

This is an early stage draft of a C++ course.

## Style

A definition of a concept can be placed in a definition container. Code is allowed inside of these containers.

::: definition Variable
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

::: warning Do try this at home
Lorep Ipsum
:::

`danger` containers:

::: danger Do try this at home
Lorep Ipsum
:::

`tip` containers:

::: tip Make sure to practice
lorem ipsum
:::

Really small inline exercises should be placed throughout the chapters (kinda like a code kata).

::: definition Code Kata
A code kata is an exercise in programming which helps programmers hone their skills through practice and repetition.
:::

This can actually easily be accomplished using the `details` container, allowing the solution to be hidden.

:::::: tip Hello World
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

## Ideas

Todo

## License

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
