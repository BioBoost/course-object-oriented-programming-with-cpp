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