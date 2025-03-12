#include "HComplex.h"

template <class T>
inline TComplex<T>::TComplex()
{}

template <class T>
inline TComplex<T>::TComplex(T real_, T imaginary_): real(real_), imaginary(imaginary_)
{}

template <class T>
inline TComplex<T>::~TComplex()
{}

template <class T>
inline TComplex<T>::TComplex(TComplex& val)
{
	re = val.GetRe();
	im = val.GetIm();
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
	real = real * val.real - imaginary * val.imaginary;
	imaginary = real * val.imaginary + imaginary * val.real;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator /= (const TComplex<T>& val)
{
	real = real * val.real - imaginary * val.imaginary;
	imaginary = real * val.imaginary + imaginary * val.real;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator = (const TComplex<T>& val)
{
	real = val.real;
	imaginary = val.imaginary;
	return(real, imaginary);
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
	out << "Ñomplex number - " << val.GetRe() << " + " << val.GetIm() << " * i " << endl;
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