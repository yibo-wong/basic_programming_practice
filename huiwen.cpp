#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1050],cases;
char a[1050];
bool judge(int x,int y)
{
	bool flag=1;
	for(int i=x-1;i<=y-1;i++)
	{
		if(a[i]!=a[x+y-i-2])
		{
			flag=0;break;
		}
	}
	return flag;
}
int main()
{
	cin>>cases;
	while(cases--)
	{
		memset(dp,10000,sizeof(dp));
		memset(a,0,sizeof(a));
		cin>>a;
		int len=strlen(a);
		//cout<<len<<endl;
		if(judge(1,len))
		{
			cout<<0<<endl;continue;
		}
		dp[0]=0;dp[1]=0;
		for(int i=2;i<=len;i++)
		{
			if(judge(1,i))
			{
				dp[i]=0;continue;
			}
			for(int j=2;j<=i;j++)
			{
				if(judge(j,i)) dp[i]=min(dp[j-1]+1,dp[i]);
			}
		}
		//for(int i=1;i<=len;i++) cout<<dp[i]<<" ";
		//cout<<endl;
		cout<<dp[len]<<endl;
	}
}
