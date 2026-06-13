#include<iostream>
using namespace std;

/*
Problem 1: 
If we don't use template, when we declare a double vector, the vector will only store integer numbers.
e.g.

MyVector2D u(1.2, 2.3);
MyVector2D v(1.4, 2.6);

Output:
(1, 2)
(1, 2)
Equal!
*/
template<typename T>
class MyVector2D{
private:
    T x;
    T y;

public:
    MyVector2D(T x = 0, T y = 0): x(x), y(y){}
    void print() const;
    T getX() const{ return this->x; }
    T getY() const{ return this->y; }
};

template<typename T>
void MyVector2D<T>::print() const{
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}

template<typename T, typename U>
bool operator==(const MyVector2D<T> &u, const MyVector2D<U> &v){
    if(u.getX() == v.getX() && u.getY() == v.getY()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // MyVector2D<int> u1(1.2, 2.3);
    // MyVector2D<int> v1(1.4, 2.6);
    // MyVector2D<double> u2(1.2, 2.3);
    // MyVector2D<double> v2(1.4, 2.6);

    // u1.print();
    // v1.print();
    // cout << "======\n";
    // u2.print();
    // v2.print();

    // cout << endl;
    // if(u1 == v1){
    //     cout << "Equal!\n";
    // }
    // else{
    //     cout << "Unequal!\n";
    // }

    // if(u2 == v2){
    //     cout << "Equal!\n";
    // }
    // else{
    //     cout << "Unequal!\n";
    // }


    MyVector2D<int> u(1.2, 2.3);
    MyVector2D<double> v(1.4, 2.6);
    u.print();
    v.print();

    if(u == v){
        cout << "Equal!\n";
    }
    else{
        cout << "Unequal!\n";
    }

    system("pause");
    return 0;
}