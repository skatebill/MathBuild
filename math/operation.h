#pragma once

namespace xe
{
	template<typename T>
	struct operationAble
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
		//���������ұ�
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

		//�����������
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
#pragma endregion ��ֵ����
	};

}