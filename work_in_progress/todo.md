Creata a chapter UML inside the book OOT !!!!!!!!!!



## Enum inside class as private member


## constructor-initialization list

Should probable best be placed in inheritance chapter
We can also add this to chapter where we show example of composition.

Some semi-decent docs here: http://www.cprogramming.com/tutorial/initialization-lists-c++.html



> #### Info::De Morgan's Laws
>
> In some cases it can be useful to rewrite complex conditions using De Morgan's Laws (https://en.wikipedia.org/wiki/De_Morgan%27s_laws). Do take note that shorter not always implies more readable or less complex.

<!-- How to break here ? -->


CASTING!!!!!!!
Pointers to Pointers?







### Namespaces

## Declaration versus definition

[todo]

<!-- Declarations:

extern int y;
class Robot;
void Robot::fight(Robot r);


Definitions
int y;
int y = 3;    // + initialization
class Robot { ...... };
void Robot::fight(Robot r) { r.decreaseHealth() ..... } -->


## Difference function and method

[todo]

## Including Standard Libraries

[todo]

<!-- <string> is the C++ standard library string header file containing std::string and its friends. <string.h> is a different header, from the C standard library, which has functions for manipulating C strings (null-terminated strings) and other related functions.

The two are entirely different and unrelated. In C++ (as in C), a header file can have any extension. The C++ standard library headers have no extension; the C standard library headers have a .h extension.  .hpp or .hxx are also common.


Everything James said is true. It's also interesting that in updated standard C++, the C string file has been renamed to <cstring> - in fact all of the C standard library, when promoted to the C++ standard library, have been renamed with a 'c' prefix and no '.h' extension, i.e., cstdlib, cstdio, etc. It's supposed to be the case that the C functions are moved into the std namespace, as well. Many compilers continue to support <string.h>, et al., and not to put the C standard library in std::, but I believe they are not required to do either anymore. – jwismar May 10 '10 at 0:27

@jwismar: All implementations are required to provide both the <cname> and <name.h> headers; the <cname> headers, as you say, put all their non-macro names into namespace std, and the <name.h> headers put all their non-macro names into the global namespace. In many implementations, the <cname> headers also put their names into the global namespace; this is technically not allowed in C++03, but will be permitted in the forthcoming C++0x. – James McNellis May 10 '10 at 0:32 -->




<!-- ## Passing objects -->

<!-- ## Copy Constructors -->
