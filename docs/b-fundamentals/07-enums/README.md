---
description: needs to be done
---

# Enums

An enumeration is a distinct type whose value is restricted to a specific range or list of values, which may include several explicitly named constants. The values of the constants are values of an integral type known as the underlying type of the enumeration.

Enums are used to assign names to the integral constants which makes a program easy to read and maintain.

## Defining an Enumeration

An enumeration is a user-defined data type that consists of integral constants. To define an enumeration, the keyword `enum` is used.

```cpp
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
std::cout << "Today we are the " << today << "th day of the week." << std::endl;
```

::: output
<pre>
Today we are the 2th day of the week.
</pre>
:::

## Renumbering an Enum

By default, the first element in an `enum` is assigned `0`, the second `1` and so on. These default values can be changed during declaration if needed.

```cpp
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

```cpp
enum Season {
  SPRING = 3,
  SUMMER = 6,
  AUTUMN = 9,
  WINTER = 12
};
```

## Scoped Enums

In the original C and C++ `enum` types, the unqualified enumerators are visible throughout the scope in which the enum is declared. In scoped enums, the enumerator name must be qualified by the enum type name.

```cpp
enum class Suit { DIAMONDS, HEARTS, CLUBS, SPADES };
```

Notice that the `class` keyword follows the `enum` keyword to create a scoped `enum`.

Now the type of the enum needs to be specified when using the enum labels:

```cpp
Suit cardSuit = Suit::HEARTS;
```

This prevents collisions and also makes code more clear.

### Enums for Flags

Enums are often used when **flags** need to be passed to a function. Instead of passing a variable for each flag, the flags are combined using an enum where the values are powers of two.

Example:

```cpp
enum class Style {
  ITALIC = 1,
  BOLD = 2,
  UNDERLINED = 4,
  STRIKETHROUGH = 8
};
```

By casting the `Style` values to `int`, different `Style` values can be combined using the bitwise *OR* operator as shown in the next example.

```cpp
// Possible styles
enum class Style {
  ITALIC = 1,
  BOLD = 2,
  UNDERLINED = 4,
  STRIKETHROUGH = 8
};

// Combining some styles
int heading = (int)(Style::BOLD) | (int)(Style::UNDERLINED);

// What styles were selected ?
if (heading & (int)Style::ITALIC) std::cout << "Style is italic" << std::endl;
if (heading & (int)Style::BOLD) std::cout << "Style is bold" << std::endl;
if (heading & (int)Style::UNDERLINED) std::cout << "Style is underlined" << std::endl;
if (heading & (int)Style::STRIKETHROUGH) std::cout << "Style is strikethrough" << std::endl;
```

::: output
<pre>
Style is bold
Style is underlined
</pre>
:::
