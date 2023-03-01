# arbuint class

## What

This class expresses **_arbitary-long_ unsigned integers**.

## Where

```cpp
namespace gmathlib {
    namespace arbtype {
        class arbuint;
    }
}
```

## How

- [To Initialize](#to-initialize)
- [Operatos](#operators)

### To Initialize

When you are to initialize arbuint, you could do so as you intialize `int`, `long`, ....

```cpp
arbuint n = 100;
```

But when you are going to use n-adic expression or to initialize to **so much big integer**, you should use string. (Note: usable n (of n-adic) is limited from 1 to 36, and use 0-9, a-z(also A-Z))

```cpp
arbuint n = "20|f312ij8"; // 20-adic
arbuint n = "1000000000000000000000000000000"; // big integer
```

[Back to table of contents of "How"](#how)

### Operators

- `operator<<`/`operator<<=` (left-shift operation)

  Left-shift operation as usual. **Note: the right operand is limited to unsigned int. **

  ```
  arbuint = arbuint << unsigned int
  arbuint <<= unsigned int
  ```

- `operator>>`/`operator>>=` (right-shift operation)

  Right-shift operation as usual. **Note: the right operand is limited to unsigned int. **

  ```
  arbuint = arbuint >> unsigned int
  arbuint >>= unsigned int
  ```

- `operator+`/`operator+=`/`operator++`

  Addition as usual.

  What operands are usable?

  ```
  arbuint = arbuint + unsigned int
  arbuint = arbuint + unsigned long long
  arbuint = arbuint + arbuint
  ```

  Also, so are compound assignment operators.

  ```
  arbuint += unsigned int
  arbuint += unsigned long long
  arbuint += arbuint
  ```

  Increment as usual.

  ```
  ++arbuint
  ```

- `operator-`/`operator-=`/`operator--`

  Subtraction as usual. **Note: if the result of sub is negative, the value is set to 0.**

  What operands are usable?

  ```
  arbuint = arbuint - unsigned int
  arbuint = arbuint - unsigned long long
  arbuint = arbuint - arbuint
  ```

  Also, so are compound assignment operators.

  ```
  arbuint -= unsigned int
  arbuint -= unsigned long long
  arbuint -= arbuint
  ```

  Decrement as usual.

  ```
  --arbuint
  ```

- `operator<` (less than)

  Less than as usual.

  What operands are usable?

  ```
  arbuint < arbuint
  ```

[Back to table of contents of "How"](#how)
