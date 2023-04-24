#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1020][510];
int hp[1020][510];
int p1[110],p2[110];
int n,m,k,temp,res,r;
int main()
{
	cin>>n>>m>>k;
	temp=0;
	for(int i=1;i<=k;i++) cin>>p1[i]>>p2[i];
	for(int s=1;s<=k;s++)
	{
		for(int i=n;i>=p1[s];i--)
		{
			for(int j=m;j>=p2[s];j--)
			{
				dp[i][j]=max(dp[i][j],dp[i-p1[s]][j-p2[s]]+1);
			}
		}
	}
	cout<<dp[n][m]<<" ";
	for(int i=0;i<=m;i++)
	{
		if(dp[n][i]==dp[n][m])
		{
			cout<<m-i<<endl;
			break;
		}
	}
	return 0;
}
