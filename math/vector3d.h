#pragma once
#include"type.h"
#include "operation.h"
namespace xe
{
	template<typename T,int dimension>
	class vector;

	template<typename T>
	class vector<T,3>:public operationAble<vector<T,3>>
	{
	public:
		T x,y,z;
		vector(T _x=0,T _y=0,T _z=0):x(_x),y(_y),z(_z)
		{

		}
#pragma region 四则运算
		inline void operator += ( const vector& o)
		{
			this->x+=o.x;
			this->y+=o.y;
			this->z+=o.z;
		}

		inline void operator -= (const vector& o)
		{
			this->x-=o.x;
			this->y-=o.y;
			this->z-=o.z;
		}
		inline void operator *= ( const vector& o)
		{
			this->x*=o.x;
			this->y*=o.y;
			this->z*=o.z;
		}

		inline void operator /= (const vector& o)
		{
			this->x/=o.x;
			this->y/=o.y;
			this->z/=o.z;
		}
		template<typename otherType>
		inline void operator += ( const otherType o)
		{
			this->x+=o;
			this->y+=o;
			this->z+=o;
		}

		template<typename otherType>
		inline void operator -= (const otherType o)
		{
			this->x-=o;
			this->y-=o;
			this->z-=o;
		}
		template<typename otherType>
		inline void operator *= ( const otherType o)
		{
			this->x*=o;
			this->y*=o;
			this->z*=o;
		}

		template<typename otherType>
		inline void operator /= (const otherType o)
		{
			this->x/=o;
			this->y/=o;
			this->z/=o;
		}



		inline void operator - ()
		{
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
		}
#pragma endregion 四则运算
#pragma region 向量运算
		inline auto getLength() -> decltype(sqrt(x))
		{
			return sqrt(x*x + y*y + z*z);
		}

		inline T getLengthSQ()
		{
			return x*x + y*y + z*z;
		}
		inline T dotProduct(const vector& o)
		{
			return x*o.x + y*o.y + z*o.z;
		}
		inline vector crossProduct(const vector& o)
		{
			vector r;
			r.x = y*o.z - z*o.y;
			r.y = z*o.x - x*o.z;
			r.z = x*o.y - y*o.x;
			return r; 
		}

#pragma endregion 向量运算
	};
	template<typename T>
	class vector<T,2>
	{
	public:
		T x,y;


		friend vector operator + (const vector& a , const vector& b)
		{
			vector r;
			r.x = a.x+b.x;
			r.y = a.y+b.y;
			return r;
		}
	};

	typedef vector<f64,2> vector2dd;
	typedef vector<f32,2> vector2df;
	typedef vector<i32,2> vector2di;

	typedef vector<f64,3> vector3dd;
	typedef vector<f32,3> vector3df;
	typedef vector<i32,3> vector3di;

}