This gives redeclaration errors
```c++
int test = 2;

switch (test) {

  case 0:
    int a = 12;
    std::cout << "a = " << a << std::endl;
    break;

  case 1:
    int a = 88;
    std::cout << "a = " << a << std::endl;
    break;

  case 2:
    int a = -15;
    std::cout << "a = " << a << std::endl;
    break;

  default:
    int a = 88;
    std::cout << "a = " << a << std::endl;
}
```

Works fine as each block creates a scope

```c++
int test = 2;

switch (test) {

    case 0: {
        int a = 12;
        std::cout << "a = " << a << std::endl;
    } break;

    case 1: {
        int a = 88;
        std::cout << "a = " << a << std::endl;
    } break;

    case 2: {
        int a = -15;
        std::cout << "a = " << a << std::endl;
    } break;

    default:
        int a = 88;
        std::cout << "a = " << a << std::endl;

}
```

## Explanation

A switch statement is just a bunch of labels and a goto done by the compiler depending on the value of the thing inside the switch test.

When you have a local variable in a function, anywhere past the declaration of that variable you can use it. For instance:

```c++
int a;
// can use a now
```

However, in a switch statement, if you have a local variable:

```c++
case 1:
    int a;
    break;
case 2:
    // we can use a here because these cases are just labels used in a goto
    // i.e. the cases do *not* create a new scope
```

So when you have a variable in a case, the variable exists in cases below it but the variable won't exist because the code that initialized it got skipped by the case statement. It's hard for me to explain, maybe someone else can do a better job.

The braces fix this problem because they make the variable local, so that it doesn't exist in subsequent cases. It only gets created if that particular case gets entered, and if you forget a break and control falls through to the next case, the ending } ends the scope and causes the variable to be destroyed so it's not accessible from the next case, and the initialization can't be skipped.

So just remember that all the cases share scope. That might help you understand this.
