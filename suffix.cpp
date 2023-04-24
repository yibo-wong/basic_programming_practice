#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int a[100500];
int b;
bool t[100500];
int dp[100500];
int sum;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[n]=1;
	t[a[n]]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(t[a[i]]==0) dp[i]=dp[i+1]+1;
		else dp[i]=dp[i+1];
		t[a[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		cout<<"ttt"<<dp[b]<<endl;
	}
	return 0;
}
