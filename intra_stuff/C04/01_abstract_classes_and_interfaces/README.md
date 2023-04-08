# Abstract classes and interfaces

Pure Virtual Functions are mostly used to define:

## abstract classes

These are base classes where you have to derive from them and then implement the pure virtual functions.

## interfaces

These are 'empty' classes where all functions are pure virtual and hence you have to derive and then implement all of the functions.

Pure virtual functions are actually functions which have no implementation in base class and have to be implemented in derived class.

[Credit to random stack overflow user](https://stackoverflow.com/a/12857266/14321918)

When to use an interface:
Use interface when the features you are implementing are not related to each other, every object is kind of separate.

When to use abstract class:
Use abstract class, when you are trying to create multiple versions of a feature, we use abstract class when there is some relation between the created objects.
