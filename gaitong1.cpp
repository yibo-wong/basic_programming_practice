#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a[40]={0,\
194.8-119.9,101.4-98.5,101.5-93.4,98.1-94.3,\
98.6-92.2,98.2-93,109.3-105.6,127-99.1,\
87.6-78.7,108.7-91.3,113.5-103.9,105.6-113.6,\
117.4-93,98.7-90,78.6-84.1,104-94.1,\
132.3-109.2,86-95.6,94.8-98.7,82.9-88.6,\
85.4-96.4,111-116.3,97-105,105-108.4,\
107.5-111.2,124.6-109.7,96.1-65.7,89.2-76.3,\
95.8-87.3,8-81.7};
double n=30;
double ave()
{
	double sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	return sum/n;
}
double var()
{
	double sum=0;
	double av=ave();
	for(int i=1;i<=n;i++) sum+=(a[i]-av)*(a[i]-av);
	return sqrt(sum/(n-1));
}
double inf()
{
	return ave()-var()*2.02/sqrt(n);
}
double sup()
{
	return ave()+var()*2.02/sqrt(n);
}
double sup1()
{
	double sum=0;
	double av=ave();
	for(int i=1;i<=n;i++) sum+=(a[i]-av)*(a[i]-av);
	return sum/3.3251;
}
int main()
{
	cout<<inf()<<" "<<sup()<<endl;
	return 0;
}

