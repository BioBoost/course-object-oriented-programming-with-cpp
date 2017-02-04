<!-- toc -->

# Its all about Objects

This chapter will give a quick introduction in the concepts of object oriented programming (OOP). While not explicitly necessary, this chapter does assume you have some basic knowledge about OOP and programming. If not, please review the GitBook course "Object Oriented Programming with Java" which can be found at https://bioboost.gitbooks.io/object-oriented-programming-using-java/content/.

While this chapter serves as an introduction to the course, it will also provide an overview of the concepts thought in this course. Most concepts given in this chapter will be discussed in detail further in the course. So this chapter will provide the big picture of OOP and connect all the different chapters. If you do not understand some of the parts in this chapter, do not panic, keep reading and return here after advancing further in the book.

## Abstracting Things

Abstracting things allows us to establishing a level of complexity on which a person interacts with the system. The more complex details are hidden below the current level. The user works with an idealized interface (usually well defined) and can add additional levels of functionality that would otherwise be too complex to handle.

> The essence of abstractions is preserving information that is relevant in a given context, and forgetting information that is irrelevant in that context.
>
> John V. Guttag (2013-01-18)

Take for example a programmer that is developing a calculator application. This programmer might not be interested in the way numbers are represented in the underlying hardware (e.g. whether they're 16 bit or 32 bit integers). The boundary where those details have been suppressed, we can state that they have been abstracted away. The programmer now just has numbers with which he can work.

All programming languages provide abstractions. The actual quality of the abstractions will determine the complexity of the problem you are able to solve. Try writing an MMORPG game using nothing but assembler.

In fact assembly language is an abstraction for machine code which is an abstraction of the actual hardware of a computer system.

![Assembler is an abstraction of Machine Code [^1]](img/assembler_abstraction.jpg)

[^1]: Source http://www.androidauthority.com/assembly-language-and-machine-code-678230/

Many imperative languages that followed (such as Fortran, C, Pascal, ...) were another level of abstraction introduced on top of the assembly language.

![Multiple Layers of Abstraction](https://www.lucidchart.com/publicSegments/view/9795cc73-acd7-478a-a1e0-3bc66b19496c/image.png)

So called imperative languages are a big improvement over the low-level assembly language. They do however still require that the programmer thinks in terms of the structure of the computer rather than in terms of the structure of the problem.

Think for example about a simple program that can perform several operations on triangles. A simple C implementation may keep track of all the coordinates (x and y) of the triangle corners using arrays. The operations would be implemented using functions that take the necessary parameters or even act on global data and return a result or change the global data. Here we are storing data in arrays of a certain type and defining functions that can operate on that particular data.

The programmer must establish the association between the machine model (**the solution space**, the place where the problem is being modelled and solved) and the model of the problem (**the problem space**, the place where the problem exists).

![Problem Space versus Solution Space](img/problem_solution_space.png)

The effort to make this mapping between the solution and problem space creates programs that are difficult write and expensive to maintain.

The alternative to modeling the machine is to *model the problem* you are trying to solve. This was introduced by languages such as:
* LISP: All problems are ultimately lists
* APL: All problems are algorithmic
* Prolog: All problems are chains of decisions

These languages chose a particular views of the world of problems. While they are good solutions to particular classes of problems, they do become awkward when you step outside their domain.

The object oriented approach takes it all a step further by given the programmer the ability to represent the elements from the problem space in the solution space. This representation is general enough so that it is not constrained to any particular type of problem. Elements in the problem space are represented in the solution space as **objects**.

This also allows the programmer to express the solution using the lingo of the problem space by adding types of objects. In other words, reading the code that describes the solution uses the same words that also express the problem. Of course a programmer will also be able to create objects that are not directly related to the problem space.

Coming back to the example of the triangle translation and rotation problem, we would actually be able to create a Triangle type. By creating objects of this type we would be able to create a solution with objects representing the elements of the problem, rather than in terms of the computer where the solution will run.

However, a connection does still exist between the solution and the computer. This in the analogy that an object can be seen as a small computer with state and actions it can be asked to perform. This is an analogy which can be extended to the real world where objects have characteristics and behavior.

Alan Kay, a renowned computer scientist, listed the five characteristics of Smalltalk, the first successful object oriented programming language and one of the languages on which C++ is based. They summarize the characteristics that represent a pure approach to object oriented programming:

1. **Everything is an Object.** An object contains both data and behavior (this is  also knows as *encapsulation*). It keeps state and can satisfy outside requests by performing operations on itself. You can basically create objects of any conceptual component in the problem you are trying to solve (people, buildings, lists, records, ...).

2. **A program is a bunch of objects telling each other what to do by sending messages.** To make a request of an object, a message needs to be send to it. This will call a certain method of that particular object.

3. **Each object has its own memory made up of other objects.** Think of this as creating another type of object by packaging together other objects, this will later be seen as what is called *composition*. This allows us to hide complexity behind the simplicity of objects. In other words, objects allows to create new levels of abstraction.

4. **Every object has a type.** Or in OOP lingo, each object is an *instance* of a *class* in which class actually is a synonym of type. A class defines what messages can be send to the objects of that particular class.

5. **All objects of a particular type can receive the same messages.** This is a bit more complex than it sounds. Basically, an object of type *circle* is also an object of type *shape*, meaning that a circle object will be guaranteed to also accept shape messages. This is where *polymorphism* comes into play: meaning you can write code that talks to shapes and automatically handles other objects that also fit the description of shapes, such as circles. This *substitutability* forms one of the most powerful concepts of OOP.

## The interface of an Object

Aristotle was one of the first to study the concept of *type*. He spoke of *the class of fishes and the class of birds*. The idea is that each object is unique (because of their state) but is also part of a class of objects that share characteristics and behavior.

The fundamental keyword *class* was first used in Simula-67, the first object oriented programming language, and allowed for the creation of new types in the program.

The number of objects that can be instantiated from a class is only limited by the memory available in the system the program is running on. Each object has its own state (contained within its data members) and identity.

These objects can then be manipulated (by sending them messages) as if they were the elements from the problem that is being solved.

Objects satisfy the requests that are being send to them (ex. draw something on the screen, complete a bank transaction, download a file from the Internet, ...). In practice, a *contract* is created between the creator of the class and the user of the class, which defines what messages can be send to a certain class of objects. This contract is realized by the **public interface** of the objects. In other words the interface of a class establishes what requests you can make to its objects.

There must however be code somewhere to satisfy the requests. This along with the hidden data comprises the *implementation* of the class.

So summarized: a type (class) has a method associated with each the possible requests (the interface) that can be made to the objects of that class. When a message is send to an object, the corresponding method is called, and the object figures out what to by executing the code that forms the implementation of that method.

Lets take a look at a simple example such as a light bulb. It might be represented as shown below.

![A UML class diagram of a light bulb](https://www.lucidchart.com/publicSegments/view/c41c9a49-31a1-48ba-8552-00a06f6da300/image.png)

The diagram above follows the UML standard (Unified Modeling Language). The diagram consists of three parts:

* The top box shows the **name of the class**. In this case Light. Note how the classname begins with a capital letter and is in the singular form.
* Below that is a list of **attributes**. They contain the characteristics or state of the objects that will be created from the class.
* Last is the box with the **methods** that are available for the class.

Except for the name of the class, the other parts of the diagram are optional and are only added when useful.

The minus '-' sign in front of the attributes state that these are private and cannot be accessed from outside the objects themselves. The plus '+' sign in front of the methods states that they are public and can be called by other type of objects.

Note that the interface of the class only consists of the public portions of the methods and attributes. The methods and attributes that are private are not considered part of the **public interface** of the class. Because of this, some programmers will leave out the private parts of the class from the UML class diagram, as they are considered private details to the actual implementation of the class

### Creating Objects in C++

Once a class is defined, objects can be instantiated from the class. This is done as shown in the code example below. First the type is specified followed by a arbitrary name chosen by the programmer.

```c++

// Create an object of type Light
Light bedroomLight;

// Send message to turn it on (method call)
bedroomLight.on();
```

The code sample also shows how a message can be send to the light bulb to request it to be turned on. This is was is what is called calling a method of that object. As a user of the object you need to specify the name that was given to the object (`bedroomLight` in this case), followed by the name of the method to call.

## Hide your Implementation

When taking a look at the object concept two parties of programmers can be distinguished. On one side is the *class creator* that defines the class and takes care of its implementation. He creates new data types and maintains the internal workings of those classes. On the other side is the *client programmer*, the class consumer, who uses the class and instantiates objects from it.

The client programmers goal is to collect a toolbox of helpful classes (libraries) and use these to develop a solution to his problem as fast as possible and with the least effort.

The class creators goal is to build a class that only exposes what is necessary and hide everything else.

Both these programmers can be the same physical person, however even in this case it is helpful to make a logical distinction between the user and the creator of a class.

Why hide as much as possible? Several reasons:
* If it is hidden, the client programmer can't use it and if he can't use it, he can't misuse it either. The hidden parts of a class represent the tender insides of the implementation and could be easily corrupted if made public.
* Hiding implementation details also allows the class creator to make changes to the hidden portions without having to worry about breaking contract with the client programmer. If you ever decide to for example optimize your implementation you would not need to worry about the people using your library.
* The simpler the public interface of the class, the more programmers will use.

In any case, in any relationship it is important to have boundaries that are respected by all involved parties. When creating libraries, you actually establish a relationship between yourself and the client programmer. That is why we often state that the public interface is a representation of the contract between a class creator and his clients.

**Access control** prevents client programmers to keep hands off portions they shouldn't touch. Hiding the internals that are not part of the interface that users need, is actually a service to the users. Client programmers can easily see what's important for them and ignore the rest.

C++ uses three keywords called **access modifiers** to set those boundaries in a class:
* `public`: Available to everyone ('+' sign in UML)
* `private`: Only available inside the class itself ('-' sign in UML)
* `protected`: Similar to private, except that subclasses can access these members ('#' sign in UML)

Trying to access members that are not available to you, will result in compile-time errors.

![Hiding implementation - Important for both client and creator[^2]](img/hiding_implementation.gif)

[^2]: Source http://javarevisited.blogspot.be/2010/10/abstraction-in-java.html

## Reusing implementation
