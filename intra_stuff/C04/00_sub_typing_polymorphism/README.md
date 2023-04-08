# Polymorphism in C++

An excellent article about Polymorphism in c++:

[The Four Polymorphisms in C++](https://catonmat.net/cpp-polymorphism)

## Subtyping polymorphism

Subtype polymorphism, also known as runtime polymorphism.

Runtime polymorphism is the ability to use delivered classes trough base class pointers and references.

### Animal example

Since they are all of Felidae biological family, and they all should be able to meow, they can be represented as classes inheriting from Felid base class and overriding the meow pure virtual function,

```cpp
// file cats.hpp

class Felid {
public:
 virtual void meow() = 0;
};

class Cat : public Felid {
public:
 void meow() { std::cout << "Meowing like a regular cat! meow!\n"; }
};

class Tiger : public Felid {
public:
 void meow() { std::cout << "Meowing like a tiger! MREOWWW!\n"; }
};

class Ocelot : public Felid {
public:
 void meow() { std::cout << "Meowing like an ocelot! mews!\n"; }
};
```

Now the main program can use Cat, Tiger and Ocelot interchangeably through Felid (base class) pointer,

```cpp
# include <iostream>
# include "cats.hpp"

void do_meowing(Felid *cat) {
 cat->meow();
}

int main() {
 Cat cat;
 Tiger tiger;
 Ocelot ocelot;

 do_meowing(&cat);
 do_meowing(&tiger);
 do_meowing(&ocelot);
}
```

Here the main program passes pointers to cat, tiger and ocelot to do_meowing function that expects a pointer to Felid. Since they are all Felids, the program calls the right meow function for each felid and the output is:

```bash
Meowing like a regular cat! meow!
Meowing like a tiger! MREOWWW!
Meowing like an ocelot! mews!
```

## Name

Subtype polymorphism is also called runtime polymorphism because the resolution of the
