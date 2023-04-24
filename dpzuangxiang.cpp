#include <iostream>
#include <algorithm>
using namespace std;
int n,tot;
int w[32];
int dp[20010];
int main()
{
	cin>>tot>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=tot;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
		}
	}
	cout<<tot-dp[tot];
	return 0;
}

