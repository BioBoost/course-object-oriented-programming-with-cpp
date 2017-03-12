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

![Aggregation relationship between Department and Teacher](img/aggregation.png)

**Composition** is a specialized form of aggregation. It is a strong type of aggregation. In this relationship child objects do not have their own lifecycle. If a parent object is destroyed, all its child objects will also be destroyed. This represents a "death-relationship". In UML this is represented by a solid diamond followed by a line.

Let's take an example of relationship between a House and a Room. House can contain multiple rooms, but there is no independent life of Room and a Room cannot belong to two different houses. If we destroy the house, the rooms will automatically be destroyed too.

![Composition relationship between House and Room](img/composition.png)

While a clear distinction is made here between aggregation and composition, it is not always done so in practice. In practice, one does often speak of composition even if he/she were to mean aggregation. As a result this course may also use the word composition where aggregation is meant. Of course in cases where a clear distinction is needed, the correct term will be used.

## Creating new Classes Through Composition

You probable have already been using composition without realizing it. Consider the example below of a class Product that might be used in an online web shop as a model for products that are sold.

![Model of a Product](img/product.png)

While we will almost never include them as such, the `name` and `description` are actually instances of a class too, namely `std::string`. So in other words `Product` is already an basic example of composition.

![Model of a Product with Composition](img/product_composition.png)

When composing objects of other objects, the *sub objects* are normally made private. This hides implementation and allows the designer of the class to change the implementation if needed.

Consider the following example where a `DisplayDevice` is modelled as a composition of an `LCD` objects, which interacts with actual hardware, and `Color` objects that define the color of the letters and background.

![A Display Device](img/display_device.png)

By hiding the `LCD` object inside the `DisplayDevice` we hide the complexity of the hardware dependent class. This class may have methods for setting and resetting pixels, for changing hardware timings, for drawing rectangles, circles, and so on. We hide all that and we only expose the ability to show some text, through `display(text:string)`, and display a bitmap, through `display(image:Bitmap)`. This keeps our `DisplayDevice` simple and very user friendly.

## How object are sprout to life

Whenever an object of a class is instantiated, its constructor is called. This however is not all that happens:
* the **parent constructor** is also called if the class inherits from another class
* also all the constructors of all the composed objects are called

Of course if the base class inherits from another class or the subobjects do, or contain other objects, this process repeats itself within those objects.

Let's take a look at a more complex example of a `MotorCycle`. It inherits from a `MotorizedVehicle` class which in turn inherits from a `TransportationDevice`. A `MotorizedVehicle` contains a `Motor` and a `MotorCycle` is composed of a `Motor` (thorugh inheritance), two `Wheel`s, a `GearBox` and a `Battery`.

![A Motorcycle Model](img/motorcycle.png)

It is very important to know which constructors are called and at what time. Let's use the following implementation to illustrate which constructors are called when. Note that the implementation is shown below each class to make the code shorter.

```c++
class Motor {
    public:
        Motor(void);
};

Motor::Motor(void){
   cout << "Constructing Motor" << endl;
}
```

```c++
class Wheel {
    public:
        Wheel(void);
};

Wheel::Wheel(void){
   cout << "Constructing Wheel" << endl;
}
```

```c++
class GearBox {
    public:
        GearBox(void);
};

GearBox::GearBox(void){
   cout << "Constructing GearBox" << endl;
}
```

```c++

class Battery {
    public:
        Battery(void);
};

Battery::Battery(void){
   cout << "Constructing Battery" << endl;
}
```

```c++
class TransportationDevice {

    public:
        TransportationDevice(void);
};

TransportationDevice::TransportationDevice(void){
   cout << "Constructing TransportationDevice" << endl;
}
```

```c++
class MotorizedVehicle : public TransportationDevice {
    private:
        Motor motor;

    public:
        MotorizedVehicle(void);
};

MotorizedVehicle::MotorizedVehicle(void){
   cout << "Constructing MotorizedVehicle" << endl;
}
```

```c++
class Motorcycle : public MotorizedVehicle {

    private:
        Wheel front;
        Wheel back;
        GearBox gearbox;
        Battery battery;

    public:
        Motorcycle(void);
};

Motorcycle::Motorcycle(void){
   cout << "Constructing Motorcycle" << endl;
}
```

The main program could be as simple as:

```c++
#include <iostream>
#include "motorcycle.h"

int main()
{
    Motorcycle vn800;
    return 0;
}

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

Important to think about is this: Why are the constructors of the composed objects executed before the actual constructor of the composing object ? Simple, because those objects should be ready and in a valid state for the composing object to use it when it is constucted. For example: the MotorCycle may want to change the battery voltage to a different level in its constructor.


![A Motorcycle Model - Constructors](img/motorcycle_constructors.png)

By default, the constructors invoked are the **default** ("no-argument") constructors. Moreover, all of these constructors are called before the class's own constructor is called.











## Constructor Initialization List

http://www.cprogramming.com/tutorial/initialization-lists-c++.html
