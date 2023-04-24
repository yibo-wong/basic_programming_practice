#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 1000000
using namespace std;
int dp[22][22];
int a[22][22];
int m,n,temp,maxs,final;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		dp[i][1]=1-a[i][1];
	}
	for(int j=2;j<=n;j++)
	{
		for(int i=1;i<=m;i++)
		{
			if(a[i][j]==0) dp[i][j]=dp[i][j-1]+1;
			else dp[i][j]=0;
		}
	}
	final=0;
	for(int j=1;j<=n;j++)
	{
		final=max(final,dp[1][j]);
	}
	if(m==1)
	{
		cout<<final<<endl;
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=2;i<=m;i++)
		{
			temp=inf;maxs=0;
			for(int k=i;i>=1;k--)
			{
				temp=min(temp,dp[k][j]);
				maxs=max(maxs,temp*(i-k+1));
				if(temp==0) break;
			}
			final=max(final,maxs);
		}
	}
	cout<<final<<endl;
	return 0;
}
