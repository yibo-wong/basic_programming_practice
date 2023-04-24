#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[150][150];
int dp[150][150];
int temp;
int m,n;
int cnt=0;
bool s[150][150];
bool flag;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int main()
{
	memset(s,0,sizeof(s));
	memset(dp,0,sizeof(dp));
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	do
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i][j]==0)
				{
					flag=true;temp=0;
				for(int k=0;k<4;k++)
				{
					if(i+dx[k]<1||i+dx[k]>m||j+dy[k]<1||j+dy[k]>n) continue;
					if(s[i+dx[k]][j+dy[k]]==0&&a[i+dx[k]][j+dy[k]]>a[i][j]) 
					{
						flag=false;break;
					}
				}
				if(flag)
				{
					temp=0;
					for(int k=0;k<4;k++)
					{
						if(i+dx[k]<1||i+dx[k]>m||j+dy[k]<1||j+dy[k]>n) continue;
						if(a[i+dx[k]][j+dy[k]]>a[i][j]) temp=max(temp,dp[i+dx[k]][j+dy[k]]);
					}	
					dp[i][j]=temp+1;s[i][j]=1;
					//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
					cnt++;
				}
				}
			}
		}
	}while(cnt<m*n);
	temp=0;
	/*
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j]>temp) temp=dp[i][j];
		}
	}
	cout<<temp;
	return 0;
}
