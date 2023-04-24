#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[110],temp;
int dp1[110],dp2[110];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp1[1]=1;
	for(int i=2;i<=n;i++)
	{
		temp=1;
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				temp=max(temp,dp1[j]+1);
			}
		}
		dp1[i]=temp;
	}
	dp2[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		temp=1;
		for(int j=n;j>i;j--)
		{
			if(a[j]<a[i])
			{
				temp=max(temp,dp2[j]+1);
			}
		}
		dp2[i]=temp;
	}
	temp=0;
	for(int i=1;i<=n;i++)
	{
		temp=max(temp,dp1[i]+dp2[i]-1);
	}
	cout<<n-temp<<endl;
	return 0;
}
