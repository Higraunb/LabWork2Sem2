#pragma once
#include <iostream>
using namespace std;
template <class T>
class TComplex
{
public:
	TComplex();
	TComplex(T real_, T imaginary_);
	TComplex(TComplex<T>& val);
	~TComplex();
	T GetRe();
	T GetIm();
	void SetRe(T val);
	void SetIm(T val);
	TComplex operator + (const TComplex<T>& val);
	TComplex operator - (const TComplex<T>& val);
	TComplex operator * (const TComplex<T>& val);
	TComplex operator / (const TComplex<T>& val);
	TComplex& operator += (const TComplex<T>& val);
	TComplex& operator -= (const TComplex<T>& val);
	TComplex& operator *= (const TComplex<T>& val);
	TComplex& operator /= (const TComplex<T>& val);
	TComplex& operator = (const TComplex<T>& val);
	bool operator == (const TComplex<T>& val);
	bool operator != (const TComplex<T>& val);

	template <class T>
	friend ostream& operator << (ostream& out, TComplex<T>& val);
	template <class T>
	friend istream& operator >> (istream& inp, TComplex<T>& val);
	
private:
	T real, imaginary;
};