#include <iostream>
#include <algorithm>
using namespace std;
int a[105][105];
int dp[105][105];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	int p;
	dp[1][1]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1]+a[i][1];
		dp[i][i]=dp[i-1][i-1]+a[i][i];
		for(int j=2;j<n;j++) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
	}
	int temp=0;
	for(int i=1;i<=n;i++) temp=max(temp,dp[n][i]);
	cout<<temp;
	return 0;
}
