# C++ crash course

## About this course
This course is written for two individuals named Y and H. If you are some random person that came accross this repo for whatever reason, you still can learn a lot from this course, you just might not get some inside joke.

### Reader's guide
Y: IO, string, vector
H: Read everything, Venn diagram of C++ and Python is almost two seperate circles.

## Boilerplate

```cpp
#include <bits/stdc++.h>  // Import every library

// Some hacky shit so you don't need to type std::xxx everytime
using namespace std;

int main() {  // Put all your code here
    // Write your code here

    return 0;  // Optional
}
```

## IO stream

#### Output

```cpp
// Outputs a and b space-separated
cout << a << " " << b << endl;
```

Using "\n" instead of endl is faster according to the programming handbook

```cpp
cout << a << "\n";
```

Format to x-decimal places (iykyk)
```cpp
// Set as x-decial
double c = 3.14159265358979323846;
cout << fixed << setprecision(10) << c << endl;  // 3.1415926536
```

#### Input

C++ have a special way of reading inputs, as follows:
```cpp
int a, b;
string s;

cin >> a >> b >> s;
```
This format can be used to read any space-like seperated values, including whitespace and newline character.

Read the whole line:
```cpp
string s;
getline(cin, s);
```
Useful when reading a line of space-separated sentence, you don't want to only read the first word!


> Life hack to memorise `<<` or `>>`, imagine it as data flow. Your output is basically your data flowing into `cout`, hence `cout << data`, vice versa.
>
> Or if this is too much for your tiny brain to comprehend, just remember it as `cout` is trying to write a story, and `<<` is used as a bracket for a story title in Chinese. 《西游记》


## Data types

Unlike Python, C++ is a statically typed language, meaning that you have to be responsible for the variable type, and you can't change it no matter what (so called have power over everything lol).


Here is a list, you probably already learned from Java
- int - stores integers (whole numbers), without decimals, such as 123 or -123
- double - stores floating point numbers, with decimals, such as 19.99 or -19.99
- char - stores single characters, such as 'a' or 'B'. Char values are - surrounded by single quotes
- string - stores text, such as "Hello World". String values are surrounded by - double quotes
- bool - stores values with two states: true or false

For bigger int values, just spam `long` before it and pray to god it's valid.

Variable declaration follows the following syntax:
```
type variableName = value;
```

```cpp
int a = 69;
double b = 2.71828;
char c = 'K'; // Note, single and double quote makes a difference!
string d = "Cogito, ergo sum";
bool e = teru;
```

Hacks:

- Chain initialization
```cpp
int a, b, c;
```

- Chain assignments:
```cpp
char a = 'b', z = 'g', e = 'f';
```

#### Trivia

##### Double vs float
`double` and `float` is the same thing, but `double` is much larger and more precise, so you almost will always use `double`.


##### Character
`char` is actually just a byte (8-bit) integer under the hood, so doing arithmetic operation will only be done based on the ascii value of the char.

```cpp
char a = 'A';
char b = 'B';

cout << a + b;
```

What you think you will see:
```
AB
```

What you will actually see:
```
131
```

65 (A) + 66 (B) = 131

##### String
String is actually just array of char under the hood, but it includes many handy built-in methods too! If you want to actually do something in string instead of char, you should convert them to string instead.

##### Boolean
Bool is actually just integer `1` or `0`, so consider saving more time by typing `0` instead of `false` and `1` instead of `true`.

#### Data type conversion

##### Convert to string
For char:
```cpp
char c = 'm';
string s = "" + c;
```
More clean but a little bit confusing method:
```cpp
string s(1, c);
```
1 indicates the length, for char it's always 1

For numbers:
```cpp
int a = 911;
double b = 1.61803399;

string sa = to_string(a);
string sb = to_string(b);
```

##### Number convert
There's nothing much about this, literally just
```cpp
double g = 9.81;
int physicist_be_like = g; // 9
```

It automatically converts, if you wanna specify:
```cpp
(long long int)g;
```
Substitute `long long int` with any type you wan

## Operator

