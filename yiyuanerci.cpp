#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double delta,x1,x2,i;
float a,b,c;
int casenum;
int main()
{
	cin>>casenum;
	while(casenum--)
	{
		cin>>a>>b>>c;
		delta=1.0*b*b-4.0*a*c;
		if(delta==0)
		{
			x1=-b/(2*a);
			printf("x1=x2=");
			printf("%.5f\n",x1);
		}
		else if(delta>0)
		{
			x1=-b/(2*a)+sqrt(delta)/(2*a);
			x2=-b/(2*a)-sqrt(delta)/(2*a);
			if(a>=0)
			{
			printf("x1=");
			printf("%.5f",x1);
			printf(";x2=");
			printf("%.5f\n",x2);
			}
			else
			{
				printf("x1=");
			printf("%.5f",x2);
			printf(";x2=");
			printf("%.5f\n",x1);
			}
		}
		else
		{
			delta=-delta;
			x1=-b/(2*a);
			x2=-b/(2*a);
			i=sqrt(delta)/(2*a);
			if(a>0)
			{
			printf("x1=");
			printf("%.5f",x1);
			printf("+");
			printf("%.5f",i);
			printf("i;x2=");
			printf("%.5f",x2);
			printf("-");
			printf("%.5f",i);
			printf("i\n");
			}
			else
			{
				i=-i;
				printf("x1=");
			printf("%.5f",x2);
			printf("+");
			printf("%.5f",i);
			printf("i;x2=");
			printf("%.5f",x1);
			printf("-");
			printf("%.5f",i);
			printf("i\n");
			}
		}
		
	}
	return 0;
}
