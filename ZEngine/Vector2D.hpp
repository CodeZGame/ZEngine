//-----------------------------------------------------------
// Vector2D.h
//-----------------------------------------------------------

#pragma once

namespace ZEngine
{
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
	};

	template<class T>
	CVector2D<T> ::CVector2D(const T p_tX, const T p_tY)
	{
		x = p_tX;
		y = p_tY;
	}

	template<class T>
	CVector2D<T> :: ~CVector2D()
	{
	}

	template<typename T>
	void CVector2D<T> ::Set(const T p_tX, const T p_tY)
	{
		this->x = p_tX;
		this->y = p_tY;
	}
}

