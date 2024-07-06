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

## Data structure

A variable can only store one value at once, but what if you want to store multiple values? This is where data structures come in. Data strucures are basically a way to store multiple values in one variable. Different data structures have different properties and use cases.

#### Array
Array is a data structure that stores multiple values of the same type in one variable. It's like a list in Python, but you have to specify the size of the array when you declare it. The size of the array cannot be changed after it's declared.

Because arrays are fixed size, you must specify their size when declaring one.
```cpp
int arr[5]; // Array of 5 integers
```

If the values of the array is known, you can also initialize the array when declaring it.
```cpp
int arr[] = {1, 2, 3, 4, 5}; // Array of 5 integers
```

Notice that you don't need to specify the size in this case, because the size is automatically determined by the number of values in the array.

The one and only way to access an element in an array is by using the index of the element. The index of the first element is 0, and the index of the last element is the size of the array minus one.

```cpp
int arr[] = {1, 2, 3, 4, 5};
cout << arr[0] << endl; // 1
cout << arr[4] << endl; // 5
```

You can also change the value of an element in the array by assigning a new value to it.
```cpp
int arr[] = {1, 2, 3, 4, 5};
arr[0] = 10;
cout << arr[0] << endl; // 10
```

#### Vector
Vector is a data structure that is similar to an array, but it's dynamic, meaning that you can change the size of the vector after it's declared.

Declaration
```cpp
vector<int> vec; // Empty vector of integers
```
Replace int with any type you want.

Initialization
```cpp
vector<int> vec = {1, 2, 3, 4, 5}; // Vector of 5 integers
```

Hacky way to create a vector with the same values
```cpp
vector<int> vec(5, 0); // Vector of 5 integers, all initialized to 0
```

Also work when trying to create a 2d vector of 0s
```cpp
vector<vector<int>> vec(5, vector<int>(5, 0)); // 5x5 2d vector of integers, all initialized to 0
```

Accessing elements
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
cout << vec[0] << endl; // 1
cout << vec.at(0) << endl; // Literally the same thing, but throws error when you try to access out of bound index.
```

Changing elements
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vec[0] = 10;
cout << vec[0] << endl; // 10
vec.at(0) = 20;
cout << vec[0] << endl; // 20
```

Compated to array, vector has a lot of functionality. Some of the most useful functions are:

Get size
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
cout << vec.size() << endl; // 5
```

Append element
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);
cout << vec[5] << endl; // 6
```

Remove last element
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vec.pop_back();
cout << vec.size() << endl; // 4
```

Remove element at specific index
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vec.erase(vec.begin() + 2);
cout << vec[2] << endl; // 4
``` 

Insert element at specific index
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vec.insert(vec.begin() + 2, 10);
cout << vec[2] << endl; // 10
```

Ok I think it's clear that we are starting to see some weird syntax now. Wtf is `vec.begin`? There's an easy explanation for this, which is C++ is a stupid low level language because they are too lazy to implement a normal `insert` function that just receives a normal integer parameter. Understanding this requires another level of understand of C++. This complex concept is explained in the [competitive programming handbook](https://cses.fi/book/book.pdf) page 49.

##### Array vs Vector

After seeing this 2 types of data structure, you might ask, why array? Inserting in array requires you to have an index while vector insert is as simple as pushing back to the vector by calling a function.

The answer is, array is faster than vector. This is because array is a fixed size data structure, while vector is dynamic. This means that array is stored in a contiguous block of memory, while vector is stored in a non-contiguous block of memory. This makes array faster than vector when accessing elements, because the elements are stored next to each other in memory. But if your algorithm suck, you should probably prioritize that first before worrying about the speed of your data structure. So feel free to just use `vector<int>` and don't give a shit to memory management.

Oh btw, congrats! At this point, you can pretty much do any thing you want and solve any cp problems, everything after this is niche stuff that can be useful when it is needed.


#### Pair
Very simple, used to group two values that doesn't have to be the same type together.

Syntax:
```cpp
pair<type1, type2> varName;
```

Example:
```cpp
pair<int, string> myPair;
myPair.first = 10;
myPair.second = "Hello";
```

You can also quickly create a pair with the builtin make_pair function

```cpp
pair<int, int> p = make_pair(1, 2);
```

#### Map
, aka dict in python, object in javacript and hashmap in java.

```cpp
map<string, int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;
cout << m["banana"] << "\n"; // 3
```

If the value of a key is requested but the map does not contain it, the key is automatically added to the map with a default value. For example, in the following code, the key ”aybabtu” with value 0 is added to the map.
```cpp
map<string,int> m;
cout << m["aybabtu"] << "\n"; // 0
```

The function count checks if a key exists in a map:
```cpp
if (m.count("aybabtu")) {
// key exists
}
```
The following code prints all the keys and values in a map:
```cpp
for (auto x : m) {
cout << x.first << " " << x.second << "\n";
}
```

#### Set
At this point I realise the cp handbook is a better resource than this, so I'm just gonna copy paste from there.

A set is a data structure that maintains a collection of elements. The basic operations of sets are element insertion, search and removal.


The following code creates a set that contains integers, and shows some of the operations. The function `insert` adds an element to the set, the function count returns the number of occurrences of an element in the set, and the function `erase` removes an element from the set.

```cpp
set<int> s;
s.insert(3);
s.insert(2);
s.insert(5);
cout << s.count(3) << "\n"; // 1
cout << s.count(4) << "\n"; // 0
s.erase(3);
s.insert(4);
cout << s.count(3) << "\n"; // 0
```