#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int testnum,n,a[100050];
int dp[100050][5];
int main()
{
	cin>>testnum;
	while(testnum--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) dp[i][0]=-a[i];
		for(int i=2;i<=n;i++) dp[i][0]=max(dp[i][0],dp[i-1][0]);
		for(int i=1;i<=n;i++) dp[i][1]=dp[i][0]+a[i];
		for(int i=2;i<=n;i++) dp[i][1]=max(dp[i][1],dp[i-1][1]);
		for(int i=1;i<=n;i++) dp[i][2]=dp[i][1]-a[i];
		for(int i=2;i<=n;i++) dp[i][2]=max(dp[i][2],dp[i-1][2]);
		for(int i=1;i<=n;i++) dp[i][3]=a[i]+dp[i][2];
		for(int i=1;i<=n;i++) ans=max(ans,dp[i][3]);
		cout<<ans<<endl;
	}
	return 0;
}
