#pragma once
#include<string>
#include<fstream>

class Complex {
private:
	double real, imaginary;
public:
	Complex();
	Complex(double a);
	Complex(double a, double b);
	Complex add(const Complex& secondComplex)const;
	Complex subtract(const Complex& secondComplex)const;
	Complex multiplication(const Complex& secondComplex)const;
	Complex division(const Complex& secondComplex)const;
	Complex abs(const Complex)const;
	string toString();
	double getRealPart();
	double getImaginaryPart();
	Complex& operator+=(const Complex& secondComplex);
	Complex& operator-=(const Complex& secondComplex);
	Complex& operator*=(const Complex& secondComplex);
	Complex& operator/=(const Complex& secondComplex);
	double& Complex::operator[](int index);
	//Prefix
	Complex& operator++();
	Complex& operator--();
	//Postfix
	Complex operator++(int dummy);
	Complex operator--(int dummy);
	//unary
	Complex operator+();
	Complex operator-();
	//>><<
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator >> (istream&, Complex&);
};
//Nonmember function operators
Complex operator+(const Complex& com1, const Complex& com2);
Complex operator-(const Complex& com1, const Complex& com2);
Complex operator*(const Complex& com1, const Complex& com2);
Complex operator/(const Complex& com1, const Complex& com2);
