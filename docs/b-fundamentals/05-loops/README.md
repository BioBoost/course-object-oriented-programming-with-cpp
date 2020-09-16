---
description: needs to be done
---

# Loops

In general, statements are executed sequentially: The first statement in a block is executed first, followed by the second, and so on. These statements are also only executed once by default. There may however be situations where you need to execute a block of code several number of times.

Programming languages provide various structures that allow you to loop a block of statements. The C++ programming language provides the following types of loops to handle looping requirements:

* a **for loop**: Execute a code block multiple times and simplify the code that manages the loop variable. Typically used if the number of iterations is fixed.
* a **while loop**: Repeats a code block while a given condition is true. It tests the condition before executing the body of the loop, meaning that it may never execute if the condition is not satisfied from the beginning.
* a **do-while loop**: Like a while loop, except that it tests the condition at the end of the loop body. This effectively means that the body of the loop will execute at least once.

::: definition Definition - Iteration
A single execution of the loop body is called an iteration.
:::

## While Loop

A while loop statement in the C# programming language repeatedly executes a statement block as long as a given condition is true. The condition is checked before the code block is executed. This means that the code block of the while loop may not even run at all if the condition is not met from the beginning.

The while loop adheres to the following construction template:

```cpp
while (condition)
{
  // Code block
}
```

## Do-While Loop

A do while loop is used when the code block (body of the loop) needs to be executed at least once. After the first iteration the condition is checked which determines if the code block should be executed again or not.

The do-while loop adheres to the following construction template:

```cpp
do
{
  // Code block
} while (condition);
```

Note that after the closing parentheses `)` of a condition, a semicolon `;` is required.


## The for loop

Basically a for loop is most often used when the number of iterations is pre-determined. A typical example would be a list of items where an actions needs to be applied to each item in the list.

The syntax of a for loop in C++ is:

```cpp
for ( <initialization>; <condition>; <increment> ) {
  // statements
}
```

* The **initialization step** is executed first, and only once. This step allows you to declare and initialize any loop control variables. You are not required to put a statement here, as long as a semicolon appears.
* Next, **the condition is evaluated**. If it is `true`, the body of the loop is executed. If it is `false`, the body of the loop does not execute and flow of control jumps to the next statement just after the for loop.
* After the body of the for loop has executed, the flow of control jumps back up to the **increment statement**. This statement allows you to update any loop control variables. This statement can be left blank, as long as a semicolon appears after the condition.
* The condition is now evaluated again. If it is true, the loop executes and the process repeats itself (body of loop, then increment step, and then again condition). After the condition becomes false, the for loop terminates.

Each of these components are optional. However the semicolon used to distinguish between each part is mandatory.

An example of a simple for-loop that iterates between 0 and 9 and outputs each value of `i`.

```cpp
for (int i = 0; i < 10; i++) {
  cout << "i = " << i << endl;
}
```

Note that `i` actually has block scope here and will not be available outside of the for-loop. If you want to keep the last iteration value after the for-loop you need to define the iterator before the for-loop.

```cpp
int i = 0;
for (; i < 10; i++) {
  cout << "i = " << i << endl;
}
cout << "After the for-loop i = " << i << endl;
```

An endless loop would look like this.

```cpp
for (;;;) {
  // Do something forever
}
```
