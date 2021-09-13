---
description: needs to be done
---

# Polymorphism

Consider an example where a class `Tank` and a class `SelfPropelledGun` inherit from a class `WarMachine`.

Now when creating objects on the stack and not using them via baseclass pointers, we would be able to write the following code:

```cpp
WarMachine machine("A small rescue jeep used in world war 2 in good shape.", 510000);
WarMachine tank("A Tiger 1 tank prototype in bad shape.", 299250);
WarMachine spg("An ISU-152 SPG in non-working condition. Needs revision.", 2000000);

// ...

cout << machine.to_string() << endl;
cout << tank.to_string() << endl;
cout << spg.to_string() << endl;
```

In this case the output would be:

::: output
<pre>
WarMachine: A small rescue jeep used in world war 2 in good shape. Price = 510'000 euro
Tank: A Tiger 1 tank prototype in bad shape. Price 299'250 euro
SPG: An ISU-152 SPG in non-working condition. Needs revision. Price = 2'000'000 euro
</pre>
:::

Polymorphism comes from Greek and means:

* Poly = many
* Morph = form, shape

So polymorphism is the ability of an object to take on many forms. The most common use of polymorphism in OOP occurs when a parent class reference is used to refer to a child class object.

This basically means that you can do the following in our `WarMachine` example application:

```cpp
WarMachine * machine = new WarMachine("A small rescue jeep used in world war 2 in good shape.", 510000);
WarMachine * tank = new Tank("A Tiger 1 tank prototype in bad shape.", 299250);
WarMachine * spg = new SelfPropelledGun("An ISU-152 SPG in non-working condition. Needs revision.", 2000000);
```

Do take note that this only works when using pointers of the baseclass type. We cannot do this when creating local variables on the stack unless we then access them via a pointer of the baseclass as shown below:

```cpp
Tank tank;

WarMachine * machine = &tank;
```

This is often used when storing subtypes inside an array or container class:

```cpp
std::vector<WarMachine*> machines;

machines.push_back(new WarMachine("A small rescue jeep used in world war 2 in good shape.", 510000));
machines.push_back(new Tank("A Tiger 1 tank prototype in bad shape.", 299250));
machines.push_back(new SelfPropelledGun("An ISU-152 SPG in non-working condition. Needs revision.", 2000000));
```

This allows all the superclass and subclass instances to be store together in a list. If this were not possible it would be necessary to create separate lists for each type.

Of course in a realistic application the list would be populated from a database or a file.

C++ tracks the actually type of the objects. This basically means that while all the objects created above are `WarMachine`s because of inheritance, C++ still knows that some are `Tank`s or `SPG`s.

Polymorphism allows us to store subtypes inside an array of the baseclass type. Now what would happen if we were to add the following code to the application:

```cpp
for (unsigned int i = 0; i < machines.size(); i++) {
  cout << machines[i]->to_string() << endl;
}
```

Which would output:

::: output
<pre>
WarMachine: A small rescue jeep used in world war 2 in good shape. Price = 510'000 euro
WarMachine: A Tiger 1 tank prototype in bad shape. Price 299'250 euro
WarMachine: An ISU-152 SPG in non-working condition. Needs revision. Price = 2'000'000 euro
</pre>
:::

This is actually not what we expected. We expected that each WarMachine item's 'correct' `to_string()` method would be called.

Important to know is that while method overriding can be done out of the box, **polymorphism needs to be enabled in C++** and is default not. A method can be declared a candidate for late binding (polymorphism) by appending the keyword `virtual` before the declaration of the method in the class as shown below. Strictly speaking only the `to_string()` method of `WarMachine` needs to be declared `virtual` here.

```cpp
class WarMachine {
  // ...
  public:
    virtual std::string to_string(void);
};
```

```cpp
class Tank : public WarMachine {
  // ...
  public:
    std::string to_string(void);
};
```

If the same main code is executed again the output will be:

