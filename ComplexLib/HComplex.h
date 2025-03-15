#pragma once
#include <iostream>
#include <complex.h>
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
	T ComplexModule();
	T ComplexDegree();
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

template <class T>
inline TComplex<T>::TComplex(): real(1), imaginary(0)
{}

template <class T>
inline TComplex<T>::TComplex(T real_, T imaginary_) : real(real_), imaginary(imaginary_)
{}

template <class T>
inline TComplex<T>::~TComplex()
{}

template <class T>
inline TComplex<T>::TComplex(TComplex& val)
{
	real = val.GetRe();
	imaginary = val.GetIm();
}

template <class T>
inline T TComplex<T>::GetRe()
{
	return real;
}

template <class T>
inline T TComplex<T>::GetIm()
{
	return imaginary;
}

template <class T>
inline void TComplex<T>::SetRe(T val)
{
	real = val;
}

template <class T>
inline void TComplex<T>::SetIm(T val)
{
	im = val;
}

template<class T>
inline T TComplex<T>::ComplexModule()
{
	return sqrt(real*real + imaginary*imaginary);
}

//template<class T>
//inline T TComplex<T>::ComplexDegree()
//{
//	pow();
//	return;
//}

template<class T>
inline TComplex<T> TComplex<T>::operator + (const TComplex<T>& val)
{
	return TComplex(real + val.real, imaginary + val.imaginary);
}

template<class T>
inline TComplex<T> TComplex<T>::operator - (const TComplex<T>& val)
{
	return TComplex(real - val.real, imaginary - val.imaginary);
}

template<class T>
inline TComplex<T> TComplex<T>::operator * (const TComplex<T>& val)
{
	return TComplex(real * val.real - imaginary * val.imaginary,
		real * val.imaginary + imaginary * val.real);
}

template<class T>
inline TComplex<T> TComplex<T>::operator / (const TComplex<T>& val)
{
	return TComplex((real * val.real + imaginary * val.imaginary)
		/ (val.real * val.real + val.imaginary * val.imaginary),
		(real * val.imaginary + imaginary * val.real)
		/ (val.real * val.real + val.imaginary * val.imaginary));
}

template<class T>
inline TComplex<T>& TComplex<T>::operator+=(const TComplex<T>& val)
{
	real += val.real;
	imaginary += val.imaginary;
	return*this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator -= (const TComplex<T>& val)
{
	real -= val.real;
	imaginary -= val.imaginary;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator *= (const TComplex<T>& val)
{
	T re = real;
	T im = imaginary;
	real = re * val.real - im * val.imaginary;
	imaginary = re * val.imaginary + im * val.real;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator /= (const TComplex<T>& val)
{
	T re = real;
	T im = imaginary;
	real = ((re * val.real) + (im * val.imaginary)) / ((val.real * val.real) + (val.imaginary * val.imaginary));
	imaginary = ((im * val.real) - (re * val.imaginary)) / ((val.real * val.real) + (val.imaginary * val.imaginary));
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator = (const TComplex<T>& val)
{
	real = val.real;
	imaginary = val.imaginary;
	return*this;
}

template<class T>
inline bool TComplex<T>::operator == (const TComplex<T>& val)
{
	return ((this->real == val.real) && (this->imaginary == val.imaginary));
}

template<class T>
inline bool TComplex<T>::operator != (const TComplex<T>& val)
{
	return ((this->real != val.real) || (this->imaginary != val.imaginary));
}


template <class T>
inline ostream& operator << (ostream& out, TComplex<T>& val)
{
	out << "Complex number - " << val.GetRe() << " + " << val.GetIm() << " * i " << endl;
	system("pause");
	system("cls");
	return out;
}

template <class T>
inline istream& operator >> (istream& inp, TComplex<T>& val)
{
	cout << "Enter real - ";
	inp >> val.re;
	cout << "Enter imaginary - ";
	inp >> val.im;
	system("pause");
	system("cls");
	return inp;
}