## The Switch Statement

Let us take a look at some code that will allow the user to enter the number of the day of the week. The program will than determine the name of the day and output it to the user.

```c++
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
```c++
// Constant expressions allowed
switch(1+2+23)
switch(1*2+3%4)
```
 * Invalid switch expressions for switch:
```c++
// Variable expression not allowed
switch(ab+cd)
switch(a+b+c)
```
* Duplicate case values are not allowed.
* The default statement is optional. Even if the switch case statement did not have a default statement, it would run without any problem.
* The break statement is optional. If omitted, execution will continue on into the next case. The flow of control will fall through to subsequent cases until a break is reached.
* Nesting of switch statements are allowed, which means you can have switch statements inside another switch. However nested switch statements should be avoided as it makes code more complex and less readable.
