/////////////
//Anna Tran
//CS 172 Sec 1 
//14.7
////////////
#include<iostream>
#include<cstdlib>
#include<sstream>
#include "Complex.h"
#include <cmath>

using namespace std;

Complex::Complex()
{
	real = 0;
	imaginary = 0;
	
}
Complex::Complex(double a)
{
	real = a;
	imaginary = 0;
}
Complex::Complex(double a, double b)
{
	real = a;
	imaginary = b;
}
Complex Complex::add(const Complex& secondComplex)const
{
	double realreal = real + secondComplex.real;
	double imim = imaginary + secondComplex.imaginary;
	Complex C(realreal, imim);
	return C;

}
Complex Complex::subtract(const Complex& secondComplex)const
{
	double realreal = real - secondComplex.real;
	double imim = imaginary - secondComplex.imaginary;
	Complex C(realreal, imim);
	return C;
}
Complex Complex::multiplication(const Complex& secondComplex)const
{
	double realreal = (real * secondComplex.real) - (imaginary*secondComplex.imaginary);
	double imim = (real*secondComplex.imaginary) - (imaginary*secondComplex.real);
	Complex C(realreal, imim);
	return C;
}
Complex Complex::division(const Complex& secondComplex)const
{
	double temp1 = (real*secondComplex.real) + (imaginary*secondComplex.real);
	double temp2 = (imaginary*secondComplex.real) + (real*secondComplex.imaginary);
	double temp3 = (secondComplex.real*secondComplex.real);
	double temp4 = (secondComplex.imaginary*secondComplex.imaginary);
	double div = (temp1 / (temp3 + temp4)) + (temp2 / (temp3 + temp4));
}
Complex Complex::abs(const Complex)const
{
	double temp1 = real*real;
	double temp2 = imaginary*imaginary;
	double absol = sqrt(temp1 + temp2);
}
string Complex::toString()
{
	stringstream ss;
	if(imaginary!=0)
	ss << "(" << real << "+" << imaginary << "i)";
		return ss.str();
}
double Complex::getRealPart()
{
	return real;
}
double Complex::getImaginaryPart()
{
	return imaginary;
}
Complex& Complex::operator+=(const Complex& secondComplex)
{
	real = real + secondComplex.real;
	imaginary = imaginary + secondComplex.getImaginaryPart;
	return *this;
}
Complex& Complex::operator-=(const Complex& secondComplex)
{
	real = real - secondComplex.real;
	imaginary = imaginary - secondComplex.getImaginaryPart;
	return *this;
}
Complex& Complex::operator*=(const Complex& secondComplex)
{
	real = (real*secondComplex.real)-(imaginary*secondComplex.getImaginaryPart);
	imaginary = (real*secondComplex.real) + (imaginary*secondComplex.getImaginaryPart);
	return *this;
}
Complex& Complex::operator/=(const Complex& secondComplex)
{
	real = ((real*secondComplex.real)+(imaginary*secondComplex.imaginary)) / ((secondComplex.real*secondComplex.real) + (secondComplex.imaginary*secondComplex.imaginary));
	imaginary=((imaginary*secondComplex.real)+(real*secondComplex.imaginary))/ ((secondComplex.real*secondComplex.real) + (secondComplex.imaginary*secondComplex.imaginary));
}
double& Complex::operator[](int index)
{
	if (index == 0)
		return real;
	else if (index == 1)
		return imaginary;
}
//Prefix
Complex& Complex:: operator++()
{
	return Complex(++real, imaginary);
}
Complex& Complex::operator--()
{
	return Complex(--real, imaginary);
}
//Postfix
Complex Complex::operator++(int dummy)
{
	return Complex(real++, imaginary);
}
Complex Complex::operator--(int dummy)
{
	return Complex(real--, imaginary);
}
//unary
Complex Complex::operator+()
{
	return Complex(real, imaginary);
}
Complex Complex::operator-()
{
	return Complex(-real, -imaginary);
}
//>><<
ostream& operator<<(ostream& out, const Complex& complex)
{
	out.toString();

}
istream& operator >> (istream& in, Complex& complex)
{
	cout << "Enter in complex number : ";
	in >> complex.getRealPart;
	cout << "Enter in complex number : ";
	in >> complex.getImaginaryPart;
}
//Nonmember function operators
Complex operator+(const Complex& com1, const Complex& com2)
{
	return com1.add(com2);
}
Complex operator-(const Complex& com1, const Complex& com2)
{
	return com1.subtract(com2);
}
Complex operator*(const Complex& com1, const Complex& com2)
{
	return com1.multiplication(com2);
}
Complex operator/(const Complex& com1, const Complex& com2)
{
	return com1.division(com2);
}