#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll int n,m,dp[5050];
bool flag[5050][5050];
int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		dp[b]=max(dp[b],dp[a]+1);
	}
	return 0;
}
