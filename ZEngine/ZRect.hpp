//-----------------------------------------------------------
// Rect.h
//-----------------------------------------------------------

#pragma once

template<class T>
class ZRect
{
public:
	union
	{
		T rect[4];
		struct
		{
			T left;
			T top;
			T width;
			T height;
		};
	};

public:
	ZRect(const T p_Top = 0, const T p_Left = 0, const T p_Width = 0, const T p_Height = 0);
	//Copy construct
	ZRect(const ZRect<T> & p_Rect);
	~ZRect();

	void Set(const T p_Top = 0, const T p_Left = 0, const T p_Width = 0, const T p_Height = 0);

	static ZRect<T> Zero;

	ZRect<T> operator=(ZRect<T> p_ptValue);
	ZRect<T> operator=(float * p_pfValue);

	bool operator==(ZRect<T> p_ptValue) const;

	bool operator!=(ZRect<T> p_ptValue) const;
};

typedef ZRect<float> ZRectf;
typedef ZRect<int> ZRecti;

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<class T>
inline ZRect<T> :: ZRect(const T p_Top /* = 0 */, const T p_Left /* = 0 */, const T p_Width /* = 0 */, const T p_Height /* = 0 */)
{
	top = p_Top;
	left = p_Left;
	width = p_Width;
	height = p_Height;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<class T>
inline ZRect<T> ::ZRect(const ZRect<T> & p_Rect)
	:	top(p_Rect.top),
		left(p_Rect.left),
		width(p_Rect.width),
		height(p_Rect.height)
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<class T>
inline ZRect<T> :: ~ZRect()
{
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline void ZRect<T> :: Set(const T p_Top /* = 0 */, const T p_Left /* = 0 */, const T p_Width /* = 0 */, const T p_Height /* = 0 */)
{
	top = p_Top;
	left = p_Left;
	width = p_Width;
	height = p_Height;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
ZRect<T> ZRect<T> :: Zero = ZRect<T>(0.0f, 0.0f, 0.0f, 0.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
ZRect<float> ZRect<float> :: Zero = ZRect<float>(0.0f, 0.0f, 0.0f, 0.0f);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<>
ZRect<int> ZRect<int> :: Zero = ZRect<int>(0, 0, 0, 0);

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
ZRect<T> ZRect<T> :: operator=(ZRect<T> p_ptValue)
{
	this->top = p_ptValue.top;
	this->left = p_ptValue.left;
	this->width = p_ptValue.width;
	this->height = p_ptValue.height;
	return *this;
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool ZRect<T> :: operator==(ZRect<T> p_ptValue) const
{
	return (this->top == p_ptValue.top && this->left == p_ptValue.left &&
			this->width == p_ptValue.width && this->height == p_ptValue.height);
}

//-----------------------------------------------------------
//
//----------------------------------------------------------
template<typename T>
inline bool ZRect<T> :: operator!=(ZRect<T> p_ptValue) const
{
	return (this->top != p_ptValue.top && this->left != p_ptValue.left &&
			this->width != p_ptValue.width && this->height != p_ptValue.height);
}