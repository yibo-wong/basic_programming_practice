#include <iostream>
using namespace std;
int a[1050];
int n;
int dp1[1050],dp2[1050];
int temp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp1[1]=1;
	for(int i=2;i<=n;i++)
	{
		temp=0;
		for(int j=1;j<i;j++)
		{
			if(dp1[j]>temp&&a[j]<a[i]) temp=dp1[j];
		}
		dp1[i]=temp+1;
	}
	dp2[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		temp=0;
		for(int j=n;j>i;j--)
		{
			if(dp2[j]>temp&&a[j]<a[i]) temp=dp2[j];
		}
		dp2[i]=temp+1;
	}
	temp=0;
	for(int i=1;i<=n;i++)
	{
		if(dp1[i]+dp2[i]>temp) temp=dp1[i]+dp2[i];
	}
	cout<<temp-1<<endl;
	return 0;
}
