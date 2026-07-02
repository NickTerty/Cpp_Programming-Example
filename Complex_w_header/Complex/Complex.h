#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>

// Class: Complex
class Complex{
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    friend std::istream &operator>>(std::istream &is, Complex &c);
    friend double complexNorm(const Complex &c);
private:
    double real;
    double image;
    // private function
    double getNorm() const;
public:
    // Constructors
    // Complex();
    Complex(double r = 0, double i = 0);
    Complex(const Complex &c);
    // ~Complex();

    // Operator Overload
    bool operator==(const Complex &c) const;
    Complex &operator=(const Complex &c);
    const Complex &operator+=(const Complex &c);
    const Complex &operator-=(const Complex &c);
    const Complex &operator*=(const Complex &c);
    const Complex &operator/=(const Complex &c);
    // Increment
    Complex &operator++();
    const Complex operator++(int);
    // Decrement
    Complex &operator--();
    const Complex operator--(int);
};

// Globals
const Complex operator+(Complex left, const Complex &right);
const Complex operator-(Complex left, const Complex &right);
const Complex operator*(Complex left, const Complex &right);
const Complex operator/(Complex left, const Complex &right);

double complexNorm(const Complex &c);
Complex complexPow(const Complex &c, const int pow);

#endif