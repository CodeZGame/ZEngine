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

	static CVector2D<T> Zero;
	static CVector2D<T> One;

	//Operator overloading
	CVector2D<T> operator=(CVector2D<T> p_ptValue);
	CVector2D<T> operator=(float * p_pfValue);

	CVector2D<T> operator+(CVector2D<T> p_ptValue);
	CVector2D<T> operator+(float * p_pfValue);

	CVector2D<T> operator-(CVector2D<T> p_ptValue);
	CVector2D<T> operator-(float * p_pfValue);

	CVector2D<T> operator*(CVector2D<T> p_ptValue);
	CVector2D<T> operator*(float * p_pfValue);

	bool operator==(CVector2D<T> p_ptValue) const;
	bool operator==(float * p_pfValue) const;

	bool operator!=(CVector2D<T> p_ptValue) const;
	bool operator!=(float * p_pfValue) const;
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
inline void CVector2D<T> :: Set(const T p_tX, const T p_tY)
{
	this->x = p_tX;
	this->y = p_tY;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: Zero = CVector2D<T>(0.0f, 0.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
CVector2D<float> CVector2D<float> :: Zero = CVector2D<float>(0.0f, 0.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
CVector2D<int> CVector2D<int> :: Zero = CVector2D<int>(0, 0);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
CVector2D<T> CVector2D<T> :: One = CVector2D<T>(1.0f, 1.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
CVector2D<float> CVector2D<float> :: One = CVector2D<float>(1.0f, 1.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
CVector2D<int> CVector2D<int> :: One = CVector2D<int>(1, 1);

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
	this->x += p_ptValue.x;
	this->y += p_ptValue.y;
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
	this->x -= p_ptValue.x;
	this->y -= p_ptValue.y;
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
	this->x *= p_ptValue.x;
	this->y *= p_ptValue.y;
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

//COMPARISON OPERATORS

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool CVector2D<T> :: operator==(CVector2D<T> p_ptValue) const
{
	return (this->x == p_ptValue.x && this->y == p_ptValue.y);
}


//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool CVector2D<T> :: operator==(float * p_pfValue) const
{
	return (this->x == p_pfValue[0] && this->y == p_pfValue[1]);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool CVector2D<T> :: operator!=(CVector2D<T> p_ptValue) const
{
	return (this->x != p_ptValue.x && this->y != p_ptValue.y);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool CVector2D<T> :: operator!=(float * p_pfValue) const
{
	return (this->x != p_pfValue[0] && this->y != p_pfValue[1]);
}