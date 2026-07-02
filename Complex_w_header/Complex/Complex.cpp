#include "Complex.h"
#include <cmath>
using namespace std;

// Constructors
Complex::Complex(double r, double i){
    this->real = r;
    this->image = i;
}

Complex::Complex(const Complex& c){
    this->real = c.real;
    this->image = c.image;
}

// Operator overload
bool Complex::operator==(const Complex &c) const{
    if(this->real == c.real && this->image == c.image){
        return true;
    }
    else{
        return false;
    }
}

Complex &Complex::operator=(const Complex &c){
    if(this == &c){
        return *this;
    }
    else{
        this->real = c.real;
        this->image = c.image;
        return *this;
    }   
}

const Complex &Complex::operator+=(const Complex &c){
    this->real += c.real;
    this->image += c.image;
    return *this;
}

const Complex &Complex::operator-=(const Complex &c){
    this->real -= c.real;
    this->image -= c.image;
    return *this;
}

const Complex &Complex::operator*=(const Complex &c){
    double oldReal = this->real;
    this->real = oldReal * c.real - this->image * c.image;
    this->image = oldReal * c.image + this->image * c.real;
    return *this;
}

const Complex &Complex::operator/=(const Complex &c){
    double div = pow(c.real, 2) + pow(c.image, 2);
    double realCal = (this->real * c.real + this->image * c.image) / div;
    double imgCal = (this->image * c.real - this->real * c.image) / div;
    this->real = realCal;
    this->image = imgCal;
    return *this;
}

// Increment
Complex &Complex::operator++(){
    this->real += 1;
    return *this;
}

const Complex Complex::operator++(int){
    Complex temp(*this);

    ++(*this);

    return temp;
}

// Decrement
Complex &Complex::operator--(){
    this->real -= 1;
    return *this;
}

const Complex Complex::operator--(int){
    Complex temp(*this);

    --(*this);

    return temp;
}

// with iostream
ostream &operator<<(ostream &os, const Complex &c){
    if(c.image < 0){
        if(c.image == -1)
            os << c.real << " - " << "i";
        else
            os << c.real << " - " << (-1) * c.image << "i";
    }
    else if(c.image == 0){
        os << c.real;
    }
    else{
        if(c.image == 1)
            os << c.real << " + " << "i";
        else
            os << c.real << " + " << c.image << "i";
    }

    return os;
}

istream &operator>>(istream &is, Complex &c){
    is >> c.real >> c.image;

    return is;
}

// Functions

// this function is private
double Complex::getNorm() const{
    double value = sqrt(pow(this->real, 2) + pow(this->image, 2));
    return value;
}

// operator overloading on global
const Complex operator+(Complex left, const Complex &right){
    left += right;
    return left;
}

const Complex operator-(Complex left, const Complex &right){
    left -= right;
    return left;
}

const Complex operator*(Complex left, const Complex &right){
    left *= right;
    return left;
}

const Complex operator/(Complex left, const Complex &right){
    left /= right;
    return left;
}

// Functions on global
double complexNorm(const Complex &c){
    double norm = c.getNorm();
    return norm;
}

Complex complexPow(const Complex &c, const int pow){
    Complex result(1, 0);
    if(pow > 0){
        for (int i = 0; i < pow; i++){
            result *= c;
        }
    }
    else if(pow < 0){
        for (int i = 0; i < -pow; i++){
            result /= c;
        }
    }
    return result;
}