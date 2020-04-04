---
description: Enums are user defined types which assign names to integral values.
title: 10 - Enums
---

<!-- Maybe this should be moved to other chapter later on -->

# Chapter 10 - Enums

An enumeration is a distinct type whose value is restricted to a specific range or list of values, which may include several explicitly named constants. The values of the constants are values of an integral type known as the underlying type of the enumeration.

## Defining an Enumeration

An enumeration is a user-defined data type that consists of integral constants. To define an enumeration, the keyword `enum` is used.

```c++
enum DayOfTheWeek {
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATERDAY,
  SUNDAY
};
```

The enumerator labels are automatically assigned an integral value starting from `0`. So the label `SUNDAY` will have a value of `6`.

To declare a variabel of the `enum` type, use the defined type as any other data type:

```c++
DayOfTheWeek today = WEDNESDAY;
cout << "Today we are the " << today << "th day of the week." << endl;
```

## Renumbering an Enum

By default, the first element in an `enum` is assigned `0`, the second `1` and so on. These default values can be changed during declaration if needed.

```c++
enum DayOfTheWeek {
  MONDAY = 1,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATERDAY,
  SUNDAY
};
```

If successive labels are not assigned a value manually, a value is automatically assigned starting by incrementing the previous value.

Another example:

```c++
enum Season {
  SPRING = 3,
  SUMMER = 6,
  AUTUMN = 9,
  WINTER = 12
};
```

## Scoped Enums

In the original C and C++ `enum` types, the unqualified enumerators are visible throughout the scope in which the enum is declared. In scoped enums, the enumerator name must be qualified by the enum type name.

```c++
enum class Suit { DIAMONDS, HEARTS, CLUBS, SPADES };
```

Notice that the `class` keyword follows the `enum` keyword to create a scoped `enum`.

Now the type of the enum needs to be specified when using the enum labels:

```c++
Suit cardSuit = Suit::HEARTS;
```

This prevents collisions and also makes code more clear.
