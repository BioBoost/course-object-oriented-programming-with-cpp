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
from scratch we can use existing ones and extend or embed them with our classes. The main advantages of this
approach is that:
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

## A wargame as an example

Let us start based on an example game. Imagine you get the assignment to create a simple game
where a player can manage an army base, where they can build tanks and other gears of war. They can then use these to fight other players (could be computer controlled AI).

As an example we will take a closer look at the modeling of some possible classes in this game. As we are just starting out with this game, we start easy and only implement parts as needed.

To start of we create a *Tank* class and a *Soldier* class. The UML diagrams of both classes are depicted below.

![Basic Tank class](https://www.lucidchart.com/publicSegments/view/5b1b35dc-e10c-4d9e-8840-11c16162cb0e/image.png)

For the Tank class we define the properties *health*, *numberOfShells* and *gunCalibre*.

All attributes are initialized to default values inside the default constructor. Some setters are adding to allow the Tank to resupply and repair. Getters allow access to the attributes to be displayed in some sort of interface.

Since only two classes are available, two fight methods (overloading) are added so a Tank can fight a Tank and a Tank can fight a Soldier.

![Basic Soldier class](https://www.lucidchart.com/publicSegments/view/db282903-1557-40da-92c2-66d9d534523d/image.png)

For the Soldier class we define the properties *health* and *numberOfBullets*.

All attributes are initialized to default values inside the default constructor. Some setters are adding to allow the Soldier to resupply and heal. Again all attributes can be accessed via getters.

Two overloaded fight methods allow the Soldier to initiate a fight with another Soldier or Tank.

In both classes the *to_string()* is mainly for debugging and logging.

Even when your programming experience is still not that great, you might feel that there are a couple of things that feel wrong about these models. This will be fixed as we advance through this chapter. Some questions you need to ask yourself:
* Is this code DRY?
* What if we added other gears of wars? Or other types of soldier and tanks?
* What about the fight methods?

## Code always changes

Something to remember is that code evolves. It changes over time as things get added, removed or refactored. Static code will eventually become outdated and die. On top of that your boss, client, teacher, ... will never tell you the whole story. Once they get the first prototype, and they like it, there will always a "would it be possible to add a ..." moment. That is also why it is also more fun to program based on methodologies such as SCRUM and Agile as they take the fact of change into account.

So let's take the game example from the previous section as an example. You created the *Tank* and *Soldier* class after which your boss shows up and tells you to add an identifier to the Soldier and Tank classes to be able to save them in a database. This means you need to change both classes as shown in the following UML class diagrams.

![Tank class UML diagram with ID](https://www.lucidchart.com/publicSegments/view/078ea71e-561b-42c7-9bf7-d66f36dba785/image.png)

![Soldier class UML diagram with ID](https://www.lucidchart.com/publicSegments/view/3f3a9b0e-933f-450c-af25-669b4056024a/image.png)

Note that the id is not added as an argument to the constructor of the classes. This because of the assumption that most of the time the id will be generated based on the ones that are already taken. On top of the attribute a getter methods is also supplied for the id.

Notice that we had to change two classes to add an id attribute and a getter. We actually also need to change the implementation of the constructor to generate an id based on the ones already taken. And if we are not careful we might forget to change the `to_string()` implementation.

It should feel awkward to change two classes for a single change based on a single property. And what if we had like 10, 20 or a 100 sorts of army weapons. It would be a days work to add such a simple change to our game.

Let's be lazier but smarter programmers and take another approach to this problem.

## Introducing inheritance

The extension of the classes with an id can be easily solved (literally minutes, even with 100 different types of vehicles and soldier classes) if we had some sort of general class that held all the common properties and actions of all the things that can fight in our game. This is exactly what inheritance provides for us.

Inheritance allows a class to inherit (get) the properties and methods of another class. In other words, the **subclass** inherits the states and behaviors from the **base class**. The subclass is also called the **derived class** while the base class is also known as the **super-class**. The derived class can add its own additional attributes and methods. These additional attributes and methods differentiates the derived class from the base class.

It is also possible to change the implementation of certain methods in the base class, also known as **method overriding**.

A super-class can have any number of subclasses. While in java, a sublcass can have only one superclass, in C++ it is possible to inherit from multiple base classes, known as **multiple inheritance** (however not always a good idea or good practice).

So going back to our example we could create a `Entity` class and put all the common properties of `Tank` and `Soldier` in this class. The same can be done for the methods of the `Tank` and `Soldier` class. Do take note that the constructor of the `Entity` class can only be used to create a general `Entity` object and does not know of the `Tank` and `Soldier` classes and their more specific properties such as *gunCalibre*.

![UML class diagram of Tank and Soldier inheriting from Entity](https://www.lucidchart.com/publicSegments/view/fd3142ee-d6f4-4f19-a7e3-f29a1ef990cf/image.png)

In an UML class diagram inheritance is depicted by drawing a closed arrow from the subclass to the base class as shown in the diagram above.

Entity has two constructors (constructor overloading). One default (no arguments) and one that takes *health* as an argument. This second one was added because one could image that a tank has a lot more health than a soldier. So when a Tank object is constructed, we could use the constructor initialization list to call the second constructor of Entity.

We also provided an implementation for the `to_string()` method.

Now the derived class `Tank` can be refactored to a simple class with only the specific `numberOfShells` and `gunCalibre` attributes, a constructor, some getters, some setters and a more specific implementation of `to_string()`. The *fight* methods cannot be refactored yet and need to stay inside the specific classes. More on this later.

A similar refactor needs to be done to the `Soldier` class.

While a Soldier had a `numberOfBullets` and Tank a `numberOfShells` both are actually the same. However it feels incorrect to refactor this to `Entity` as this would mean that every Entity will have some sort of ballistic weapon with shells. As Agile programmers, we await a better solution.

## Private, protected and public members

Very important to know is that a derived class inherits all the members of its base class, even the private ones, However it cannot access the **private members** of its baseclass. This means that the Tank class cannot directly access the id and health of Entity. For this reason getters are provided for these attributes.

Since a Tank and Soldier both need to be able to change their health, a setter needs to be added to the Entity class. As a `heal()` method is already available, a `damage()` method was added to provide the opposite action of healing.

Another solution would be to make the attributes protected. This would allow subclasses to access the attributes directly, while still keeping them inaccessible for outside classes. This can be a good solution in same cases, but most of the time it is cleaner to use accessors.

Do note that you can also make methods protected, allowing subclasses to use them, but not outside classes.

## Is-a relationships

The superclass and subclass have an **"is-a"** relationship between them. This means we can state that `Tank` is-an `Entity` and `Soldier` is-an `Entity` if we take the previous example.

If you cannot logically state that 'subclass' is-a 'superclass' than you made a mistake to make 'subclass' inherit from 'superclass'. An example of this would be the case when you would create a subclass `Cement` from `Food` because `Cement` also has an expiration date. This may seem DRY but it is illogical. You can't state that `Cement` is-a `Food`.

Let's see some examples:

If we needed to model both a *Bus* class and a *Car* class it makes perfect sense to create a *Vehicle* class and make both *Bus* and *Car* inherit from them. It's perfectly valid to state that
* a Bus is a Vehicle
* a Car is a Vehicle

However it would of been illogical to make *Bus* inherit from *Car* or vice versa as it would not have been logical to state that:
* a Bus is a Car
* a Car is a Bus

## Inheritance in C++

To implement inheritance in C++ all you need is a baseclass and a subclass. The subclass needs to extend the baseclass and this can be accomplished by using the syntax shown below:

```c++
class <subclass> : public <baseclass>
  // Implementation
}
```

Note that *extending* the baseclass is exactly what we are doing when implementing inheritance. We take a general class and add something to it: data, behavior or both.








## Poly:

Boss again: we need to be able to draw all items

<!-- ## Composition versus Inheritance


What to use when -->
