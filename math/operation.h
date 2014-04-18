#pragma once

namespace xe
{
	template<typename T>
	struct operationAble
	{
#pragma region 基本运算
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
#pragma endregion 基本运算

#pragma  region 数值运算
		//操作符在右边
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

		//操作符在左边
		template<typename otherType>
		friend T operator + (const otherType b,const T& a)
		{
			T c = a;
			c += b;
			return c;			
		}

		template<typename otherType>
		friend T operator - (const otherType b,const T& a)
		{
			T c = a;
			c -= b;
			return c;			
		}
		template<typename otherType>
		friend T operator * (const otherType b,const T& a)
		{
			T c = a;
			c *= b;
			return c;			
		}

		template<typename otherType>
		friend T operator / (const otherType b,const T& a)
		{
			T c = a;
			c /= b;
			return c;			
		}
#pragma endregion 数值运算
	};

}