::: output
<pre>
WarMachine: A small rescue jeep used in world war 2 in good shape. Price = 510'000 euro
Tank: A Tiger 1 tank prototype in bad shape. Price 299'250 euro
SPG: An ISU-152 SPG in non-working condition. Needs revision. Price = 2'000'000 euro
</pre>
:::

### Another look at polymorphism

Source: [http://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c#comment32597274_2392656](http://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c#comment32597274_2392656)

Let's say you have these two classes:

```cpp
class Animal {
  public:
    void eat(void) {
      std::cout << "I'm eating generic food.";
    }
};
```

```cpp
class Cat : public Animal {
  public:
    void eat(void) {
      std::cout << "I'm eating a rat.";
    }
};
```

In your main function:

```cpp
void main(void) {
  Animal * animal = new Animal();
  Cat * cat = new Cat();

  animal->eat(); // outputs: "I'm eating generic food."
  cat->eat();    // outputs: "I'm eating a rat."
}
```

So far so good right? Animals eat generic food, cats eat rats, all without virtual.

Let's change it a little now so that eat() is called via an intermediate function (a trivial function just for this example):

```cpp

void make_it_eat(Animal * animal) {
  animal->eat();
}

void main(void) {
  Animal * animal = new Animal();
  Cat * cat = new Cat();

  make_it_eat(animal);  // outputs: "I'm eating generic food."
  make_it_eat(cat);     // outputs: "I'm eating generic food."
}
```

Uh oh ... we passed a Cat into `make_it_eat()`, but it won't eat rats. Should you overload `make_it_eat()` so it takes a `Cat *` ? If you have to derive more animals from Animal they would all need their own `make_it_eat()`.

The solution is to make `eat()` a virtual function:

```cpp
class Animal {
  public:
    virtual void eat(void) {
      std::cout << "I'm eating generic food.";
    }
};
```

Where now all goes well:

```cpp

void make_it_eat(Animal * animal) {
  animal->eat();
}

void main(void) {
  Animal * animal = new Animal();
  Cat * cat = new Cat();

  make_it_eat(animal);  // outputs: "I'm eating generic food."
  make_it_eat(cat);     // outputs: "I'm eating a rat."
}
```

If we did not have this polymorphic behavior we would have to create a `make_it_eat()`
method for each type of Animal. This would definitely cause lots of errors and headaches.

So polymorphism is again another technique that allows us to write short, clean and maintainable code.

### Virtual Destructors

The `virtual` keyword is not only important for methods we which to override and access via baseclass pointers. It is also important when considering dynamic memory usage. When reserving memory in your objects, you need to free it once the objects are destroyed. This is accomplished using the `delete` keyword. This has been discussed in detail in the chapter "Memory Allocation".

However what if you extend this class. Is the destructor of the baseclass still called in that case?

Let's take a look at a simple example:

```cpp
class Animal{
  public:
    ~Animal(){
        std::cout << "Destroying an Animal" << std::endl;
    }
};
```

and a subclass from Animal named Cat:

```cpp
class Cat : public Animal {
  public:
    ~Cat(){
        std::cout << "Destroying a Cat" << std::endl;
    }
};
```

If we create a new Cat we expect both destructors to be called:

```cpp
int main() {
    Animal * a = new Cat();
    delete a;
    return 0;
}
```

However the only thing the output shows is:

::: output
<pre>
Destroying an Animal
</pre>
:::

Do note that this is not the case when a Cat object is created on the stack.

To fix this, we are required to make the destructor of Animal `virtual`.

```cpp
class Animal{
  public:
    virtual ~Animal(){
        std::cout << "Destroying an Animal" << std::endl;
    }
};
```

```cpp
int main() {
    Animal * a = new Cat();
    delete a;
    return 0;
}
```

Rendering the output

::: output
<pre>
Destroying a Cat
Destroying an Animal
</pre>
:::

Note that the destructors are executed in the opposite order as the constructors.