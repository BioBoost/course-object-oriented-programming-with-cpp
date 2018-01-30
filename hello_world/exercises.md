## Exercises

### Personal Information

Alter the "Hello World" application to display some more text. Add some personal information about yourself. Can you also output literal integers. How would you go about chaining pieces of information into a single `cout` statement?

### endl

What does `endl` do? It is often found after outputting some information to the terminal.

### The standard namespace

Try leaving out the `using namespace std;` statement. Can you alter the "Hello World" application to work without using the `using namespace std;` statement?

### Status Code of an Application

Create a small C++ application that return a value from main different from `0`. Try to chain the execution of your application with a simple command such as `echo "All went well"`.

Can you fix the chaining of both commands so the `echo "All went well"` will only run when your application returns 0.

Hint: Both on Window and Linux there are two ways to chain commands. One that always executes both commands and one that only executes the second command if the first one did not fail (returned a value equal to 0).
