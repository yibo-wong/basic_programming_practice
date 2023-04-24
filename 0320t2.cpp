#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int dp[105][1005];
int a[105];
int n,k;
void print()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp[i][j]==inf) cout<<"inf"<<" ";
			else cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	while(1)
	{
		cin>>n>>k;
		if(n==0 && k==0) return 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(dp,inf,sizeof(dp));
		dp[1][a[1]]=1;
		dp[1][0]=0;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=1;
			for(int j=1;j<=k;j++)
			{
				int t=j;
				int p=inf;
				int sum=0;
				while(t-sum*a[i]>=0)
				{
					p=min(p,dp[i-1][t-sum*a[i]]+sum);
					sum++;
				}
				dp[i][j]=p;
			}
		}
		//print();
		if(dp[n][k]!=inf) cout<<dp[n][k]<<endl;
		else cout<<"-1"<<endl;
	}
}
