## Chapter 05 - Composition - Challenges

### Die Throwing (continued)

Take the "Die Throwing" application from the challenges of chapter 4.

Next create a class `DieThrower` that takes a `Die` object and throws it the requested number of times. Track the throws as you did before with the frequency table. Output the results via the `to_string()` method.

```text
##############################################
# DieThrower
##############################################
# - die: Die
# - numberOfThrows: unsigned int
# - freqTable: unsigned int[]
##############################################
# + DieThrower(die: Die, numberOfThrows: unsigned int)
# + roll(): void
# + to_string(): string
##############################################
```

You will need to create a dynamically allocated frequency table based on the number of sides on your die.