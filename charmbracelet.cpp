#include <iostream>
#include <algorithm>
using namespace std;
int w[5000],p[5000];
int dp[12900];
int m,n;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i]>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
	}
	cout<<dp[m]<<endl;
	return 0;
}
