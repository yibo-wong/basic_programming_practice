#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int n,kk;
ll int a[50][50];
ll int dp[50][50];
char num[50];
ll int temp;
int main()
{
	cin>>n>>kk;
	cin>>num;
	for(int i=0;i<strlen(num);i++) a[i+1][i+1]=num[i]-'0';
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			a[i][j]=a[i][j-1]*10+a[j][j];
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	dp[2][1]=a[1][1]*a[2][2];
	for(int i=2;i<=n;i++)
	{
		temp=0;
		for(int j=1;j<i;j++)
		{
			if(a[1][j]*a[j+1][i]>temp) temp=a[1][j]*a[j+1][i];
		}
		dp[i][1]=temp;
	}
	//for(int i=1;i<=n;i++) cout<<dp[i][1]<<" ";
	//cout<<endl<<endl;
	for(int j=2;j<=kk;j++)
	{
		for(int i=1;i<=n;i++)
		{
			temp=0;
			if(i<=j)
			{
				dp[i][j]=0;
				continue;
			}
			for(int k=1;k<i;k++)
			{
				if(dp[k][j-1]*a[k+1][i]>temp) temp=dp[k][j-1]*a[k+1][i];
			}
			dp[i][j]=temp;
		}
	}
	/*for(int j=1;j<=kk;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	cout<<dp[n][kk]<<endl;
	return 0;
}
