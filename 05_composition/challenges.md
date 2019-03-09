## Chapter 05 - Composition - Challenges

### A Menu

Create a class `Menu` that holds an `std::vector` of `string` objects.

A user of the class can add items to the menu, which are then stored in the `std::vector`. A user can also request an `up` and `down` action on the object the select the previous or next menu item in the list. The current position should be remembered inside the class.

Also supply a method that returns the current selected menu item.

Last also add a method `to_string()` that returns a string representation of the current state of the menu in a similar format to the one shown below:

```text

Menu:

* Create new game
* Load a game
=> Help
* Cheats
* About
```

Notice the arrow that indicated the currently selected menu item in the list.

You do not need to request actual user input, but you may do so as an extra.