#include "Kompleks.hpp"

Kompleks::Kompleks() : real(0), imag(0){}

Kompleks::Kompleks(double r, double i) : real(r), imag(i){}

Kompleks::Kompleks(const Kompleks& other) : real(other.real), imag(other.imag){}

double Kompleks::getReal() const{return real;}

double Kompleks::getImag() const{return imag;}

double Kompleks::setReal(double r) {double prev = real; real = r; return prev;}

double Kompleks::setImag(double i) {double prev = imag; imag = i; return prev;}

Kompleks Kompleks::operator+(const Kompleks& other) const{return Kompleks(this->real + other.real, this->imag + other.imag);}

Kompleks Kompleks::operator-(const Kompleks& other) const{return Kompleks(this->real - other.real, this->imag - other.imag);}

Kompleks Kompleks::operator*(const Kompleks& other) const{return Kompleks(this->real * other.real - (this->imag * other.imag), this->imag * other.real + this->real * other.imag);}

bool Kompleks::operator==(const Kompleks& other) const{return (this->real == other.real && this->imag == other.imag);}

Kompleks &Kompleks::operator=(const Kompleks& other){
    if(this != &other){
        this->real = other.real;
        this->imag = other.imag;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Kompleks& c){
    auto i = c.getImag();
    os << c.getReal();
    if(i != 0) if(i > 0) os << " + " << i << "i"; else os << " - " << -i << "i";
    return os;
}