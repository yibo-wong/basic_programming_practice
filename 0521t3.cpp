#include <iostream>
#include <cstring>
using namespace std;
int n,a[1050];
int dp[1050];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=a[i];
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j]) dp[i]=max(dp[j]+a[i],dp[i]);
		}
	}
	int t=0;
	for(int i=1;i<=n;i++) t=max(t,dp[i]);
	cout<<t<<endl;
	return 0;
}
