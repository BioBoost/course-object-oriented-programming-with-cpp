# Solutions

## Its all about Objects

### The Java Stack class

By inheriting from Vector, all public methods (the interface) of Vector are also available for the Stack class. This means that the Stack class has methods such as add() and remove() which allow to add and remove elements at a given index. This is totally illogical for a Stack implementation which should only have a push(), pop() and peek() method. Elements should only be able to be added or removed to or from the top.

A much better implementation would of consisted of composition. This would hide the Vector inside the Stack class and never allow the public interface of the Vector to be part of the public interface of Stack.
