# Struct vs Class

Structs and classes are really similar in c++.

`Class`:

- `atributes` of the `class` are **private** by default

`Stuct`:

- `attributes` of a struct are **public** by default.

___

## Example programm

```hpp
# ifndef  SAMPLE1_CLASS_HPP
# define SAMPLE1_CLASS_HPP

struct Sample1 {
    int  foo;
    Sample1( void );
    ~Sample1( void );

    void bar (void ) const;
}
#endif
```

```hpp
# ifndef  SAMPLE2_CLASS_HPP
# define SAMPLE2_CLASS_HPP

class Sample2 {
    int  foo;
    Sample2( void );
    ~Sample2( void );

    void bar (void ) const;
}
#endif

```

```c++
int main() {
    Sample1 instance1;
    Sample2 instance2;

    return 0;
}
```

If we try to compile the progrann we get a compiler error warning us that the `constructor` and `destructor` is private in case of `Sample2`.

```shell
main.cpp:8:10: error: calling a private constructor of class 'Sample2'
        Sample2 instance2;
                ^
./Sample_class2.hpp:6:5: note: implicitly declared private here
    Sample2( void );
    ^
main.cpp:8:10: error: variable of type 'Sample2' has private destructor
        Sample2 instance2;
                ^
./Sample_class2.hpp:7:5: note: implicitly declared private here
    ~Sample2( void );
    ^
2 errors generated.
```

`Class`:

- `atributes` of the `class` are **private** by default

`Stuct`:

- `attributes` of a struct are **public** by default.
