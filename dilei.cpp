#include <iostream>
#include <algorithm>
using namespace std;
int dp[25],a[25];
int n,pre[25];
bool maze[25][25];

void print(int i)
{
	if(pre[i]==0)
	{
		cout<<i<<" ";
		return;
	}
	print(pre[i]);
	cout<<i<<" ";
	return;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>maze[i][j];
			//maze[j][i]=maze[i][j];
		}
	}
	for(int i=1;i<=n;i++) dp[i]=a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(maze[i][j])
			{
				if(a[j]+dp[i]>dp[j])
				{
					dp[j]=dp[i]+a[j];
					pre[j]=i;
				}
			}
		}
	}
	int tmp=0,p=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]>tmp)
		{
			tmp=dp[i];
			p=i;
		}
	}
	print(p);
	cout<<endl;
	cout<<dp[p];
	return 0;
}
