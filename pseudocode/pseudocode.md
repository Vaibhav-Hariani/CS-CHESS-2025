[comment]: # (THEME = black)
[comment]: # (CODE_THEME = base16/zenburn)

# Cooper CHESS CS: Pseudocode
August 2025     
Vaibhav Hariani

[comment]: # (!!!)

## Anatomy of a computer program

Programs are similar to block diagrams in that they describe how to step 
through some kind of process. We'll go over some common parts you find 
in a program.

Note:
Be sure to write these down on a board as we go along! We need it for the 
class exercise

[comment]: # (|||)

## Variables
Variables attach a *name* to a *piece of information*. The variable *type* 
defines what kind of information is being stored by that variable.

Declaration syntax:
```c
type name = value;

// example: storing a string that says "Hello, world!"
string myString = "Hello, world!";
```

[comment]: # (|||)

Notable types:

```cpp
int // stores an integer value: no decimals
string // stores a multi-character string, eg "Hello, world!"
bool // boolean value - stores TRUE or FALSE
float //stores a value with decimal places.   
```

[comment]: # (|||)

## `while` Operator
`while` repeats a block of code until its condition is no longer true

```c
while (condition) {
    do something;
}
```

[comment]: # (|||)

## `for` Operator
`for` repeats a block of code until its condition is no longer true, same 
as a `while` operator.<br>
However, `for` allows for an *initialization statement*, as well as an 
*expression*, to be declared. 
- The *initalization statement* is ran at the __very start__ of a for loop.
- The *expression* is ran __every time__ the for loop is completed.

```c
for (init statement; condition; expression) {
    do something;
}
```

[comment]: # (|||)

Example: a counter! We initalize a number, `int i = 0` at the start of 
our `for` statement.
We want to run this loop 100 times, so we set our condition to be `i < 100` 
Then, we set our expression to be `i = i + 1`, so at the end, we add 1 to 
`i`.

```c
for (int i = 1; i < 100; i = i + 1) {
    print(i);
}
```

[comment]: # (|||)

## `if` operator

`if` the condition is true, do it!!!

```c
if (condition) {
    do it, if condition == TRUE;
}
move on;
```

[comment]: # (|||)

## `else` operator

`else`, do this!!!

```c
if (condition) {
    do this;
} else {
    do this;
}
move on;
```

[comment]: # (|||)

## `functions`
These let us express systems with an input and an output.
```c
//The first int tells us what we expect to get out: Return type.
//The elements after <addition> tell us that we're expecting two numbers as inputs
int multiplication(int num1, int num2) {
    int return_value = 0;
    for(int i = 0; i < num2; i++){
        return_value = return_value + num1;
    }
    //return designates the output
    return return_value;
}
```

[comment]: # (!!!)

## A puzzle! Finding numbers

Ok, heres a scenario: Lets say we have a computer with a clock speed of
`1 Hz`, or 1 calculation per second. This is our only tool for getting into 
a room which has a passcode thats a random number between 1 & 100. We have a `int guess(int try)` function, which tells us if our guess is lower (-1), higher (1), or correct (0). How do we break in, taking as little time as possible?

Note:
if this is too easy or if someone finishes really early, change it up:
It now generates a *determined* `n` number of numbers. 
`guess` has a second arg, `int position`. 
All `n` numbers must add to a *determined* sum to let you in. 
`direction` tells you how close you are to this sum. 

[comment]: # (|||)

## Linear search (counting up)

```c
// our code-cracking algorithm
// returns an integer that opens the door. 
// otherwise, its over 9000
int crack_the_code() 
{
    for (int ourGuess = 1; ourGuess <= 100; ourGuess = ourGuess + 1) {
        if (guess(ourGuess) == 0) {
            return ourGuess;
        }
    } 
    return 9001;
}
```

[comment]: # (|||)

The previous algorithm works, taking at most 100 seconds to find our 
result. However, its not exactly efficient, since it just works up from 
the absolute lowest number until we find what we want. 

We can do better!!!

[comment]: # (|||)

## Binary search

```c
// our code-cracking algorithm
// returns an integer that opens the door. 
// otherwise, its over 9000
int crack_the_code_V2() 
{
    int lowestPossible = 1;
    int highestPossible = 100;
   
    while (lowestPossible <= highestPossible) {
        // take the average of our lowest possible & highest possible code
        int ourGuess = (lowestPossible + highestPossible) / 2; // 50
        int goHigher = guess(ourGuess);
 
        if (goHigher == 1) { 
            lowestPossible = ourGuess + 1; // we must go higher
        } else if (goHigher == -1) {
            highestPossible = ourGuess - 1; // we must go lower
        } else { 
            return ourGuess; // found it!
        }
    }

    return 9001; // couldnt find it
}
```

[comment]: # (!!!)
Homework: 2 problems. Email/teams with questions or solutions.

1) You're trying to save up for a house (with that fancy post-Cooper salary). 
    Write pseudocode for a function that accepts a salary, a saving percentage, and a home cost. Show how many months it will take to buy the home, given your savings. Assume that you deposit a percentage monthly, and that all money you deposit increases in value by 3% every year (divide by 12 for every month).
[comment]: # (!!!)
2) Challenge (Optional & Unexpected): In the towers of hanoi problem, there are 3 pegs. The first peg contains N disks, each one slightly larger than the one before it. You must move all the disks to the last peg. A smaller disk cannot be placed on top of a larger disk.

 Don't waste time on number two if you can't figure it out: It's the subject of our final lecture!