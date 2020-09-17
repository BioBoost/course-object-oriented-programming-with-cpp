---
description: needs to be done
---

# Input and Output

C++ uses a convenient abstraction called **streams** to perform input and output operations in sequential media such as the screen, the keyboard or a file. A stream is an entity where a program can either insert or extract characters to/from. There is no need to know details about the media associated to the stream or any of its internal specifications. All the programmer needs to know is that streams are a source/destination of characters, and that these characters are provided/accepted sequentially.

The standard library defines a handful of stream objects that can be used to access what are considered **the standard sources and destinations** of characters by the environment where the program runs.

| Stream | Description |
| --- | --- |
| `cin` | Standard Input Stream |
| `cout` | Standard Output Stream |
| `cerr` | Standard Error Stream |
| `clog` | Standard Logging Stream |

The 'c' in the name refers to "character", because `iostreams` map values to and from byte (`char`) representations.

Typically input comes from the keyboard through `cin`, and "normal" output is sent to the console through `cout`. Error messages or diagnostics are also sent to the screen but through `cerr`. C++ uses two output streams so that the user can, when desired, separate them with command line operators and send the two outputs to different destinations.

All output streams (`cout`, `cerr` and `clog`) work exactly the same way. Only their actual destination may be different.

`cin` is an instance of a class named `istream`, while `cout` and `cerr` are instances of of a class named `ostream`. All three instances or objects are stored in the standard library, which the linker searches while creating the final executable program.

## Standard Output Stream

In C++, output to the display console is done via `cout` and the stream insertion operator `<<`. The `<<` operator inserts the data that follows it into the stream that precedes it.

```cpp
cout << "Hello World" << endl;
```

::: output
<pre>
Hello World
</pre>
:::

The previous example makes use of the `endl` manipulator which inserts an end-of-line and flushes the output buffer.

Multiple items can be inserted into the `cout`stream one after another by chaining them with the insertion `<<` operator.

```cpp
cout << "Hello World" << endl
  << "My name is Nico De Witte" << endl
  << "I am " << 34 << " years of age at this moment" << endl;
```

::: output
<pre>
Hello World
My name is Nico De Witte
I am 34 years of age at this moment
</pre>
:::

While the previous examples demonstrated insertion of literals, its also perfectly possible to print variabel values to the terminal by inserting them into the stream.

```cpp
int myAge = 34;
double height = 1.86;

cout << "Hello, my name is " << "Nico De Witte" << endl;
cout << "I am " << myAge << " years of age at this moment" << endl;
cout << "BTW. I am about " << height << "m tall." << endl;
```

::: output
<pre>
Hello, my name is Nico De Witte
I am 34 years of age at this moment
BTW. I am about 1.86m tall.
</pre>
:::

Notice that the string literals are enclosed in double quotes `"`, while the variables and integral literals are not. The double quoting is what makes the difference; when the text is enclosed between them, the text is printed literally; when they are not, the text is interpreted as the identifier of a variable, and its value is printed instead.

Also notice that each line here is constructed using a separate `cout` statement in comparison to the previous example where the three lines were constructed using a single statement. There is no real difference in the end result and no preference towards one construct.

### Escape Characters

Escape characters are special characters than can be used inside a string. They always are prefixed with a backslash `\`. Most programming languages have them. The code below shows examples of all these techniques.

```cpp
cout << "There\tis\ta\ttab\tbetween\teach\tword\n" << endl;
cout << "You can also use quotes here but they need to be escaped:\n" << endl;
cout << "\t\"C makes it easy to shoot yourself in the foot;" << endl;
cout << "\tC++ makes it harder,\n"
        << "\tbut when you do it blows your whole leg off.\"" << endl;
cout << "\t\t\t\t- by Bjarne Stroustrup" << endl;
```

:::output
<pre>
There   is      a       tab     between each    word

You can also use quotes here but they need to be escaped:

        "C makes it easy to shoot yourself in the foot;
        C++ makes it harder,
        but when you do it blows your whole leg off."
                                - by Bjarne Stroustrup
</pre>
:::

The table below lists the most used escape sequences.

| Escape Sequence | Description |
| --- | --- |
| `\t` | Insert a tab in the text at this point. |
| `\b` | Insert a backspace in the text at this point. |
| `\n` | Insert a newline in the text at this point. |
| `\'` | Insert a single quote character in the text at this point. |
| `\"` | Insert a double quote character in the text at this point. |
| `\\` | Insert a backslash character in the text at this point. |

## Standard Input Stream

The `cin` object in C++ is an object of class `istream`. It is used to accept the input from the standard input device. In most program environments, the standard input is by default the keyboard.

The `cin` object is used together with the extraction operator `>>`. This operator is then followed by the variable where the extracted data is to be stored.

Take a look at a small example that requests the age of the user:

```cpp
cout << "Please enter your age: ";

unsigned int userAge;
cin >> userAge;

cout << "Great. I am also "
  << userAge << " years of age." << endl;
```

::: output
<pre>
Please enter your age: 19
Great. I am also 19 years of age.
</pre>
:::

:::::: question Question - Wrong Input

