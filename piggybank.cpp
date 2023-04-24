#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10050],p[10050],w[10050];
bool a[10050];
int n,totalcases,e,f,tot;
int main()
{
	cin>>totalcases;
	while(totalcases--)
	{
		cin>>e>>f;
		cin>>n;
		tot=f-e;
		memset(dp,-1,sizeof(dp));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>p[i]>>w[i];
		}
		dp[0]=0;a[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=w[i];j<=tot;j++)
			{
				if(a[j-w[i]]==1)
				{
					a[j]=1;
					if(dp[j]==-1) dp[j]=dp[j-w[i]]+p[i];
					else dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
				}
			}
		}
		if(dp[tot]==-1)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[tot]<<"."<<endl;
	}
	return 0;
}
