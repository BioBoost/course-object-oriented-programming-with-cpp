---
description: Reading and writing data from and too files is a common practice in any application.
---

# Chapter 08 - File Streams

Until this point, we've mainly been using the `iostream` standard library, which provides the ability to read and write from and to the standard input and output using `cin` and `cout`.

However, an application often needs information from files or needs to write information to files. This can be accomplished using the standard library `fstream` which provides support for reading and writing data from and to files.

The `fstream` library defines three stream types which can be used:

* `ofstream`: represents an **output file stream** which can be used to create files and write data to files.
* `ifstream`: represent an **input file stream** which can be used to read data from files.
* `fstream`: represent a general file stream, which can both be used to write and read data to and from files.

These classes are derived directly or indirectly from the classes `istream` and `ostream`. We have already been using objects from these classes, namely `cout` (of type `ostream`) and `cin` (of type `istream`). In other words, the operators `<<` and `>>` of these classes will also be applicable for the file streams. The only difference is that they are associated with physical files.

## Instantiating a File Stream

Before starting, one needs to create a stream object of the appropriate type. For example to write to a file, a `ofstream` object needs to be instantiated:

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // File stream object
  ofstream output;

  // ...

  return 0;
}
```

Or when reading a file, an `ifstream` object is required:

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // File stream object
  ifstream input;

  // ...

  return 0;
}
```

## Opening and closing a File Stream

Before any action can be taken to transfer data with the file stream objects, they need to be associated to a file. This is realized by opening a file in a given mode. Once a file is open, any input or output operation performed on the stream object will be applied to the physical file associated with it.

To open a file, the standard `void open(const char *filename, ios::openmode mode)` function can be used. The first argument, `char * filename`, is the path to the file which should be bound to the file stream. The second argument, `ios::openmode mode`, can take flags which determine the mode in which the file should be opened.

| Mode Flag | Description |
| --- | --- |
| ios::out| Open file for writing. |
| ios::in | Open file for reading. |
| ios::app | Open file in append mode. All data is added to the end of the current content of the file.
| ios::binary | Open file in binary mode. |
| ios::ate | Set the start position of the read/write iterator at the end of the file (default is the beginning).
| ios::trunc | When opening the file in output mode and the file exists, its current content is removed and replaced by the new content. |

The before mentioned flags can be combined using the bitwise OR operator `|`. Each of the `open()` methods of the classes `ofstream`, `ifstream` and `fstream` have a default mode that is used if the file is opened without a mode argument:

| File Stream | Default Mode |
| `ofstream` | `ios::out` |
| `ifstream` | `ios::in` |
| `fstream` | `ios::in | ios::out` |

For example to open a file for writing and appending content to the end:

```c++
ofstream output;
output.open("hello.txt", ios::out | ios::app);
```

Or to open a file for both reading and writing:

```c++
fstream iofile;
iofile.open("hello.txt", ios::out | ios::in);
```

Note that the stream object is of the `fstream` type in the second example.

### Check if open succeeded

Always check if the files was opened successfully. For example, the open fails if the file doesn't exist, or if it can't be read because another program is writing it, or if the application does not have the permissions to access the file.

To check if the open operation one can check the state of the object using an `if` construct as shown below:

```c++
// File stream object
ifstream input;
input.open("hello.txt");    // Default mode is ios::in

if (!input) {
  cerr << "Could not open the file in read mode" << endl;
}
```

### Closing a file

Once done with the file stream always make sure to close it. This will make sure that the file handle is released and the stream buffers are flushed.

To close a file, just call the `close()` method on the stream object.

```c++
// File stream object
ifstream input;
input.open("hello.txt");    // Default mode is ios::in

if (!input) {
  cerr << "Could not open the file in read mode" << endl;
}

// ...

// Close the file when finished
input.close();
```

## Writing to a file

Writing to `cout` is accomplished using the **stream insertion operator** `<<`. Since `ofstream` is a derived class of `ostream`, the same operator can be used to write data to files. Conversions of integral data types to `string` types are also handled automatically, same as with `cout`.

Take the following example, which request the user's name and age and writes the corresponding data to a file:

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // File stream object
  ofstream output;
  output.open("user.txt");    // Default mode is ios::out

  if (!output) {
    cerr << "Could not open the file in write mode" << endl;
  }

  std::string name;
  cout << "Please enter your name: ";
  getline(cin, name);

  int age;
  cout << "Please enter your age: ";
  cin >> age;

  // Writing the data to a file
  output << name << " is " << age << " years of age." << endl;

  // Close the file
  output.close();
  
  return 0;
}
```

## Reading from a file

Reading from `cin` is accomplished using the **stream extraction operator** `>>`. Since `ifstream` is a derived class of `istream`, the same operator can be used to read data from files. Conversions of integral data types to `string` types are also handled automatically, same as with `cin`.

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // File stream object
  ifstream input;
  input.open("values.txt");    // Default mode is ios::in

  if (!input) {
    cerr << "Could not open the file in reading mode" << endl;
  }

  // Read a single integers from the file
  int value;
  input >> value;
  cout << "Read from the file: " << value << endl;

  // Close the file
  input.close();

  return 0;
}
```

Just create a file and put a number inside of it.

To read multiple values from a file, one can check the state of the file stream object and keep reading as long as all goes well or the end of the file has not been reached.

```c++
// Read some integers from the file
int value;
while (input >> value) {
  cout << "Read from the file: " << value << endl;
}
```

### Reading Lines

To read full lines from a file, one can also make use of the `getline()` function. Instead of passing the `cin` object, all one needs to do is pass the input file stream object.

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // File stream object
  ifstream input;
  input.open("lines.txt");    // Default mode is ios::in

  if (!input) {
    cerr << "Could not open the file in reading mode" << endl;
  }

  // Read some integers from the file
  std::string line;
  while (getline(input, line)) {
    cout << "Read from the file: " << line << endl;
  }

  // Close the file
  input.close();

  return 0;
}
```

## State Flags

Things can go wrong when reading data from files. The end of the file can be reached, the format of the data is not as expected, there is not enough space left to write to the data, ...

To check the current state of the file stream object, the following methods are provided (they all return a `bool`):

* `bad()`: Returns `true` if an operation fails. For example, in the case that we try to write to a file that is not open for writing or if the device where we try to write has no space left.
* `fail()`: Returns `true` in the same cases as `bad()`, but also in the case that a **format error** happens, like when an alphabetical character is extracted when we are trying to read an integer number.
* `eof()`: Returns `true` if a file open for reading has reached the end.
* `good()`: It is the most generic state flag: it returns `false` in the same cases in which calling any of the previous functions would return `true`. Note that good and bad are not exact opposites (good checks more state flags at once).

The `clear()` method can be used to reset the state flags.

<!-- ## Binary Mode -->

<!-- TODO -->