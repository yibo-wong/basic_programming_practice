#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long int n,a[30];
long long int dp[30];
int main()
{
	cin>>n;
	for(long long int i=1;i<=n;i++) cin>>a[i];
	dp[1]=a[1];
	dp[2]=max(a[1],a[2]);
	for(int i=3;i<=n;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}
