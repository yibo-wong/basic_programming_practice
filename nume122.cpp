#include <iostream>
#include <cmath>
using namespace std;
double w[5]={1.0/12,4.0/12,2.0/12,4.0/12,1.0/12};
int main()
{
	double x=1.0;
	double y=1.2;
	double sum=0;
	for(int i=0;i<5;i++)
	{
		x=1.0;
		for(int j=0;j<5;j++)
		{
			sum+=w[i]*w[j]*log(x+2*y);
			cout<<w[i]<<" ";
			x+=0.125;
		}
		cout<<endl;
		y+=0.1;
	}
	sum=sum*0.5*0.4;
	cout<<sum<<endl;
	return 0;
}
