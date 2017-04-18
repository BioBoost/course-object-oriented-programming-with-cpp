# Assignments

## Linked List

### Part 1 - Basic actions

Model a linked list (single linked, not double) that allows you to store a primitive integer as data.
A linked list allows you to create a dynamic list that expands and shrinks as needed.

More info @ https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm

You need a class Node which has a `data` attribute (type int) and a pointer to the `next` node.
Also create a class LinkedList which just keeps track of the `head` node using a pointer. It should also
have a destructor to clean up all dynamically created memory of the nodes.

The following actions should be available for the linked list:
* Adding an element
* Removing the first or last node
* Print the list (best to use a to_string method)

### Part 2 - Keys

Turn your linked list into a hashmap by adding a key attribute to identify your data.

This can be achieve by extending the Node class with a `key` attribute which allows you to identify the items held by the linked list.
This will require you to add a method `get(std::string key)` which returns the data item with the specified key.
The add method should also be changed to allow a `key` to be specified.

### Part 3 - Exceptions (does not work for mBed)

Throw a custom exception when you add an element and the specified key is already taken.

This assignment cannot be used on the mBed as exceptions are disabled for this platform.

### Part 4 - DigitalOut (mBed specific)

Replace the integral `data` attribute of the Node with a `DigitalOut`. This will for example allow you to create a linked list of LEDs.

Now create a small main application that creates a hashmap (linked list) of four LEDs. Next ask the user which LED he wants to toggle. Use the pseudo code below as a demo program.

```c++

int main(void) {
  LinkedList leds;
  leds.add(LED1, "alive");
  leds.add(LED2, "busy");
  leds.add(LED3, "hungry");
  leds.add(LED4, "sleepy");

  do {
    string input;
    cin >> input;
    leds.get(input).toggle();
  } while (input != "exit");

  return 0;
}
```

Do note that LED1, LED2, ... are of type `PinName`.

### Part 5 - Reverse (optional)

Add a reverse method to the linked list that reverses all the elements in the linked list.
