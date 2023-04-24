#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t[1005];
int w[1005];
int dp[1005];
int a[1005];
int main()
{
	int tot,n;
	cin>>tot>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>w[i];
	}
	dp[t[1]]=w[1];
	a[t[1]]=1;
	a[0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=tot;j>=t[i];j--)
		{
			if(a[j-t[i]])
				{
					dp[j]=max(dp[j],dp[j-t[i]]+w[i]);
					a[j]=1;
			    }
		}
	}
	if(a[tot])
		cout<<dp[tot];
	else
		cout<<"-1";
	return 0;
}
