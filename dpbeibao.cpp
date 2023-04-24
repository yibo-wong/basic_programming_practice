#include <iostream>
#include <algorithm>
using namespace std;
long long int n,x;
long long int lose[1010];
long long int win[1010];
long long int use[1010];
long long int dp[1010];
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>lose[i]>>win[i]>>use[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j>=use[i];j--)
		{
			dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
		}
		for(int j=use[i]-1;j>0;j--)
			dp[j]+=lose[i];
	}
	cout<<dp[x]*5<<endl;
	return 0;
}
