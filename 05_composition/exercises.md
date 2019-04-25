## Chapter 05 - Composition - Exercises

### Die Throwing (continued)

Take the "Die Throwing" application from the exercises of chapter 4.

Create a class `DieThrower` that takes a `Die` object and throws it the requested number of times. Track the throws as you did before with the frequency table. Output the results via the `to_string()` method.

```text
##############################################
# DieThrower
##############################################
# - die: Die
# - numberOfThrows: unsigned int
# - freqTable: vector<unsigned int>
##############################################
# + DieThrower(die: Die, numberOfThrows: unsigned int)
# + roll(): void
# + to_string(): string
##############################################
```

You can us the `std::vector` class to create a frequency table based on the size of the number of eyes on the die.