#include "../math/vector3d.h"
#include<iostream>
#include <windows.h>
using namespace std;
void main()
{
	xe::vector3dd a,b,c;
	DWORD n = GetTickCount();
	for(int i=0;i<1000000000;++i)
	{
		a = b * 2;
	}
	DWORD l = GetTickCount();
	cout << l -n;
}