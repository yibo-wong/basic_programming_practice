#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x=0.001;
	double y1=tan(x)*tan(x);
	y1=y1*y1;
	double y2=sqrt(1-0.5*x*sin(x));
	double y3=sqrt(cos(x));
	double ans=(y1)/(y2-y3);
	cout<<ans<<endl;
	return 0;
}
