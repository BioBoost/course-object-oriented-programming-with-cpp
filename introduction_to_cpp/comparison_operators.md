## Comparison Operators

Comparison (aka relational) operators are used for **comparison of two values**.

The table below shows the available comparison operators that can be used in C++ to build a condition.

| Operator | Description |
|---|---|
| == | equal to |
| != | not equal to |
| > | greater than |
| >= | greater than or equal to |
| < | less than |
| <= | less than or equal to |

Since a conditional statement actually produces a single `true` or `false` result, this result can actually be assigned to a variable of type `bool`.

Let's take a look at some examples of comparison operators:

```c++
int a = 4;
int b = 8;
bool result;
result = (a < b);     // true
result = (a > b);     // false
result = (a <= 4);    // a smaller or equal to 4 - true
result = (b >= 9);    // b bigger or equal to 9 - false
result = (a == b);    // a equal to b - false
result = (a != b);    // a is not equal to b - true
```

Note how we need to use two equality signs `==` to test if two values are equal, while we use a single sign `=` for assignment.

While the comparison operators will not often be used in a situation as shown in the code above, they will often be used when making decisions in your program.