`+ - * / %`, pretty self-explanatory
No `**` for exponenent and `//` for floor division, not today, fellow pythonist. Use [math lib](https://www.youtube.com/watch?v=dQw4w9WgXcQ) for that.

#### Logical operator
`&&` - and
`||` - or
`!` - not

#### Bitwise (logic gates) operation
`&` - and
`|` - or
`~` - not
`<<` - lshift
`>>` - rshift
`^` - xor

Typing `x+=1` is too time consuming, some genius invented this syntax to save our precious time!

`x++` - Literally `x+=1`
`x--` - Literally `x-=1`
`x` - Literally `x*=1`

Fun fact, `++x` and `--x` do the same thing, with a slight difference, googling is left as an exercise for the reader.

Comparison operators are the same as any other language, namely
`> < >= <= == !=`
(We don't do `===` here, screw Javascript)

`x = x opr y` can be shorten to `x opr= y`, if that isn't obvious enough.


## String
As mentioned before, `string` is basically an array of `char`s, but as an object, with helper functions that makes your life easier.

List of useful functions for string:

Concatenation
```cpp
string s = "Hello";
cout << s + ", world!" << endl; // Hello, world!
cout << s << endl; // Hello

string s2 = s + ", world!";
cout << s2 << endl; // Hello, world!

s.append(", world!");
cout << s << endl; // Hello, world!
```

Indexing
```cpp
char c = s[0]; // H
char d = s.at(0); // Literally the same thing, but throws error when you try to access out of bound index.
```

Changing characters
```cpp
s[0] = 'B'; // Bello, world!
s.at(0) = 'Z' // Zello, world!
```

Get length
```cpp
int len = s.length(); // 13
int len2 = s.size(); // Same shit
```

## Conditions

#### If-else
C++'s if-else syntax is inspired by the [Bython](https://github.com/mathialo/bython) language syntax. Only difference is C++ uses `else if` instead of `elif`

```cpp
if (condition1) {
    // Do smth
} else if (condition2) {
    // Do smth else
} else {
    // Do stuff
}
```

Another alternative, is using ternary operator, which is basically an if-else short hand. Syntax:
```cpp
variable = (condition) ? expressionTrue : expressionFalse;
```
Example:

```cpp
cout << "Light is a " + (observed ? "particle" : "wave") << endl;
```

#### Switch-case
Switch case can also be considered as condition, its syntax is exactly the same as Java's. For this reason we are not gonna elaborate more on this. One reason we use switch-case over if-else is not only because of it's simplicity in some specific case (no need to spam `==`), it's also significantly faster than if-else statements, refer to [this video](https://youtu.be/fjUG_y5ZaL4?si=jg77LfneYWlfA8iP).

```cpp
switch (expression) {
    case x:
        // code block
        break;
    case y:
        // code block
        break;
    default:
        // code block
}
```

> A break can save a lot of execution time because it "ignores" the execution of all the rest of the code in the switch block.

## Loop

#### While loop
While loop is the same as any other language, it's just a loop that runs while the condition is true.

```cpp
while (condition) {
    // Do smth
}
```

Another alternative is do-while loop, which is basically a while loop that runs at least once. What this means is that the condition is checked after the first iteration.
```cpp
do {
    // Do smth
} while (condition);
```

```cpp
do {
    cout << "This still got printed because it runs for one turn before checking condition" << endl;
} while (false);
```

#### For loop
For loop syntax in C++ is exactly the same as Java. Syntax:
```cpp
for (initial; condition; increment) {
    // Do smth
}
```

This code prints 0 to 4
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Those fields are optional, meaning you can not put anything in there, but you have to put the semicolon.
```cpp
int i = 0; // Put initial outside because you can
for (; i < 5;) {
    cout << i << endl;
    i++; // Increment inside the loop because why not
}
```
```cpp
for (;;) { // No stop condition, hence resulting in infinite loop
    // Do some expensive things here to break your computer
}
```

##### Range-based for loop
This is a special loop that is only available in C++11 and above. It's a loop that iterates through all the elements in a container, such as an array or a vector.

Syntax:
```cpp
for (type var : container) {
    // Do smth
}
```

This works for

- Arrays
```cpp
int arr[] = {1, 2, 3, 4, 5};
for (int i : arr) {
    cout << i << endl;
}
```

- Vectors
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
for (int i : vec) {
    cout << i << endl;
}
```

- Strings
```cpp
string s = "Hello";
for (char c : s) {
    cout << c << endl;
}
```

This is useful when you only need the value of the element, and not the index.

#### Break and continue
What if I have multiple conditions that will break the loop? I wish there's a way to break the loop inside the loop itself. Fear not, for `break` and `continue` is here to save the day!

`break` is used to break the loop, and `continue` is used to skip the current iteration and continue to the next iteration.

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break; // Break the loop when i is 5
    }
    if (i == 3) {
        continue; // Skip the iteration when i is 3
    }
    cout << i << endl;
}
```

This code outputs 0, 1, 2, 4. 3 is skipped because of the `continue`, and 5 is not printed because of the `break`.

When a loop is `break`ed or `continue`d, it will not execute the rest of the code in the loop, and will immediately go to the next iteration or exit the loop.

When you have nested loops, `break` and `continue` will only affect the innermost loop.
