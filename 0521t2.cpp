#include <iostream>
#include <cstring>
using namespace std;
long long int dp[35][10];
void make()
{
	memset(dp,0,sizeof(dp));
	dp[1][3]=dp[1][6]=dp[1][0]=1;
	for(int i=2;i<=32;i++)
	{
		dp[i][0]=dp[i-1][7];
		dp[i][1]=dp[i-1][6];
		dp[i][2]=dp[i-1][5];
		dp[i][3]=dp[i-1][7]+dp[i-1][4];
		dp[i][4]=dp[i-1][3];
		dp[i][5]=dp[i-1][2];
		dp[i][6]=dp[i-1][7]+dp[i-1][1];
		dp[i][7]=dp[i-1][0]+dp[i-1][6]+dp[i-1][3];
	}
}
int main()
{
	int x;
	make();
	while(cin>>x)
	{
		if(x==-1) return 0;
		if(x==0) cout<<"1"<<endl;
		else cout<<dp[x][7]<<endl;
	}
}
