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
