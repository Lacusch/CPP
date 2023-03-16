# Member vs non Member attributes

## Member attributes / functions

- Instance variables / functions
- It's present in an instance of a class
- The class needs to be instanciated for it to work
- Each attribute is different in every instance
- Each function (even functions with `void` as parameters) has a pointer to itself, that can be accesed with `this`

## Non Member attributes / functions

- Class variables / functions
- `static` keyword is used to define class variables / attributes
- It's the same for each instance of the class
- Is not dependent on the instances of the class
- It's the same in each instance
- Has no pointer refering to itself, so one cannot use `this` keyword in a non member / Class funtion
- We can initially non member atributes independent of instances

## Class atribute syntax

To refer to a non menber function use the name of the class with the scope operator (`::`)

```cpp
Sample::_nbInst
```

## Instance atribute syntax

When refering to an instance attricube:

- Use `this` inside the instance

- Use the instance of the class outside

```cpp
this.nb;

vs 

instance.nb
```

An instance variable need to be initilised with the syntax:
`int Sample::_nbInst = 0;` before it can be used
