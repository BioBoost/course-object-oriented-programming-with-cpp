---
description: needs to be done
---

# Input Output

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

In C++, output to the display console is done via "cout" and the stream insertion operator `<<`. The `<<` operator inserts the data that follows it into the stream that precedes it.

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
