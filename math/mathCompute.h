#pragma once
#include "vector3d.h"
namespace xe
{
	//! �������������
	template<typename T,int dimension>
	T computeTriangleArea(vector<T,dimension>& p1,vector<T,dimension>& p2,vector<T,dimension>& p3)
	{
		typedef vector<T,dimension> vec;
		vec v1 = p2 - p1;
		vec v2 = p3 - p1;
		return v1.crossProduct(v2).getLength()/2;
	}

	//! ��ȡ����a������b�ϵ�ͶӰ
	template<typename T,int dimension>
	inline vector<T,dimension> getProjection(vector<T,dimension>& a,vector<T,dimension>& b)
	{
		typedef vector<T,dimension> vec;
		return (a.dotProduct(b)/b.getLengthSQ()) * b;

	}

	//! ��ȡ����a������b�ϵ�ͶӰ
	template<typename T,int dimension>
	inline vector<T,dimension> getPerpendicular(vector<T,dimension>& a,vector<T,dimension>& b)
	{
		typedef vector<T,dimension> vec;
		return a - getProjection(a,b);

	}

}