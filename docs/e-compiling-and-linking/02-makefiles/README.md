---
description: Compiling C++ applications using Makefiles.
---

# Makefiles

Compiling your source code files can be tedious, especially when you want to include several source files and have to type the compiling command everytime you want to do it. Well, I have news for you ... Your days of command line compiling are (mostly) over, because you will learn how to write basic Makefiles.

Makefiles are human readable special format files that together with the `make` utility will help you to automagically build and manage your projects.

The `Makefile` directs the `make` tool on how to compile and link a program. Some common action that need to be taken when using C/C++ as an example:

* When a C/C++ source file is changed, it must be recompiled.
* If a header file has changed, each C/C++ source file that includes the header file must be recompiled to be safe.
* Each compilation produces an object file corresponding to the source file. Finally, if any source file has been recompiled, all the object files, whether newly made or saved from previous compilations, must be linked together to produce the new executable program.

These instructions with their dependencies are specified in a `Makefile`. If none of the files that are prerequisites have been changed since the last time the program was compiled, no actions take place. For large software projects, using Makefiles can substantially reduce build times if only a few source files have changed.

## Basics of Makefiles

A makefile is based on a very simple concept. A makefile typically consists of many entries. Each entry has:

* a **target** (usually a file)
* the **dependencies** (files which the target depends on)
* and **commands to run**, based on the target and dependencies.

Let's look at a simple example.

```make
student.o: student.cpp
   g++ -Wall -c student.cpp
```

`-Wall` has already been explained but `-c` has not. It tells the compiler to compile the code into an object file and stop there. This allows us to compile all `.cpp` files into object files and later link them all together into a single executable file.

::: warning TABS
Please note that make depends heavily on indentation (a bit like python). This means that the commands of a target need to be prefixed with a single tab character, no more, no less. The tabs should also be tab characters and no spaces.
:::

The basic syntax of an entry looks like:

```make
<target>: [ <dependency > ]*
	[ <TAB> <command> <endl> ]+
```

As with other programming, we also like to make our makefiles as DRY (Don't Repeat Yourself) as possible. For this reason the compiler, the compiler flags and linker flags are often set as variables in the makefile, allowing them to be reused and changed quickly if needed.

Let's see an example for a simple *hello world* program with a single `main.cpp` file:

```make
# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=hello

$(EXECUTABLE): main.o
	$(CC) main.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
```

Notice how the compilation of the `main.cpp` file and the eventual linking of all object files (is this case only one, excluding libraries) is split into two targets.

Now to start the make process all you need to do is traverse to the directory with the `Makefile` in it and execute the `make` command with a target specified:

```bash
make hello
g++ -c -Wall main.cpp
g++ main.o -o hello
```

This should result in the following files:

```bash
hello  main.cpp  main.o  Makefile
```

::: tip Make for Windows
Make is automatically installed on Linux when you installed the `build-essential` package. For Windows, make can be downloaded at [http://gnuwin32.sourceforge.net/packages/make.htm](http://gnuwin32.sourceforge.net/packages/make.htm). Make sure to add make to the PATH of your user, typically `C:\Program Files (x86)\GnuWin32\bin`.
:::

Most makefiles will also include an 'all' target. This allows the compilation of the full project. The 'all' target is usually the first in the makefile, since if you just write `make` in command line, without specifying the target, it will build the first target. And you expect it to be 'all'.

Another frequent target is the 'clean' target. This removes both the executable and all intermediary files that were generated.

With both these targets added, the makefile becomes:

```make
# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=hello

all: $(EXECUTABLE)

$(EXECUTABLE): main.o
	$(CC) main.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o $(EXECUTABLE)
```

## A More Complex Hello World Example

Now what if your project contained more files than just a simple `main.cpp` file. This will be the case for most projects.

The makefile below shows how separate classes can be compiled using a makefile.

```make
# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=hello

all: $(EXECUTABLE)

# The executable depends on all the separate object files
$(EXECUTABLE): main.o robot.o
	$(CC) main.o robot.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

robot.o: lib/robot.cpp
	$(CC) $(CFLAGS) lib/robot.cpp

clean:
	rm -f *.o $(EXECUTABLE)
```

## A Generic Makefile

A more generic but a bit less readable makefile is shown next. It automatically compiles all `.cpp` files in a subdirectory `src` and places the final executable in a directory `bin`.  The only downside is that it **only works on Linux**.

```make
# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall -std=c++2a
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Linker flags
# LDFLAGS=

# Libraries
# LIBS=

# Name of app
APPNAME=hello
BINARY=${APPNAME}
SRCDIR=src
BUILDDIR=bin
INSTALLDIR=/opt/${APPNAME}
PATHDIR=/usr/local/bin

OBJS := $(patsubst %.cpp,%.o,$(shell find ${SRCDIR} -name '*.cpp'))

all: makebuildir ${BINARY}

${BINARY}: ${OBJS}
	${CC} ${LDFLAGS} -o ${BUILDDIR}/$@ ${OBJS} ${LIBS}

%.o : %.cpp
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -rf ${BUILDDIR}
	rm -f ${OBJS}

# Really basic install - needs improvement
install:
	mkdir -p ${INSTALLDIR}
	cp ${BUILDDIR}/${BINARY} ${INSTALLDIR}
	ln -sf ${INSTALLDIR}/${BINARY} ${PATHDIR}/${APPNAME}

makebuildir:
	mkdir -p ${BUILDDIR}
```
