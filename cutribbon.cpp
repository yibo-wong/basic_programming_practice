#include <iostream>
#include <algorithm>
using namespace std;
int dp[5000];
int n,a,b,c;
int t[5];
int maxn;
int main()
{
	cin>>n>>a>>b>>c;
	dp[a]=1;
	dp[b]=1;
	dp[c]=1;
	for(int i=1;i<=n;i++)
	{
		t[1]= i-a>0 ? dp[i-a] : -1;
		t[2]= i-b>0 ? dp[i-b] : -1;
		t[3]= i-c>0 ? dp[i-c] : -1;
		maxn=max(max(t[1],t[2]),t[3]);
		if(maxn>0) dp[i]=maxn+1;
		cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}
