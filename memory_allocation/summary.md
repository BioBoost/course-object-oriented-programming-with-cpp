# Summary

[Source: http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap]

Stack:

* Stored in computer RAM just like the heap.
* Variables created on the stack will go out of scope and automatically deallocated.
* Much faster to allocate in comparison to objects on the heap.
* Implemented with an actual stack data structure.
* Stores local data, return addresses, used for parameter passing
* Can have a stack overflow when too much of the stack is used. (mostly from infinite (or too much) recursion, very large allocations)
* Data created on the stack can be used without pointers.
* You would use the stack if you know exactly how much data you need to allocate before compile time and it is not too big.
* Usually has a maximum size already determined when your program starts


Heap:

* Stored in computer RAM just like the stack.
* In C++, variables on the heap must be destroyed manually and never fall out of scope. The data is freed with delete or delete[]
* Slower to allocate in comparison to variables on the stack.
* Used on demand to allocate a block of data for use by the program.
* Can have fragmentation when there are a lot of allocations and deallocations
* In C++, data created on the heap will be pointed to by pointers and allocated with new.
* Can have allocation failures if too big of a buffer is requested to be allocated.
* You would use the heap if you don't know exactly how much data you will need at run time or if you need to allocate a lot of data.
* Responsible for memory leaks


```c++
int foo()
{
  char *pBuffer; // nothing allocated yet (excluding the pointer itself, which is allocated on the stack).
  bool b = true; // Allocated on the stack.
  if(b)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
    pBuffer = new char[500];

   } // buffer is deallocated here, pBuffer is not
} // oops there's a memory leak, I should have called delete[] pBuffer;
```
