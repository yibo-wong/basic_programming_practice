#include <iostream>
#include <cstdio>
using namespace std;
double p[100050];
double dp[100050];
double m[100050];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	m[1]=p[1];dp[1]=1.0;
	for(int i=2;i<=n;i++)
	{
		if(p[i]<m[i-1])
		{
			dp[i]=1.0;
			m[i]=p[i];
		}
		else 
		{
			m[i]=m[i-1];
			dp[i]=1.0*p[i]/m[i];
		}
	}
	double temp=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]>temp) temp=dp[i];
	}
	temp=temp*100;
	printf("%.2f",temp);
	return 0;
}
