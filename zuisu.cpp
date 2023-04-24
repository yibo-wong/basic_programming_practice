#include <iostream>
#include <cmath>
using namespace std;
double times(double x1,double x2,double x3,double d1,double d2,double d3)
{
	return 4*x1*d1 + 4*x2*d2 + 4*x3*d3 + 3*x1*d2 + 3*x2*d1 - x2*d3 -x3*d2;
}
void change(double& x1,double& x2,double& x3)
{
	double r1=24-4*x1-3*x2;
	double r2=30-3*x1-4*x2+1*x3;
	double r3=-24+x2-4*x3;
	
	double m=(r1*r1+r2*r2+r3*r3)/times(r1,r2,r3,r1,r2,r3);
	x1+=m*r1;
	x2+=m*r2;
	x3+=m*r3;
}
int main()
{
	double d1=24.0;
	double d2=30.0;
	double d3=-24.0;
	
	double x1=0;
	double x2=0;
	double x3=0;
	
	for(int i=1;i<=100;i++)
	{
		change(x1,x2,x3);
		if(i%2==0) cout<<i<<" "<<x1<<" "<<x2<<" "<<x3<<endl;
	}
	return 0;
}
