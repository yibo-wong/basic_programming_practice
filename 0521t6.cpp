#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,sum;
int a[22],dp[22][1050];
int main()
{
	cin>>n>>sum;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[1][a[1]]=1;dp[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=sum;j++)
		{
			if(j>=a[i]) dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][sum]<<endl;
	return 0;
}
