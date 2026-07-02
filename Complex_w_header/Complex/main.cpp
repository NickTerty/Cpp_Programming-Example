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