#include <iostream>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;
int testnum;
int dp[1050][1050];
int len;
string s;
int main()
{
	cin>>testnum;
	while(testnum--)
	{
		cin>>s;
		memset(dp,0,sizeof(dp));
		len=s.size();
		for(int i=0;i<=len-2;i++)
		{
			if(s[i]==s[i+1]) dp[i][i+1]=0;
			else dp[i][i+1]=1;
		}
		for(int i=2;i<=len-1;i++)
		{
			for(int j=0;j<len-i;j++)
			{
				if(dp[j+1][j+i-1]==0 && s[j]==s[j+i]) dp[j][j+i]=0;
				else
				{
					int minx=inf;
					for(int k=0;k<i;k++)
					{
						minx=min(minx,1+dp[j][j+k]+dp[j+k+1][j+i]);
					}
					dp[j][j+i]=minx;
				}
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}
