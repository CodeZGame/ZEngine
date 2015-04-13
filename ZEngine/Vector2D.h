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
		CVector2D(const int p_tX = 0, const int p_tY = 0);
		~CVector2D();

		//Setter
		void Set(const T p_tX, const T p_tY);
	};
}

