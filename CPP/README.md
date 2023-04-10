# Orthodox Canonical Form

Orthodox canonical form in is the name of the default functions that
(by convention) should be available in each class.

These standard functions are:

`class Sample`

- Default constructor

```cpp
    Sample();
```

- Copy constructor

```cpp
Sample (const A &Sample);
```

- Destructor

```cpp
~Sample();
```

- Copy assignment operator

```cpp
Sample & operator=(const Sample & Sample)
```

## The orthodox canonical class form in C++11 and later

In C++11 the orthodox canonical class form has changed by including two new member functions:

- Move constructor
- Move assignment operator

This orthodox canonical form (like everything in the c++ community) is a *bit* controversial, but is preferred in some projects.

## Declaration Order

Group similar declarations together, placing public parts earlier.

A class definition should usually start with a `public`: section, followed by `protected`:, then `private`:. Omit sections that would be empty.

Within each section, prefer grouping similar kinds of declarations together, and prefer the following order:

1. Types and type aliases (typedef, using, enum, nested structs and classes, and friend types)
1. (Optionally, for structs only) non-static data members
1. Static constants
1. Factory functions
1. Constructors and assignment operators
1. Destructor
1. All other functions (static and non-static member functions, and friend functions)
1. All other data members (static and non-static)

Do not put large method definitions inline in the class definition. Usually, only trivial or performance-critical, and very short, methods may be defined inline. See Inline Functions for more details.
