#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* s,T* e)
{
	T tmp=*s;
	T* p;
	for(p=++s;p<e;p++)
	{
		tmp=tmp + *p;
	}
	return tmp;
}

int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //ÌáÊ¾£º1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}
