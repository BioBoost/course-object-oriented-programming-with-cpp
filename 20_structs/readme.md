---
description: Structs are a common used data structuring type in C++, inherited from C.
---

# Chapter 20 - Structs

Basically a `struct` in C++ is the same as a class. The only difference between them is that the members of a `class` are `private` by default, while the members of a `struct` are `public` by default.

The only reason a struct is available in C++ is because of backward compatibility with C. The C programming language is not object oriented and does not have a keyword `class`, only structs. In C, structs can therefore not house member functions (methods), while this is perfectly possible in C++.

## The Old Switcheroo

Below is a simple class `User`:

```c++
class User {
  // Default access is private for class !

  public:
    User(std::string name) {
      this->name = name;
    }

  public:
    std::string get_name() {
      return name;
    }

  private:
    std::string name = "";
};
```

Since the access modifiers were placed explicitly in the code, the keyword `class` can be directly interchanged with the keyword `struct` as shown below:

```c++
struct User {
  // Default access is public for struct !

  public:
    User(std::string name) {
      this->name = name;
    }

  public:
    std::string get_name() {
      return name;
    }

  private:
    std::string name = "";
};
```

There is no difference for creating instances or calling members of either:

```c++
User user("Nico");
std::cout << user.get_name() << std::endl;
```

## Use Cases

As mentioned before, the main reason structs exist in C++ is for backward compatibility with C. There are however some use cases in which they are considered a valid option and good practice.

### Plain Old Data objects

Structs are also often used when in need of PODs (Plain Old Data objects). In this case data is grouped together using structs. A POD is a data structure that is represented only as a passive collection of instance variables, without behavior or without using object-oriented features.

A good example might be a struct `Point2D`, which combines the `x` and `y`components of a 2D point in space.

```c++
struct Point2D {
  double x = 0;
  double y = 0;
};
```

### Multiple Return Values

In C++ a function or method can only return a single value. However by packing data inside objects, it is possible to return multiple pieces of data as a single value.

C++ provides many different options to do this, however most of these lead to bad and unreadable code:

* Using pointers or references as output parameters
* Returning an array, `std::array` or `std::vector` when their types match
* Returning an `std::tuple`

However a much cleaner solution lies in returning an instance of a `class` or a `struct`. Since these pieces of bundled data are often considered PODs, many programmers will use an instance of a struct to return multiple values from a function or method.

Consider the following example where a function can search an `std::string` for a given keyword and return the match itself, but also the parts before and after the match.

By declaring a `struct` of `std::string`, the function can return the bundled data:

```c++
struct SearchMatch {
  std::string before;
  std::string match;
  std::string after;
};
```

Now the implementation for the function can be as simple as:

```c++
SearchMatch find_match(std::string text, std::string key) {
  SearchMatch match {
    "", "", ""
  };

  std::size_t startPos = text.find(key);
  if (startPos !=std::string::npos) {
    match.before = text.substr(0, startPos);
    match.match = key;
    match.after = text.substr(startPos+key.length(), text.length());
  }

  return match;
}
```

A small demo app could be:

```c++
int main(int argc, char const *argv[])
{
  SearchMatch match = find_match("C:/users/nicod/projects/hello.txt", "users");

  std::cout << "Before: " << match.before << std::endl;
  std::cout << "Match: " << match.match << std::endl;
  std::cout << "After: " << match.after << std::endl;

  return 0;
}
```

Consider for example the alternative using an array of the three elements, which is only possible here because all three parts are of the same type, namely `std::string`. In this case the code would change to this:

```c++
std::string * find_match(std::string text, std::string key) {
  std::string * results = new std::string[3];

  std::size_t startPos = text.find(key);
  if (startPos !=std::string::npos) {
    results[0] = text.substr(0, startPos);
    results[1] = key;
    results[2] = text.substr(startPos+key.length(), text.length());
  }

  return results;
}

int main(int argc, char const *argv[])
{
  std::string * results = find_match("C:/users/nicod/projects/hello.txt", "users");

  std::cout << "Before: " << results[0] << std::endl;
  std::cout << "Match: " << results[1] << std::endl;
  std::cout << "After: " << results[2] << std::endl;

  delete results;
  return 0;
}
```

While a bit shorter, this code is a lot less readable. The indexes of the array have no real meaning. This approach is also very prone to errors and the code that is using the functionality of the function `find_match` is also responsible of deleting the dynamically allocated array of strings allocate by the `find_match` function.