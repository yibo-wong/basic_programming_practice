#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string a,b;
int dp[1000][1000];
int main()
{
	a.resize(10000);
	b.resize(10000);
	while((scanf("%s",&a[0])!=EOF))
	{
		scanf("%s",&b[0]);
		memset(dp,0,sizeof(dp));
		if(a[0]==b[0])
		{
			for(int i=0;i<a.size();i++) dp[i][0]=1;
			for(int i=0;i<b.size();i++) dp[0][i]=1;
		}
		for(int i=1;i<a.size();i++)
		{
			for(int j=1;j<b.size();j++)
			{
				if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.size()-1][b.size()-1]<<endl;
	}
	return 0;
}
