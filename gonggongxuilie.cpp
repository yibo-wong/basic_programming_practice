#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char x[210],y[210];
int xlen,ylen;
int dp[210][210];
int main()
{
	while(scanf("%s",&x)!=EOF)
	{
		scanf("%s",&y);
		xlen=strlen(x);
		ylen=strlen(y);
		if(x[0]==y[0]) dp[0][0]=1;
		else dp[0][0]=0;
		for(int i=1;i<ylen;i++)
		{
			if(y[i]==x[0]) dp[0][i]=1;
			else dp[0][i]=dp[0][i-1];
		}
		for(int i=1;i<xlen;i++)
		{
			if(x[i]==y[0]) dp[i][0]=1;
			else dp[i][0]=dp[i-1][0];
		}
		for(int i=1;i<xlen;i++)
		{
			for(int j=1;j<ylen;j++)
			{
				if( x[i]==y[j] ) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			}
		}
		cout<<dp[xlen-1][ylen-1]<<endl;
	}
}