What happens when the user inputs something different than a number. For example a character `b` or a string `Hello`? Can you explain what happens? How can we detect this?

```cpp
cout << "Please enter a number: ";

int number;
cin >> number;
```

::: details Solution

Basically everything that the user inputs is read as a string of characters. This string is then converted to the desired type depending on the variable type to which the data is extracted (second operand of `>>`).

If the user inputs something different from an unsigned number here, `cin` will indicate an error by setting the `fail` flag. The state of this can be retrieved using `cin.fail()` which returns `true` or `false`. Do note that the application does not crash (some programming languages will generate an exception in this case).

This can be demonstrated using the following code snippet:

```cpp
cout << "Please enter a number: ";

int number;
cin >> number;

cout << "Failed? " << cin.fail() << endl;
```

:::
::::::

The extraction operator can actually be used more than once to accept multiple inputs as shown in the next example.

```cpp
cout << "Please enter two numbers: ";

int numberA;
int numberB;

cin >> numberA >> numberB;

cout << "Sum: " << (numberA + numberB) << endl;
```

### For Future Reference

The `cin` object can also be used with other methods. Some of the commonly used methods are:

* `cin.get()`: Read a single input character
* `cin.getline()`: Reads a stream of characters into the string buffer, It stops when the buffer is filled or when an end-of-line is detected.
* `cin.read()`: Read a number of bytes or until an end-of-line is detected from the stream into a buffer.
* `cin.ignore()`: Ignores a number of characters from the input stream.
* `cin.eof()`: Returns a nonzero value if the end-of-file (eof) is reached.

More info about these methods can be found at [http://www.cplusplus.com/reference/istream/istream/](http://www.cplusplus.com/reference/istream/istream/).

## Standard Error Stream

The standard error stream `cerr` is the default destination for error messages and other diagnostic warnings. Like `cout``, it is usually also directed by default to the text console (generally, on the screen).

Although in many cases both `cout` and `cerr` are associated with the same output device (like the console), applications may differentiate between what is sent to `cout` and what to `cerr` for the case that one of them is redirected. For example, regular output may be shown in the terminal, while error messages are logged to a file.

```cpp
cout << "This is normal output" << endl;
cerr << "This is an error" << endl;
```

::: output
<pre>
This is normal output
This is an error
</pre>
:::

Running the previous code does not allow us to differentiate between the output.

However if we run the binary as follows in (works both with PowerShell and bash), the error output can be redirected to a file:

```bash
./app 2>error.log
This is normal output
```

## Changing the Number System

Sometimes you may require numbers to be inputted or outputted using a different number system such as hexadecimal or octal. This can easily be achieved by setting the correct base using the different manipulators that are available in C++.

| Manipulator | Number System | Base Prefix |
| --- | --- | --- |
| `dec` | Switch stream to decimal base format | - |
| `hex` | Switch stream to hexadecimal base format | `0x` |
| `oct` | Switch stream to octal base format | `0` |

::: warning Warning - No Binary manipulator
Note that there is no manipulator for the binary system. Almost any type can however be easily converted to binary using the `bitset` library. More information about bitset can be found here: [https://en.cppreference.com/w/cpp/utility/bitset](https://en.cppreference.com/w/cpp/utility/bitset).
:::

Consider the following example that outputs an integer value in all three formats.

```cpp
int value = 15;

cout << "Hexadecimal: " << hex << value << endl;
cout << "Octal: " << oct << value << endl;
cout << "Decimal: " << dec << value << endl << endl;
```

::: output
<pre>
Hexadecimal: f
Octal: 17
Decimal: 15
</pre>
:::

Using `setfill` and `setw`, one can for example prefix the number with leading zero's. These manipulators can be used by including the `iomanip` header.

By default the number format prefix is not shown when outputting values. This can be altered with the `showbase` and `noshowbase` manipulators. The `showbase` manipulator can however give conflicts with other manipulators (such as `setfill` and `setw`) so it is often a better option to output this yourself.

:::::: kata Code Kata - Output Hexadecimal Value

Can you alter the next code snippet so the number is outputted in hexadecimal format, with a leading `0x` and a width of 4 hexadecimal digits? Note that this will require the `iomanip` library to be included (already done for you).

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int number = 23;
  cout << "Number in hex format: " << number << endl;

  return 0;
}
```

The expected output is:

::: output
<pre>
Number in hex format: 0x0017
</pre>
:::

::: details Solution

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int number = 23;

  cout << "Number in hex format: "
    << hex << "0x"
    << setfill('0') << setw(4) << number
    << endl;

  return 0;
}
```

:::
::::::

### Applied to Standard Input

The number format manipulators can also be applied the standard input stream `cin`. It will even allow the user to type the number with and without the base prefix.

```cpp
#include <iostream>

using namespace std;

int main() {
  int value = 0;

  cout << "Please enter a HEX value: ";
  cin >> hex >> value;

  cout << "The value in DEC format: ";
  cout << dec << value << endl;

  return 0;
}
```

::: output
<pre>
Please enter a HEX value: 0xAB
The value in DEC format: 171
</pre>
:::
