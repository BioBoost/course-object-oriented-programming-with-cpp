<!-- toc -->

# Composition / Aggregation

One of the most used mechanisms to reuse code is by using composition and aggregation. By using composition we build classes that consist of other objects. Think of this as creating another type of object by packaging together other objects.

Composition also allows us to hide complexity behind the simplicity of objects. In other words, objects allow us to create new levels of abstraction.

Composition/Aggregation comes with a great deal of flexibility. Member objects of the new class can be made private, making them inaccessible to client programmers. This means that they can be changes without disturbing existing client code. This can even be done at runtime, to dynamically change the behavior of your program. This cannot be done using inheritance since the compiler must place compile-time restrictions on classes created with inheritance.

Because inheritance is one of the main pillars of object oriented design, it is often over-estimated and over-used. When used wrongly, it can result in awkward and overly-complicated designs. A good practice is to look at aggregation/composition first when creating new classes as it is simpler and more flexible.

## Composition or aggregation

While in most cases aggregation is synonym with composition, there is a subtle difference.

**Aggregation** is a specialized form of association where all object have their own lifecycle but there is ownership. This represents "whole-part or a-part-of" relationship. In UML this is represented by a hollow diamond followed by a line.

Let's take an example of a relationship between Department and Teacher. A Teacher may belong to multiple departments. Hence Teacher is a part of a Department. But if we delete a Department object, no Teacher objects will be destroyed.

