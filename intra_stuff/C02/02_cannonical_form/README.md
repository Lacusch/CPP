# Orthodox canonical form in c++

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
