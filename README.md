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


WIP