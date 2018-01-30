## Hello World in C++

Let's jump right in and create our "Hello World" application in C++.

Open your favorite editor or IDE and create a new C++ application. Place the code below in a file called `main.cpp`. This file often serves as the entry point of the application containing the `main` function which contains the code to execute when the application is started. Compile and execute the application.

```c++
#include <iostream>

using namespace std;

int main(void) {
    cout << "Hello world!" << endl;
    return 0;
}
```

If you need more information on how to setup your development environment than please take a look at [https://www.gitbook.com/book/sillevl/software-installation-guide](https://www.gitbook.com/book/sillevl/software-installation-guide) at the section "Visual Studio Code".

As a compiler you can make use of MinGW which stands for "Minimalist GNU for Windows", which is a native Windows port of the GNU Compiler Collection (GCC).

> #### Info::"GNU"
>
> GNU is an operating system and an extensive collection of computer software. GNU is composed wholly of free software, most of which is licensed under GNU's own GPL (General Purpose License).
>
> GNU is a recursive acronym for "GNU's Not Unix!", chosen because GNU's design is Unix-like, but differs from Unix by being free software and containing no Unix code. The GNU project includes an operating system kernel, GNU HURD, which was the original focus of the Free Software Foundation (FSF). However, non-GNU kernels, most famously Linux, can also be used with GNU software; and since the kernel is the least mature part of GNU, this is how it is usually used. The combination of GNU software and the Linux kernel is commonly known as Linux (or less frequently GNU/Linux).
