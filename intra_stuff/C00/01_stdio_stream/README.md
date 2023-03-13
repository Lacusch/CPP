# I/O operations

- `cin` and `cout` objects can be used to acess input streams and output streams respectively.
- `<<` and `>>` operator allow you to copy these data flows.

## Example programm

```cpp
int main(void)
{
    char buff[512];

    std::cout << "Hello Word !" << std::endl;

    std::cout << "Input a word: ";
    std::cin >> buff;
    std::cout << "You entered : [" << buff << "]" << std::endl;

    return (0);
}
```
