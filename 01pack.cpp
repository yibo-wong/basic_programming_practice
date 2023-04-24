#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10010
int dp[maxn][maxn]={0};
int w[maxn]={0};
int v[maxn]={0};
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		{
			if(w[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

