#include <iostream>
#include <cmath>
using namespace std;
double times(double x1,double x2,double x3,double d1,double d2,double d3)
{
	return 4*x1*d1 + 4*x2*d2 + 4*x3*d3 + 3*x1*d2 + 3*x2*d1 - x2*d3 -x3*d2;
}
void change(double& x1,double& x2,double& x3,double& d1,double& d2,double& d3)
{
	double r1=24-4*x1-3*x2;
	double r2=30-3*x1-4*x2+1*x3;
	double r3=-24+x2-4*x3;
	
	double beta=-(times(r1,r2,r3,d1,d2,d3))/(times(d1,d2,d3,d1,d2,d3));
	cout<<"beta "<<beta<<endl;
	d1=r1+beta*d1;
	d2=r2+beta*d2;
	d3=r3+beta*d3;
	cout<<"d "<<d1<<" "<<d2<<" "<<d3<<endl;
	double lam=(r1*d1+r2*d2+r3*d3)/times(d1,d2,d3,d1,d2,d3);
	cout<<"lam "<<lam<<endl;
	x1+=lam*d1;
	x2+=lam*d2;
	x3+=lam*d3;
	return;
}
int main()
{
	double d1=24.0;
	double d2=30.0;
	double d3=-24.0;
	
	double x1=3.526;
	double x2=4.407;
	double x3=-3.526;
	
	for(int i=1;i<=100;i++)
	{
		change(x1,x2,x3,d1,d2,d3);
		cout<<x1<<" "<<x2<<" "<<x3<<endl;
	}
	return 0;
}
