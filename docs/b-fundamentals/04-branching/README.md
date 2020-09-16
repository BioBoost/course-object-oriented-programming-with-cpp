---
description: needs to be done
---

# Branching

## The if statement

The statements inside your source files are generally executed from top to bottom (in the order that they appear). Control flow statements, however, break up the flow of execution by employing decision making, enabling your program to conditionally execute particular blocks of code. This section describes the `if` and `if-else` statements that allow code to be executed based on a given condition.

The `if` statement is the most basic of all the control flow statements. It allows an application to execute a certain section of code only if a particular condition evaluates to `true`.

Examine the following example where the user is requested to enter a temperature. Next the given value is evaluated and if it is above (or equal to) a certain threshold value (`85` in this case) a warning message is outputted to the terminal.

```cpp
int temperature = 0;

std::cout << "Please enter temperature: ";
std::cin >> temperature;

if (temperature >= 85) {
  std::cout << "Warning, temperature is too high!" << std::endl;
}
```

<!-- TODO: Explain cin a bit earlier? -->

If this test evaluates to `false` (meaning that the temperature is below `85`), control jumps to the end of the if statement.

## The if-else Statement

The if-else statement provides a secondary path of execution when an "if" clause evaluates to `false`. Taking the previous example you could output an "all is good" message when the temperature is below the threshold value.

```cpp
int temperature = 0;

std::cout << "Please enter temperature: ";
std::cin >> temperature;

if (temperature >= 85) {
  std::cout << "Warning, temperature is too high!" << std::endl;
} else {
  std::cout << "All is good" << std::endl;
}
```

The if-else statement can be extended with **even more if-else statements**. Each if-else will need a new condition that needs to be checked. The first one that evaluates to `true` is executed, after which control jumps to the end of the if-else statements.

Let us extend the temperature example with a number of ranges.

```cpp
int temperature = 0;

std::cout << "Please enter temperature: ";
std::cin >> temperature;

if (temperature < 85) {
  std::cout << "All is good" << std::endl;
} else if (temperature >= 85 && temperature < 100) {
  std::cout << "Warning, temperature is too high!" << std::endl;
} else if (temperature >= 100 && temperature <= 200) {
  std::cout << "Time to run!" << std::endl;
} else {
  std::cout << "We are doomed!!!!" << std::endl;
}
```

<!-- You may have noticed that the value of `temperature` can satisfy more than one expression in the combined statements. However the conditions are checked sequentially and once a condition is satisfied, the appropriate statements are executed and the remaining conditions are not evaluated anymore. -->

## The Switch Statement

Let us take a look at some code that will allow the user to enter the number of the day of the week. The program will than determine the name of the day and output it to the user.

```cpp
  int dayOfTheWeek = 0;

  std::cout << "What day of the week is it today [1-7]? ";
  std::cin >> dayOfTheWeek;

  if (dayOfTheWeek == 1) {
    std::cout << "Than it's Monday today" << std::endl;
  } else if (dayOfTheWeek == 2) {
    std::cout << "Than it's Tuesday today" << std::endl;
  } else if (dayOfTheWeek == 3) {
    std::cout << "Than it's Wednesday today" << std::endl;
  } else if (dayOfTheWeek == 4) {
    std::cout << "Than it's Thursday today" << std::endl;
  } else if (dayOfTheWeek == 5) {
    std::cout << "Than it's Friday today" << std::endl;
  } else if (dayOfTheWeek == 6) {
    std::cout << "Than it's Saturday today" << std::endl;
  } else if (dayOfTheWeek == 7) {
    std::cout << "Than it's Sunday today" << std::endl;
  } else {
    std::cout << "That is not a valid number" << std::endl;
  }
}
```

When **checking a single variable for equality** using multiple if-else statements, it can be replaced with another structure called a switch structure. The template of the switch structure is shown below. Each case needs a **literal integral value** to compare the variable against. If it matches (equals) than the code between the colon `:` and the `break;` statement is executed. The `break` is required for the switch to be stopped when a match is found. If no `break` is placed, the execution falls through to the next case.

```java
switch (<variable>) {
  case <integral_literal_1>:
    // Code to be executed
    break;
  case <integral_literal_2>:
    // Code to be executed
    break;
  case <integral_literal_3>:
    // Code to be executed
    break;
  // ...
  default:
    // Code to be executed in case no match found
}
```

Replacing the if-else structure of the day-of-the-week example with a switch statement results in the following code.

```java
int dayOfTheWeek = 0;

std::cout << "What day of the week is it today [1-7]? ";
std::cin >> dayOfTheWeek;

switch(dayOfTheWeek) {
  case 1:
    std::cout << "Than it's Monday today" << std::endl;
    break;
  case 2:
    std::cout << "Than it's Tuesday today" << std::endl;
    break;
  case 3:
    std::cout << "Than it's Wednesday today" << std::endl;
    break;
  case 4:
    std::cout << "Than it's Thursday today" << std::endl;
    break;
  case 5:
    std::cout << "Than it's Friday today" << std::endl;
    break;
  case 6:
    std::cout << "Than it's Saturday today" << std::endl;
    break;
  case 7:
    std::cout << "Than it's Sunday today" << std::endl;
    break;
  default:
    std::cout << "That is not a valid number" << std::endl;
}
```

No general rule exists for when to use which construct. Some programmers don't like the switch statement. In most cases it is a case of preference.

Some important points about the switch statement:

* The expression provided in the switch should result in a constant value otherwise it would not be valid.
  * Valid expressions for switch:
    * `switch(1+2+23)`
    * `switch(1*2+3%4)`

  * Invalid switch expressions for switch:
    * `switch(ab+cd)`
    * `switch(a+b+c)`

* Duplicate case values are not allowed.
* The `default` statement is optional. Even if the switch case statement did not have a default statement, it would run without any problem.
* The `break` statement is optional. If omitted, execution will continue on into the next case. The flow of control will fall through to subsequent cases until a `break` is reached.
* Nesting of switch statements are allowed, which means you can have switch statements inside another switch. However nested switch statements should be avoided as it makes code more complex and less readable.

<!-- TODO: Add warning here about scope of local variables inside of cases. Need `{}` to limit scope. Also see remark on paper -->