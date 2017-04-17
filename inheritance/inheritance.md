<!-- toc -->

# Inheritance

One of the best features of an object oriented programming language are the abilities for code reuse.
Programmers are generally lazy in the way that they hate to repeat themselves or do things twice.

> #### Warning::Copy paste is not reuse
>
> For all you copy-paste fanatics out there, copying code from one place to another
> is not considered code reuse. If the original code is ever extended, changed or corrected,
> chances are that you will forget to alter one of the copies.

As with most in an OOP language, the solution revolves around the class. Instead of creating classes
from scratch we can use existing ones an extend or embed them with our classes. The main advantages of this
approach are that:
* we reuse code that has been tested and debugged
* code is not duplicated
* classes can be kept small and thus more manageable

The trick is to use the classes without soiling the existing code.
There are two ways to accomplish this and one has already been discussed in this course.

The first approach is to create objects of the already existing class inside the class you are developing.
This is called **composition** as the new class is composed of objects of existing classes.

The second approach is to create a new class as a subtype of an existing class. You literally
take the form of an existing class and extend it, and this without modifying the existing class.
This is called **Inheritance** and it is one of the cornerstones of an object oriented programming language.


<!-- ## Composition versus Inheritance


What to use when -->
