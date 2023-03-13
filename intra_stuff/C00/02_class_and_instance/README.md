# Class and instances

- CPP is classed based
- Each class has a constructor and destructor
  - Constructor: gets called at instantiation
  - Destructor: gets called at destruction

```hpp
#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>
class Sample{

public:
    Sample(void);
    ~Sample(void);
};

Sample::Sample (void) {
    std::cout << "Constructor called" <<std::endl;
    return ;
}

Sample::~Sample (void){
    std::cout << "Destructor called" <<std::endl;
}

#endif
```

- `Sample::Sample`: constructor of the class
- `Sample::~Sample`: destructor of the class
