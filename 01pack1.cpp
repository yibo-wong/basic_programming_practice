#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10010
int dp[maxn]={0};
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
		for(int j=m;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[20]<<endl;
	return 0;
}
