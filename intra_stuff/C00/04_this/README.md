# This

- The `this` keyword, known in other programming langues as `self` (Python) is a pointer that refers to the instance of the class itself.

```cpp
#include <iostream>
class Sample{

public:
    int foo;
    Sample(void);
    ~Sample(void);

    void bar(void);
};

Sample::Sample (void) {
    std::cout << "Constructor called" <<std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();
    return ;
}

Sample::~Sample (void){
    std::cout << "Destructor called" <<std::endl;
}

void Sample::bar(void) {
    std::cout << "Member function called" << std::endl;
}

int main (){
    Sample instance;
       return (0);
}
```

This code creates a sample class, that has the members :

1. Constructor: `Sample`
2. Destructpr: `~Sample`
3. Function: `bar`
4. Integer: `foo`

Each an instance of the class gets intentiated, we call the constructor.

This constructor sets the value of it's own int `foo` to 42, then it prints it out.
