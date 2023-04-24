#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int dp[1050][1050];
int a[1050];
int main()
{
	int testnum;
	cin>>testnum;
	while(testnum--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[1]==1) dp[1][0]=1;
		else dp[1][0]=0;
		for(int i=2;i<=n;i++)
		{
			//dp[i][i]=0;
			for(int j=0;j<i;j++)
			{
				int t=0;
				t=max(t,dp[i-1][j-1]);
				if(a[i] == i-j)
				{
					t=max(t,dp[i-1][j]+1);
				}
				else
				{
					t=max(t,dp[i-1][j]);
				}
				dp[i][j]=t;
			}
		}
		int s=0;
		for(int i=0;i<n;i++) s=max(s,dp[n][i]);
		cout<<s<<endl;
	}
	return 0;
}
