# Pointers vs References

## Pointers in C

- Need a variable outside of our scope
- Allocate it on the heap not on the stack

## References in C++

Definitions:

1. And alias to an existing variable
2. It's a pointer that's **constant**, **always dereferenced** and **never void**

- Serve a similar purpose as pointers in `C`

### Diffences between pointers and references

#### Pointers in c++

- Can be set to `NULL`
- Can be changed at runtime
- Needs to manually dereferenced to acess it's value (`*`)

#### References in c++

- Can't be set to `NULL` --> needs to be known at initialisation
- `const` so can't be changed after initialisation
- The're always dereferenced

It case the variable needs to be changed or it could have `null` value / sometimes shoudn't exist than pointers are required, othervise references are preferable.
