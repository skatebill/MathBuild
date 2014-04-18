#include "../math/mathCompute.h"
#include "../math/matrix.h"
#include<iostream>
#include <windows.h>
using namespace std;
void main()
{
	//xe::vector3dd a,b,c;
	xe::vector3dd a(0,0,0),b(1,0,0),c(1,1,0);
	DWORD n = GetTickCount();
	//for(int i=0;i<10000000;++i)
	//{
	//	xe::computeTriangleArea(a,b,c);
	//}
	//auto d = xe::getProjection(c,b);
	//d = xe::getPerpendicular(c,b);
	//DWORD l = GetTickCount();
	//cout << l -n;
	using namespace xe;
	matrix4<double> m1,m2,m3;
	m1.buildTrasform(10,0,0);
	m2.buildTrasform(0,10,10);
	m3 = m2 * m1;
	system("pause");
}