#include <iostream>
#include <cmath>
using namespace std;
double a0=0;
double a1=0;
double lam,a2;
double change(double& x1,double& x2,double& x3)
{
	double m1=4*x1-1*x2+1*x3;
	double m2=-1*x1+3*x2-2*x3;
	double m3=x1-2*x2+3*x3;
	x1=m1;x2=m2;x3=m3;
	//cout<<x1<<"  "<<x2<<"  "<<x3<<endl;
	int n=1;
	if(abs(x1)<abs(x2)) n=2;
	if(abs(x2)<abs(x3)) n=3;
	double m=0;
	if(n==1) m=x1;
	if(n==2) m=x2;
	if(n==3) m=x3;
	x1=x1/m;
	x2=x2/m;
	x3=x3/m;
	a2=m;
	lam=a0-(a1-a0)*(a1-a0)/(a2-2*a1+a0);
	a0=a1;
	a1=a2;
	return lam;
}
int main()
{
	double x1,x2,x3,k;
	x1=1;
	x2=x3=0;
	for(int i=1;i<=100;i++)
	{
		k=change(x1,x2,x3);
		cout<<i<<":"<<x1<<" "<<x2<<" "<<x3<<" "<<k<<endl;
	}
}
