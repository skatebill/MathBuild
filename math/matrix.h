#pragma once
#include"vector3d.h"
#include "operation.h"
#include<memory.h>
namespace xe
{

	template<typename T>
	class matrix4:public operationAble<matrix4<T>>
	{
	public:
#pragma region ����ö�ٺͶ���
		enum EnumMatrixBuildType
		{
			Indentity=0,
			Copy,
			Inverse,
			Transpose,
			EMBT_COUNT
		};
		enum {
			StructSize = sizeof(T) * 16
		};
		typedef vector<T,3> vec;
#pragma endregion ����ö�ٺͶ���
#pragma region ���캯��
		matrix4()
		{
			memset(m,0,StructSize);
			m[0] = (T)1;
			m[5] = (T)1;
			m[10] = (T)1;
			m[15] = (T)1;
		}

		matrix4(const matrix4& other,EnumMatrixBuildType type = Copy)
		{
			switch(type)
			{
			case Inverse:
				other.getInverse(*this);
				break;
			case Transpose:
				other.getTranspose(*this);
				break;
			case Copy:
				memcpy(m,other.m,StructSize);
				break;
			default:
				break;
			}
		}

		matrix4& operator = (const matrix4& other)
		{
			memcpy(m,other.m,StructSize);
			return *this;
		}

#pragma endregion ���캯��
#pragma region ����任

		inline void getInverse(matrix4& out) const
		{

		}
		inline void getTranspose(matrix4& out) const
		{

		}
#pragma endregion ����任
#pragma region ���ݶ�ȡ����
		T m[16];
		inline T& operator ()(u32 x,u32 y)
		{
			return m[4*y +x];
		}
#pragma endregion ���ݶ�ȡ����
#pragma region ��������
		inline void operator += (const matrix4& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]+=o.m[i];
			}
		}

		inline void operator -= (const matrix4& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]-=o.m[i];
			}
		}
		inline void operator *= (const matrix4& o)
		{
			matrix4 temp(*this);
			const T* m1 = temp.m;
			const T* m2 = o.m;
			//��һ��
			m[0] = m1[0] * m2[0] + m1[1] * m2[4] + m1[2] * m2[8] + m1[3] * m2[12];
			m[1] = m1[0] * m2[1] + m1[1] * m2[5] + m1[2] * m2[9] + m1[3] * m2[13];
			m[2] = m1[0] * m2[2] + m1[1] * m2[6] + m1[2] * m2[10] + m1[3] * m2[14];
			m[3] = m1[0] * m2[3] + m1[1] * m2[7] + m1[2] * m2[11] + m1[3] * m2[15];
			//�ڶ���
			m[4] = m1[4] * m2[0] + m1[5] * m2[4] + m1[6] * m2[8] + m1[7] * m2[12];
			m[5] = m1[4] * m2[1] + m1[5] * m2[5] + m1[6] * m2[9] + m1[7] * m2[13];
			m[6] = m1[4] * m2[2] + m1[5] * m2[6] + m1[6] * m2[10] + m1[7] * m2[14];
			m[7] = m1[4] * m2[3] + m1[5] * m2[7] + m1[6] * m2[11] + m1[7] * m2[15];
			//������
			m[8] = m1[8] * m2[0] + m1[9] * m2[4] + m1[10] * m2[8] + m1[11] * m2[12];
			m[9] = m1[8] * m2[1] + m1[9] * m2[5] + m1[10] * m2[9] + m1[11] * m2[13];
			m[10] = m1[8] * m2[2] + m1[9] * m2[6] + m1[10] * m2[10] + m1[11] * m2[14];
			m[11] = m1[8] * m2[3] + m1[9] * m2[7] + m1[10] * m2[11] + m1[11] * m2[15];
			//������
			m[12] = m1[12] * m2[0] + m1[13] * m2[4] + m1[14] * m2[8] + m1[15] * m2[12];
			m[13] = m1[12] * m2[1] + m1[13] * m2[5] + m1[14] * m2[9] + m1[15] * m2[13];
			m[14] = m1[12] * m2[2] + m1[13] * m2[6] + m1[14] * m2[10] + m1[15] * m2[14];
			m[15] = m1[12] * m2[3] + m1[13] * m2[7] + m1[14] * m2[11] + m1[15] * m2[15];

		}
		/* ����任û�г�����˵��
		inline void operator /= (const matrix4& o)
		{
		for(u32 i=0;i<16;++i)
		{
		m[i]/=o.m[i];
		}
		}*/

		template<typename otherType>
		inline void operator += (const otherType& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]+=o;
			}
		}

		template<typename otherType>
		inline void operator -= (const otherType& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]-=o;
			}
		}

		template<typename otherType>
		inline void operator *= (const otherType& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]*=o;
			}
		}

		template<typename otherType>
		inline void operator /= (const otherType& o)
		{
			for(u32 i=0;i<16;++i)
			{
				m[i]/=o;
			}
		}

#pragma endregion ��������
#pragma region �任������
		void buildTrasform(vec trans)
		{
			makeIdentity();
			m[4] = trans.x;
			m[8] = trans.y;
			m[12] = trans.z;
		}
		void buildTrasform(T x,T y,T z)
		{
			makeIdentity();
			m[4] = x;
			m[8] = y;
			m[12] = z;
		}
		void makeIdentity()
		{
			memset(m,0,StructSize);
			m[0] = (T)1;
			m[5] = (T)1;
			m[10] = (T)1;
			m[15] = (T)1;
		}
#pragma endregion �任������
	};

}