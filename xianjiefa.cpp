#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double a[20],b[20];
double f1(double x,double y)
{
	return 2*(x*x+x+3*y-y*y);
}
double f2(double x,double y)
{
	return x*x*x+x*x-x*y*y+5*x+y*y-2*y+5;
}
double f3(double x,double y)
{
	return x*x*y+3*x*x+2*x-y*y*y+3*y*y-5*y+15;
}

int main()
{
	a[0]=b[0]=1;
	for(int i=1;i<=20;i++)
	{
		a[i]=f2(a[i-1],b[i-1])/f1(a[i-1],b[i-1]);
		b[i]=f3(a[i-1],b[i-1])/f1(a[i-1],b[i-1]);
		cout<<a[i]<<" "<<b[i]<<endl;
	}
	return 0;
}
