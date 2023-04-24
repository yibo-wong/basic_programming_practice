#include <iostream>
#include <vector>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int dp[(1<<16)+2][16];
int n,a[18][18];
vector<int>q[17];
int sum(int x)
{
	int ans=0;
	for(int i=0;i<16;i++) ans+=(x>>i)&1;
	return ans;
}
void make()
{
	for(int i=1;i<=(1<<16)-1;i++) q[sum(i)].push_back(i);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	int maxn=(1<<n)-1;
	make();
	memset(dp,inf,sizeof(dp));
	dp[1][0]=0;
	int minx;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			int cur=q[i][j];
			for(int k=0;k<n;k++)
			{
				minx=inf;
				if((cur>>k)&1)
				{
					for(int s=0;s<n;s++)
					{
						minx=min(minx,dp[cur-(1<<k)][s]+a[s][k]);
					}
					dp[cur][k]=minx;
				}
			}
		}
	}
	cout<<dp[maxn][n-1]<<endl;
}
