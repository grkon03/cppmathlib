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

[Back to table of contents of "How"](#how)
