//-----------------------------------------------------------
// Vector2D.h
//-----------------------------------------------------------

#pragma once

template<class T>
class CVector2D
{
public:
	union
	{
		T v[2];
		struct
		{
			T x;
			T y;
		};
	};

public:
	CVector2D(const T p_tX = 0, const T p_tY = 0);
	~CVector2D();

	//Setter
	void Set(const T p_tX, const T p_tY);

	void Zero();
	void One();

	//Operator overloading
	CVector2D<T> operator=(CVector2D<T> p_ptValue);
	CVector2D<T> operator=(float * p_pfValue);

	CVector2D<T> operator+(CVector2D<T> p_ptValue);
	CVector2D<T> operator+(float * p_pfValue);

	CVector2D<T> operator-(CVector2D<T> p_ptValue);
	CVector2D<T> operator-(float * p_pfValue);

	CVector2D<T> operator*(CVector2D<T> p_ptValue);
	CVector2D<T> operator*(float * p_pfValue);
};

typedef CVector2D<float> CVector2Df;
typedef CVector2D<int> CVector2Di;

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<class T>
inline CVector2D<T> :: CVector2D(const T p_tX, const T p_tY)
{
	x = p_tX;
	y = p_tY;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<class T>
inline CVector2D<T> :: ~CVector2D()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline void CVector2D<T> ::Set(const T p_tX, const T p_tY)
{
	this->x = p_tX;
	this->y = p_tY;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline void CVector2D<T> ::Zero()
{
	this->x = 0;
	this->y = 0;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline void CVector2D<T> ::One()
{
	this->x = 1;
	this->y = 1;
}


//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator=(CVector2D<T> p_ptValue)
{
	this->x = p_ptValue.x;
	this->y = p_ptValue.y;
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator=(float * p_pfValue)
{
	this->x = p_pfValue[0];
	this->y = p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator+(CVector2D<T> p_ptValue)
{
	this->x += p_pfValue[0];
	this->y += p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator+(float * p_pfValue)
{
	this->x += p_pfValue[0];
	this->y += p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator-(CVector2D<T> p_ptValue)
{
	this->x -= p_pfValue[0];
	this->y -= p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator-(float * p_pfValue)
{
	this->x -= p_pfValue[0];
	this->y -= p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator*(CVector2D<T> p_ptValue)
{
	this->x *= p_pfValue[0];
	this->y *= p_pfValue[1];
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: operator*(float * p_pfValue)
{
	this->x *= p_pfValue[0];
	this->y *= p_pfValue[1];
	return *this;
}

