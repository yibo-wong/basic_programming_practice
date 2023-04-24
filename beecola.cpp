#include <iostream>
#include <algorithm>
using namespace std;
int x[100050];
int n;
int m;
int q;
int dp[100050];
int p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	p=1;
	for(int i=1;i<=x[n];i++)
	{
		if(i<x[p]) dp[i]=dp[i-1];
		else 
		{
			dp[i]=dp[i-1];
			do
			{
				p++;
				dp[i]++;
			}while(i==x[p]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>m;
		if(m>=x[n]) cout<<"ttt"<<dp[x[n]]<<endl;
		else cout<<"ttt"<<dp[m]<<endl;
	}
	return 0;
}
