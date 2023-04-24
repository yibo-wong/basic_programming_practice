#include <iostream>
#include <cmath>
using namespace std;
double f1(double y,double u,double x)
{
	return u;
}
double f2(double y,double u,double x)
{
	return 2*u-2*y+exp(x)*sin(x);
}
double h=0.1;
double y_temp(double y,double u,double x)
{
	return y+h*f1(y,u,x);
}
double u_temp(double y,double u,double x)
{
	return u+h*f2(y,u,x);
}
double y_eu(double y,double u,double x)
{
	return y+0.5*h*(f1(y,u,x)+f1(y_temp(y,u,x),u_temp(y,u,x),x+h));
}
double u_eu(double y,double u,double x)
{
	return u+0.5*h*(f2(y,u,x)+f2(y_temp(y,u,x),u_temp(y,u,x),x+h));
}
int main()
{
	double y=0,u=-0.5;
	double x=0;
	for(int i=1;i<=10;i++)
	{
		//cout<<"y temp "<<y_temp(y,u,x)<<endl;
		//cout<<"u temp "<<u_temp(y,u,x)<<endl;
		double ty=y_eu(y,u,x);
		double tu=u_eu(y,u,x);
		y=ty;u=tu;
		x+=h;
		cout<<endl<<x<<"  "<<u<<"  "<<y<<"  "<<endl;
	}
}
