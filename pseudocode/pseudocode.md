[comment]: # (THEME = black)
[comment]: # (CODE_THEME = base16/zenburn)

# Cooper CHESS CS: Pseudocode
August 2024     
James Ryan, Vaibhav Hariani

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
int // stores a number
string // stores a multi-character string, eg "Hello, world!"
bool // boolean value - stores TRUE or FALSE
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
    do it, if condition == TRUE;
} else {
    do this if that wasnt true;
}
move on;
```

[comment]: # (!!!)

## Picking up from block diagrams...

Block diagrams are basically a visual representation of an *algorithm*
> An <b>algorithm</b> can be thought of as a series of steps which bring us 
> to some kind of result.

[comment]: # (|||)

## Primer: Lets rebuild our previous in-class block diagram

Take some time to see if you can rebuild our previous block diagram 
on deciding whether or not to go grocery shopping. Think about what you 
need (variables) and whether you have it (if statements). 
You may work in groups, or work alone.

[comment]: # (|||)

## Example solution

[comment]: # (|||)

## Lets review: Fibonnaci



[comment]: # (!!!)

## A puzzle! Finding numbers

Ok, heres a scenario: Lets say we have a computer with a clock speed of
`1 Hz`, or 1 calculation per second. This is our only tool for getting into 
a room which has a passcode thats a random number between 1 & 100. 
If we guess wrong, it tells us "higher" or "lower", to indicate what our 
next guess could be (provided by a built-in `bool guess(int try)` function. 
How do we break in, taking as little time as possible?

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
        if (guess(ourGuess) == TRUE) {
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

Remember how we said this door tells us whether we should guess "higher" or
"lower"? Well, it does that with another function: `int direction(int)`.
If `direction` returns `1`, we go higher. If its `-1`, we go lower. 
Otherwise, we are at the number we want.

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
        int goHigher = direction(ourGuess);
 
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
