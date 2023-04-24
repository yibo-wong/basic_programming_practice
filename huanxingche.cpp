#include <iostream>
#include <algorithm>
using namespace std;
int a[550];
int w[550];
int dp[550];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>w[i];
	dp[1]=w[1];
	int temp;
	for(int i=2;i<=m;i++)
	{
		temp=w[i];
		for(int j=1;j<i;j++)
		{
			if(a[j]<=a[i]) temp=max(temp,dp[j]+w[i]);
			//cout<<temp<<" "<<j<<endl;
		}
		dp[i]=temp;
	}
	temp=0;
	for(int i=1;i<=m;i++)
	{
		temp=max(temp,dp[i]);
	}
	cout<<temp;
	return 0;
}
