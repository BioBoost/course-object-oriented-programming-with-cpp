

<!-- down vote
General rule:

when you use new or new [], you allocate on heap, in other case you allocate on stack.
every time you use new you should use delete (explicitly or not)
every time you use new[] you should use delete[] (explicitly or not)
The next code is UB since you use one new[] and 101 delete. Use one delete[].


Vector** v = new Vector*[100];
for (int i = 0; i < 100; ++i)
{
   delete(v[i]);
}
delete(v);
-->

<!-- Variables are stored:

Source: http://stackoverflow.com/questions/230584/where-are-variables-in-c-stored

on the stack, if they're auto-matic function-local variables
on the heap, if they're allocated with new or malloc, etc. (details of what it means to say "a variable is stored in the heap" in the comments)
in a per-process data area if they are global or static
This is all in RAM, of course. Caching is transparent to userspace processes, though it may visibily affect performance.

Compilers may optimize code to store variables in registers. This is highly compiler and code-dependent, but good compilers will do so aggressively.





5	 	
Actually, variables are not stored in the heap. You may have a variable that points to something in the heap, but the variable itself will be in a register, on a stack, or be statically allocated. – Kristopher Johnson Oct 23 '08 at 17:29

Kristopher, a valid point. In the C++ definition, the variable is the pointer, not the pointed-to array, so you're right. – Dan Lenski Oct 23 '08 at 19:12

Upvoted but you should remove point 2. – Joe Jan 13 '10 at 13:26

Note that storing variables in registers is highly platform-dependent also. Different architectures have different numbers of registers, and not all registers are the same in all architectures. – David Thornley Jan 15 '10 at 15:14
3	 	
@Kristopher: well, your statement is not entirely true. member variables of class ojects are stored/allocated on heap. – Chethan Jul 7 '11 at 14:59


-->
