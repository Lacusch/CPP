# Comparison

Comparison works ina  similar way to C.

To compare the values of the `insances` of `objects` we can use a getter function.

```cpp
int Sample::compare(Sample * other) const {
    if (this->_foo < other->get_Foo() )
        return -1;
    else if (this->_foo > other->get_Foo() )
        return 1;
    return 0;
}

int main () {

    Sample i1( 42 );
    Sample i2 ( 42);
    if (&i1 == &i2)
        std::cout << "The adress of i1 and i2 are equal" << std::endl;
    else
        std::cout << "The adress of i1 and i2 are NOT" << std::endl;
    if (i1.compare(&i2) == 0)
        std::cout << "The values of i1 and i2 are equal" << std::endl;
    else
        std::cout << "The values of i1 and i2 are NOT" << std::endl;
    return 0;
}
```

So we could compare the values, adresses the object depending on the use case.
