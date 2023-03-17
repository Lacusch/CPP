# Pointer on member + pointer on member funtions

## Types of pointers in C++

C

- `pointers`
- `pointers` on functions

___

C++

- `pointers` on members
- `pointers` on member functions

## Example class

```cpp
#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

class Sample {

public:

    int foo;

    Sample( void );
    ~Sample ( void );

    void bar (void) const ;
};
#endif
```

### `.*` operator

- Gets the adress of the instance

```cpp
    Sample instance;

    instance.*p = 21
```

Change the value of int foo to 21

### `->` operator

- Used to get the adress of of an instance pointed to by the pointer

```cpp
Sample  *iinstance_agress = &instance;

instance_adress->*p = 42;
```

- Change the value of int foo to 21
(Same as above)
