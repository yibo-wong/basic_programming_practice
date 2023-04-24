#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 1000000
using namespace std;
int dp[20][20];
int maze[20][20],n,temp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>maze[i][j];
	dp[1][1]=inf;
	for(int i=2;i<=n;i++) dp[i][1]=maze[1][i];
	for(int i=2;i<=n-2;i++)
	{
		for(int j=2;j<=n-1;j++)
		{
			temp=inf;
			for(int k=1;k<=n-1;k++)
			{
				if(k!=j) temp=min(temp,dp[k][i-1]+maze[k][j]);
			}
			dp[j][i]=temp;
		}
	}
	temp=inf;
	for(int i=2;i<=n;i++)
	{
		temp=min(temp,dp[i][n-2]+maze[i][n]);
	}
	cout<<temp<<endl;
	return 0;
}
