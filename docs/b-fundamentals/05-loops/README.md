---
description: needs to be done
---

# Loops

<!-- TODO: Add some info on continue and break; -->

In general, statements are executed sequentially: The first statement in a block is executed first, followed by the second, and so on. These statements are also only executed once by default. There may however be situations where you need to execute a block of code several number of times.

Programming languages provide various structures that allow you to loop a block of statements. The C++ programming language provides the following types of loops to handle looping requirements:

* a **for loop**: Execute a code block multiple times and simplify the code that manages the loop variable. Typically used if the number of iterations is fixed.
* a **while loop**: Repeats a code block while a given condition is true. It tests the condition before executing the body of the loop, meaning that it may never execute if the condition is not satisfied from the beginning.
* a **do-while loop**: Like a while loop, except that it tests the condition at the end of the loop body. This effectively means that the body of the loop will execute at least once.

::: insight Key Insight - Iteration
A single execution of the loop body is called an iteration.
:::

## The While Loop

A while loop statement in the C# programming language repeatedly executes a statement block as long as a given condition is true. The condition is checked before the code block is executed. This means that the code block of the while loop may not even run at all if the condition is not met from the beginning.

The while loop adheres to the following construction template:

```cpp
while (condition) {
  // Code block
}
```

## The Do-While Loop

A do while loop is used when the code block (body of the loop) needs to be executed at least once. After the first iteration the condition is checked which determines if the code block should be executed again or not.

The do-while loop adheres to the following construction template:

```cpp
do {
  // Code block
} while (condition);
```

Note that after the closing parentheses `)` of a condition, a semicolon `;` is required.

Consider the following example where the user is requested to input a number between `1` and `10`:

```cpp
int number = 0;
do {
  cout << "Please enter a number between 1 and 10: ";
  cin >> number;
} while (number < 1 || number > 10);
```

::: output
<pre>
Please enter a number between 1 and 10: 0
Please enter a number between 1 and 10: 33
Please enter a number between 1 and 10: 12
Please enter a number between 1 and 10: 3
</pre>
:::

Note that the `number` variable needs to be declared outside of the do-while loop if it is required in the condition.

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

::: output
<pre>
i = 0
i = 1
i = 2
i = 3
i = 4
i = 5
i = 6
i = 7
i = 8
i = 9
</pre>
:::

Note that `i` actually has block scope here and will not be available outside of the for-loop. If you want to keep the last iteration value after the for-loop you need to define the iterator before the for-loop.

```cpp
int i = 0;
for (; i < 10; i++) {
  cout << "i = " << i << endl;
}
cout << "After the for-loop i = " << i << endl;
```

::: output
<pre>
i = 0
i = 1
i = 2
i = 3
i = 4
i = 5
i = 6
i = 7
i = 8
i = 9
After the for-loop i = 10
</pre>
:::

## Endless Loops

In embedded programming one will often find an endless loop in the `main` function or in the processing functions of threads:

```cpp
for (;;) {
  // Do something forever
}
```

Or using a while construct

```cpp
while(true) {
  // Do something forever
}
```

::: tip Interrupt a Process
`Ctrl+C` can interrupt (kill) the current foreground process running in the terminal. It sends the SIGINT signal to the process, which is technically just a request - most processes will honor it, but some may ignore it.
:::

## Unconditional Branching Statements

A branch statement is a statement in a computer program that can cause the application to follow a different path of execution (i.e. jump to another part of the program and start executing statements there).

Conditional branch instructions are instructions that can produce 2 different path of executions based on the state of the application. A good example is the if-else statement.

Unconditional branching (otherwise known as a jump) is when the programmer forces the execution of a program to jump to another part of the program and this without the evaluation of a condition.

C++ has four statements that perform an unconditional branch:

* `return`: returns from a function/method. Possible with a resulting value.
* `break`: break out of a switch case or exit from a loop construct.
* `continue`: break away from the current iteration in a loop and skip to the next iteration
* `goto`: jump to a label inside of the application.

Except for the `return` statement, the `break` and `continue` statements should be used with care. Often these constructs can be avoided. `goto` statements are considered **ill practice** in modern programming. You may encounter them in old code, but don't use them in yourself. They create error prone code, a pain to debug and generate hard to read code.

### The `break` statement

The `break` statement is mostly used to exit from a `switch` case. However, you may also encounter it inside loop constructs where it is used to end the loop construct pre-maturely.

Let's take a look at a simple example where a for-loop is ended prematurely if the iterator value reaches `3`:

```cpp
for (unsigned int i = 0; i < 10; i++) {
  cout << "i = " << i << endl;
  if (i == 3) break;
}
```

::: output
<pre>
i = 0
i = 1
i = 2
i = 3
</pre>
:::

A `break` statement can often be found inside a `for` loop construct iterating over a set of data (an array for example), where a single condition breaks the iteration.

::: warning Breaking a while
Breaking away inside a `while` or `do-while` loop is often frowned upon. This is because the same can be achieved using some proper conditioning.
:::

### The `continue` statement

The `continue` statement is used to bypass the remainder of the current iteration.

The loop does not terminate when a `continue` statement is encountered. Instead, the remaining loop statements are skipped and the computation proceeds directly to the next iteration of the loop.

The continue statement can be included within a `while`, `do-while` and `for` statement.

In a `while` and `do-while`, `continue` causes the control to go directly to the condition check. In the case of a `for` loop, the iterator is first updated and then the condition is checked.

Let's take a look at a simple example where a for-loop is used to make the sum of only the even numbers:

```cpp
int sum = 0;
for (unsigned int i = 0; i < 10; i++) {
  if (i % 2 != 0) continue;   // Not even, skip

  cout << "i = " << i << endl;
  sum += i;
}
cout << "Total sum: " << sum << endl;
```

::: output
<pre>
i = 0
i = 2
i = 4
i = 6
i = 8
Total sum: 20
</pre>
:::

## Exercises

Try to solve the exercises yourself. Don't go copy pasting other people's solutions.

Mark the exercises using a ✅ once they are finished.

<!-- ### ❌ TITLE_GOES_HERE -->
