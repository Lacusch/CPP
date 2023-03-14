# Constans in cpp

- `Constans` are generally important in programming, but especially in:
- funtional programming where everything is a constant
- complex langues like C++ (where it helps to reduce errors).

```cpp

class Sample{

public:
    float const pi;
    int         qd;

    Sample(float const f);
    ~Sample(void);

    void bar(void) const;
    // this atribute of this instance of the class shoud never be altered
};

```

This `const` after the function makes sure that the values im the function cannot be asigned:

- after `initialising` a variable / function, the that instans is `const` cannot be changed
- (`this->qd = 0`) gives a compile error

This technik is really helpful to make programs safer and save on debugging time.
