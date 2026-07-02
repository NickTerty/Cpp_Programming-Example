# About this header files
This is the first time I learn operator overloading and header files.
I use `Complex` as a object with class. 
> If you don't know what complex number is, see [here](https://en.wikipedia.org/wiki/Complex_number).

Here is some operands and function that exist.
### Operands
1. Assignment: `=`
2. Comparison: `==`
3. Arithmetic: `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`
4. iostream: `>>`, `<<`
5. Others: `complex++`, `++complex`, `complex--`, `--complex`, `complex` is a variable.

### functions
`double complexNorm(const Complex &c);`: `complexNorm(z)` will calculate the norm (or absolute value) of complex number like $|z|$, return a `double` value. <br>
`Complex complexPow(const Complex &c, const int pow);`: `complexPow(z, n)` will calculate the power of complex number like $z^n$, return a `Complex` value.

## Some example
(1) power of $i$<br>
`main.cpp`
```cpp
#include <iostream>
#include "Complex.h" 

using namespace std;

int main(){
    Complex complex;

    cin >> complex;

    for (int i = 0; i < 5; i++){
        cout << "C^" << i << " = " << complexPow(complex, i) << endl;
    }

    return 0;
}
```
Sample Run:
```
0 1

C^0 = 1
C^1 = 0 + i
C^2 = -1
C^3 = -0 - i
C^4 = 1
```

(2) Operator
```cpp
#include <iostream>
#include "Complex.h" 

using namespace std;

int main(){
    Complex complex[3];

    for (int i = 0; i < 3; i++){
        cin >> complex[i];
    }

    for(int i = 0; i < 3; i++){
        cout << complex[i] << endl;
    }

    Complex resultComp(0, 0);
    for(int i = 0; i < 3; i++){
        resultComp += complex[i];
    }

    cout << resultComp << endl;

    return 0;
}
```
Sample Run:
```
1 3
3 4
-2 -7

1 + 3i
3 + 4i
-2 - 7i
2
```