# Initiallisation list

- We can use an initiallision list as a more concise sintax to alternative to the `this` form.

Instead of :

```cpp
Sample1::Sample1( char p1, int p2, float p3) {
    std::cout << "Sample Constructor called" << std::endl;

    this->a1 = p1;
    std::cout << "this->a1 = " << this->a1 << std::endl;

    this->a2 = p2;
    std::cout << "this->a1 = " << this->a2 << std::endl;

    this->a3 = p3;
    std::cout << "this->a1 = " << this->a3 << std::endl;
}
```

We can write:

```cpp
Sample2::Sample2 (char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
    std::cout << "Sample2 Constructor called" << std::endl;
    std::cout << "this->p1 = " << this->a1 << std::endl;
    std::cout << "this->p2 = " << this->a2 << std::endl;
    std::cout << "this->p3 = " << this->a3 << std::endl;
}
```

Initiallisation list is the prevered method.
