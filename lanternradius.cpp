#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,len;
long long int a[1050];
int main()
{
	cin>>n>>len;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[0]=0;
	a[n+1]=len;
	sort(a,a+n+2);
	long long int m=0;
	for(int i=2;i<=n;i++)
	{
		m=max(m,a[i]-a[i-1]);
	}
	m=max(m,2*(a[n+1]-a[n]));
	m=max(m,2*a[1]);
	double d;
	d=1.0*m/2;
	printf("%.10f",d);
	return 0;
}
