#include <iostream>
#include <cmath>
#define E 2.71828182845904523536
using namespace std;
double x1,x2;
double f(double x)
{
	return x*pow(E,x)-1;
}
int main()
{
	x1=0.0;
	x2=1.0;
	for(int i=1;i<=20;i++)
	{
		if(f((x1+x2)/2.0)<0) cout<<"- ";
		else cout<<"+ ";
		if(f((x1+x2)/2.0)<0) x1=(x1+x2)/2.0;
		else x2=(x1+x2)/2.0;
		cout<<i<<" "<<x1<<" "<<x2<<endl;
	}
}
