#include <iostream>
#include <algorithm>
using namespace std;
int tot,n;
int w[1050],p[1050];
int dp[1050];
int main()
{
	cin>>tot>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=tot;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		}
	}
	cout<<dp[tot]<<endl;
	return 0;
}
