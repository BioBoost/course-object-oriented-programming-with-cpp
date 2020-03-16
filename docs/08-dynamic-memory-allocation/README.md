---
description: Dynamic memory allocation allows our application to request memory on the fly.
title: 08 - Dynamic Memory Allocation
---

# Chapter 08 - Dynamic Memory Allocation

Basically when executing an application on any machine - be it a server, a desktop or an embedded system - the application requires at least a processing unit (CPU) and memory.

C++ will store data in different places based on how and where in code they were created. The programmer is given the choice based on efficiency and necessity. For maximum runtime speed, the storage and lifetime can be determined by the programmer while the program is being written.

## Memory Segments

The memory that is a assigned to an application when it is being run is typically divided in different regions called memory segments:

* The **code segment**, also called the text segment, is where the compiled binary resides in memory. This is typically a read-only memory segment.
* The **bss segment**, hosts zero-initialized global and static variables.
* The **data segment**, hosts initialized global and static variables.
* The **heap** is used to provide memory at runtime when the application requests dynamically allocated memory.
* The stack, tracks function arguments, local variables and other function-related information.