![Aggregation relationship between Department and Teacher](https://www.lucidchart.com/publicSegments/view/9aec84f5-cb64-4dc3-81ab-d444b1360df6/image.png)

**Composition** is a specialized form of aggregation. It is a strong type of aggregation. In this relationship child objects do not have their own lifecycle. If a parent object is destroyed, all its child objects will also be destroyed. This represents a "death-relationship". In UML this is represented by a solid diamond followed by a line.

Let's take an example of relationship between a House and a Room. House can contain multiple rooms, but there is no independent life of Room and a Room cannot belong to two different houses. If we destroy the house, the rooms will automatically be destroyed too.

![Composition relationship between House and Room](https://www.lucidchart.com/publicSegments/view/3956209b-7d39-4c99-ba49-e476ec700b97/image.png)

While a clear distinction is made here between aggregation and composition, it is not always done so in practice. In practice, one does often speak of composition even if he/she were to mean aggregation. As a result this course may also use the word composition where aggregation is meant. Of course in cases where a clear distinction is needed, the correct term will be used.

## Creating new Classes Through Composition

You probable have already been using composition without realizing it. Consider the example below of a class Product that might be used in an online web shop as a model for products that are sold.

![Model of a Product](https://www.lucidchart.com/publicSegments/view/0f2c96fa-b37a-4f60-bc2b-a34b8ce6de3f/image.png)

While we will almost never include them as such, the `name` and `description` are actually instances of a class too, namely `std::string`. So in other words `Product` is already an basic example of composition.

![Model of a Product with Composition](https://www.lucidchart.com/publicSegments/view/599c7063-4fe3-47a8-b2ae-920c5ae93404/image.png)

When composing objects of other objects, the *sub objects* are normally made private. This hides implementation and allows the designer of the class to change the implementation if needed.

Consider the following example where a `DisplayDevice` is modelled as a composition of an `LCD` objects, which interacts with actual hardware, and `Color` objects that define the color of the letters and background.

![A Display Device](https://www.lucidchart.com/publicSegments/view/56b665f8-bc3c-4339-bc16-b7ad09439482/image.png)

By hiding the `LCD` object inside the `DisplayDevice` we hide the complexity of the hardware dependent class. This class may have methods for setting and resetting pixels, for changing hardware timings, for drawing rectangles, circles, and so on. We hide all that and we only expose the ability to show some text, through `display(text:string)`, and display a bitmap, through `display(image:Bitmap)`. This keeps our `DisplayDevice` simple and very user friendly.

## How Objects Sprout to Life

Whenever an object of a class is instantiated, its constructor is called. This however is not all that happens:
* the **parent constructor** is also called if the class inherits from another class
* also all the constructors of all the composed objects are called

Of course if the base class inherits from another class or the subobjects do, or contain other objects, this process repeats itself within those objects.

Let's take a look at a more complex example of a `MotorCycle`. It inherits from a `MotorizedVehicle` class which in turn inherits from a `TransportationDevice`. A `MotorizedVehicle` contains a `Motor` and a `MotorCycle` is composed of a `Motor` (thorugh inheritance), two `Wheel`s, a `GearBox` and a `Battery`.

![A Motorcycle Model](https://www.lucidchart.com/publicSegments/view/1eea9455-686b-4691-b71c-e8ddbac4f66e/image.png)

It is very important to know which constructors are called and at what time. Let's use the following implementation to illustrate which constructors are called when. Note that the implementation is shown below each class to make the code shorter.


[include](code/motorcycle_default_constructors/include/motor.h)

[include](code/motorcycle_default_constructors/src/motor.cpp)


[include](code/motorcycle_default_constructors/include/wheel.h)

[include](code/motorcycle_default_constructors/src/wheel.cpp)


[include](code/motorcycle_default_constructors/include/gearbox.h)

[include](code/motorcycle_default_constructors/src/gearbox.cpp)


[include](code/motorcycle_default_constructors/include/battery.h)

[include](code/motorcycle_default_constructors/src/battery.cpp)


[include](code/motorcycle_default_constructors/include/transportation_device.h)

[include](code/motorcycle_default_constructors/src/transportation_device.cpp)


[include](code/motorcycle_default_constructors/include/motorized_vehicle.h)

[include](code/motorcycle_default_constructors/src/motorized_vehicle.cpp)


[include](code/motorcycle_default_constructors/include/motorcycle.h)

[include](code/motorcycle_default_constructors/src/motorcycle.cpp)


The main program could be as simple as:

[include](code/motorcycle_default_constructors/main.cpp)

This would output:

```text
Constructing TransportationDevice
Constructing Motor
Constructing MotorizedVehicle
Constructing Wheel
Constructing Wheel
Constructing GearBox
Constructing Battery
Constructing Motorcycle
```

So basically, when constructing an object of a class the default constructor of its baseclass is called first. In turn if this class is also inheriting from another class, that baseclass default constructor is called first. Once the topclass is reached the constructors of the composed objects are called. Taking into account that also these can inherit from a baseclass. Once the object of the topclass is constructed, we traverse back toward the actual class object being constructed, under way constructing the composed objects of the baseclasses being traversed.

Important to think about is:
* **Why are the constructors of the composed objects invoked before the actual constructor of the composing object ?** Simple, because those objects should be ready and in a valid state for the composing object to use it when it is constructed. For example: the MotorCycle may want to change the battery voltage to a different level in its constructor.
* **Why are the constructors of the parent class invoked before the constructor of the child class ? ** Because each class should initialize the things that belong to it, not things that belong to other classes. So a child class should hand off the work of constructing the portion of it that belongs to the parent class. Second, the child class may depend on these fields when initializing its own fields; therefore, the constructor needs to be called before the child class's constructor runs.

![A Motorcycle Model - Constructors](https://www.lucidchart.com/publicSegments/view/8ea7fc2f-058f-41d3-82db-2ef5b9951153/image.png)

## Constructor Initialization List

By default, the constructors invoked are the **default** ("no-argument") constructors. Moreover, all of these constructors are called before the class's own constructor is called.

But what if we do not want the default constructor to be invoked, or what if the composed object classes have no default constructors ? In that case we need to be able to tell the compiler to execute a particular constructor when initializing the objects. This can be achieved using the **constructor initialization list**.

A constructor initialization list immediately follows the constructor's signature, separated by a colon `:`

```c++
#pragma once
#include <string>
class Bar {
    private:
        std::string name;

    public:
        Bar(std::string name);
};
```

```c++
#include "bar.h"
#include <iostream>
Bar::Bar(std::string name) {
    this->name = name;
    cout << "Bar: Name = " << this->name << std::endl;
}
```

A class `Foo` that inherits from `Bar`, where a constructor initialization list is used to invoke a non-default constructor of it's baseclass.

```c++
#pragma once
#include "bar.h"
class Foo : public Bar {

    private:
        std::string description;

    public:
        Foo(std::string name, std::string description);
};
```
```c++
#include "foo.h"
#include <iostream>
Foo::Foo(std::string name, std::string description)
    : Bar(name) {
    this->description = description;
    cout << "Foo: Description = " << this->description << std::endl;
}
```

Note that to call a particular parent class constructor, you just need to use the name of the class (it's as though you're making a function call to the constructor).

An example main could look like this:
```c++
#include "foo.h"

int main() {
    Foo foo("Foo the Great", "What can I say, Foo rules ...");
}
```

Output:
```text
Bar: Name = Foo the Great
Foo: Description = What can I say, Foo rules ...
```

But what if we need to call a different constructor for an attribute of our class when our objects are composed of other objects. In that case we can again use the constructor initialization list, but instead of the classname we use the name of the attribute followed with an argument list.

Let's for example take a television class that contains a powersupply that can convert any input voltage to any output voltage. We keep it simple and just implement the constructors to see what happens when the objects are instantiated.

[include](code/composition_non_default_constructors/include/power_supply.h)

[include](code/composition_non_default_constructors/src/power_supply.cpp)

 Since the `PowerSupply` class has no default constructor, the `Television` class needs to use the constructor initialization list to call a constructor of `PowerSupply`. Note that it is the name of the attribute that is used and not the name of the class. Otherwise if multiple attributes of the same class would be available we would not be able to differentiate between them.

[include](code/composition_non_default_constructors/include/television.h)

[include](code/composition_non_default_constructors/src/television.cpp)

A example program can be as simple as:

[include](code/composition_non_default_constructors/main.cpp)

Which would result in the output:

```text
Constructing PowerSupply: Input = 220 Output = 12
Constructing Television
```

## A More Complex Example

Let's recap on the Motorcycle example and add some none-default constructors.

![A Motorcycle with non-default constructors](https://www.lucidchart.com/publicSegments/view/3b9f34ae-bbfa-4d4a-b0cf-0d3a41622285/image.png)

This changes the implementation as follows:

[include](code/motorcycle_non_default_constructors/include/motor.h)

[include](code/motorcycle_non_default_constructors/src/motor.cpp)


[include](code/motorcycle_non_default_constructors/include/wheel.h)

[include](code/motorcycle_non_default_constructors/src/wheel.cpp)


[include](code/motorcycle_non_default_constructors/include/gearbox.h)

[include](code/motorcycle_non_default_constructors/src/gearbox.cpp)


[include](code/motorcycle_non_default_constructors/include/battery.h)

[include](code/motorcycle_non_default_constructors/src/battery.cpp)


[include](code/motorcycle_non_default_constructors/include/transportation_device.h)

[include](code/motorcycle_non_default_constructors/src/transportation_device.cpp)


[include](code/motorcycle_non_default_constructors/include/motorized_vehicle.h)

[include](code/motorcycle_non_default_constructors/src/motorized_vehicle.cpp)


[include](code/motorcycle_non_default_constructors/include/motorcycle.h)

[include](code/motorcycle_non_default_constructors/src/motorcycle.cpp)


The main program then would need to change too.

[include](code/motorcycle_non_default_constructors/main.cpp)

This would output:

```text
Constructing TransportationDevice: Kawasaki VN800
Constructing Motor with 2 cilinders
Constructing MotorizedVehicle
Constructing Wheel
Constructing Wheel
Constructing GearBox with 5 gears
Constructing Battery
Constructing Motorcycle
```

Of course in practice most classes will have default constructors and if you need to change anything to the state of your internal objects you can often do this by calling the appropriate setters. However, if other constructors are available which initialize the subobject to the wanted state, it is a good idea to use them as it keep your code cleaner.

## Pointers and Composition

[todo]
