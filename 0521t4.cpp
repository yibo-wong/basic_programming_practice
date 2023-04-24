#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int dp[1050][1050];
string a,b;
int main()
{
	int n;cin>>n;
	while(n--)
	{
		cin>>a>>b;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=a.size();i++) dp[i][0]=i;
		for(int i=1;i<=b.size();i++) dp[0][i]=i;
		for(int i=1;i<=a.size();i++)
		{
			for(int j=1;j<=b.size();j++)
			{
				if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;	
	}
	return 0;
}
