#include <iostream>
#include <cmath>
using namespace std;
double f(double x,double y)
{
	return 1-2*x*y/(1+x*x);
}
double h=0.5;
double rk(double x,double y)
{
	double k1=f(x,y);
	cout<<"k1 "<<k1<<endl;
	double k2=f(x+h/2,y+0.5*h*k1);
	cout<<"k2 "<<k2<<endl;
	double k3=f(x+h/2,y+0.5*h*k2);
	cout<<"k3 "<<k3<<endl;
	double k4=f(x+h,y+h*k3);
	cout<<"k4 "<<k4<<endl;
	return y+h*(k1+2*k2+2*k3+k4)/6;
}
int main()
{
	double x=0,y=0;
	for(int i=1;i<=5;i++)
	{
		y=rk(x,y);
		x+=h;
		cout<<x<<"  "<<y<<endl;
	}
}
