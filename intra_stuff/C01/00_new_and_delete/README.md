# `new` and `delete`, dynamic memory allocation in c++

- `new` ~ `malloc`
- `delete` ~ `free`
- dynamic allocation for classes

It's possible to declare variables on the stack and the heap.

```cpp
Student bob = Student("bfubar"); // stack allocation
Student* jim = new Student ("jfubar"); //heap allocation, need to be freed manually
delete ("jfubar"); // frees the manual allocation
```

## Arrays

To free an array using `new` (so dynamic allocation ) you can free it using the `[]` syntax:

```cpp
    Student* students = new Student[42];
    //do some stuff
    delete [] students;
```
