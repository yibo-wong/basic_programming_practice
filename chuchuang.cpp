#include <iostream>
#include <cstring>
using namespace std;
int f,v;
int a[110][110];
int dp[110][110];
int pos[110][110][110];
int main()
{
	cin>>f>>v;
	for(int i=1;i<=f;i++)
	{
		for(int j=1;j<=v;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=f;i++)
	{
		dp[i][i]=dp[i-1][i-1]+a[i][i];
	}
	for(int i=1;i<=f;i++)
	{
		for(int j=1;j<=i;j++)
		{
			pos[j][i][i]=j;
		}
	}
	for(int i=1;i<=f;i++)
	{
		for(int j=i+1;j<=v;j++)
		{
			//dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
			if(dp[i][j-1]>dp[i-1][j-1]+a[i][j])
			{
				dp[i][j]=dp[i][j-1];
				for(int k=1;k<=f;k++) pos[k][i][j]=pos[k][i][j-1];
			}
			else
			{
				dp[i][j]=dp[i-1][j-1]+a[i][j];
				for(int k=1;k<=f;k++) pos[k][i][j]=pos[k][i-1][j-1];
				pos[i][i][j]=j;
			}
		}
	}
	cout<<dp[f][v]<<endl;
	for(int i=1;i<=f;i++) cout<<pos[i][f][v]<<" ";
	return 0;
}
