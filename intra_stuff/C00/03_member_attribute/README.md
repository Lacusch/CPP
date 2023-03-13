# Members of a class

- It's possible to define a function inside a class
- This function can be used after declaring an instance of a class

```hpp
class Sample{

public:
    Sample(void);
    ~Sample(void);

    void bar(void);
};

```

```cpp
#include "Sample_class.hpp"

int main (){
    Sample instance;
    instance.bar();
    return (0);
}
```

In this case an instance of the `Sample` class gets declared, then it's member `bar` gets called.
