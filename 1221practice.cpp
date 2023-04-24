#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,m,p[20][20];
int dp[20][20];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		dp[1][i]=dp[1][i-1]+p[1][i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]+p[i][j]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
