#pragma once
#include"type.h"
namespace xe
{
	template<typename T,int dimension>
	class vector;
	template<typename T>
	struct opeartionAble
	{
#pragma region ��������
		friend T operator + (const T& a,const T& b)
		{
			T c = a;
			c += b;
			return c;			
		}

		friend T operator - (const T& a,const T& b)
		{
			T c = a;
			c -= b;
			return c;			
		}
		friend T operator * (const T& a,const T& b)
		{
			T c = a;
			c *= b;
			return c;			
		}

		friend T operator / (const T& a,const T& b)
		{
			T c = a;
			c /= b;
			return c;			
		}
#pragma endregion ��������

#pragma  region ��ֵ����
		template<typename otherType>
		friend T operator + (const T& a,const otherType b)
		{
			T c = a;
			c += b;
			return c;			
		}

		template<typename otherType>
		friend T operator - (const T& a,const otherType b)
		{
			T c = a;
			c -= b;
			return c;			
		}
		template<typename otherType>
		friend T operator * (const T& a,const otherType b)
		{
			T c = a;
			c *= b;
			return c;			
		}

		template<typename otherType>
		friend T operator / (const T& a,const otherType b)
		{
			T c = a;
			c /= b;
			return c;			
		}
#pragma endregion ��ֵ����
	};

	template<typename T>
	class vector<T,3>:public opeartionAble<vector<T,3>>
	{
	public:
		T x,y,z;
#pragma region ��������
		void operator += ( const vector& o)
		{
			this->x+=o.x;
			this->y+=o.y;
			this->z+=o.z;
		}

		void operator -= (const vector& o)
		{
			this->x-=o.x;
			this->y-=o.y;
			this->z-=o.z;
		}
		void operator *= ( const vector& o)
		{
			this->x*=o.x;
			this->y*=o.y;
			this->z*=o.z;
		}

		void operator /= (const vector& o)
		{
			this->x/=o.x;
			this->y/=o.y;
			this->z/=o.z;
		}
		template<typename otherType>
		void operator += ( const otherType o)
		{
			this->x+=o;
			this->y+=o;
			this->z+=o;
		}

		template<typename otherType>
		void operator -= (const otherType o)
		{
			this->x-=o;
			this->y-=o;
			this->z-=o;
		}
		template<typename otherType>
		void operator *= ( const otherType o)
		{
			this->x*=o;
			this->y*=o;
			this->z*=o;
		}

		template<typename otherType>
		void operator /= (const otherType o)
		{
			this->x/=o;
			this->y/=o;
			this->z/=o;
		}



		void operator - ()
		{
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
		}
#pragma endregion ��������
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